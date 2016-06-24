#include "song.h"

bool Song::verifyLink(std::string sUrl) {
	std::string	sId;
	std::regex id_regex("http:\\/\\/mp3.zing.vn\\/bai-hat\\/[\\w-]+\\/ZW\\w{6}.html");
	std::smatch id_match;
	if (std::regex_match(sUrl, id_match, id_regex)) {
		return true;
	}
	return false;
}

bool Song::getLink(std::string sUrl)
{
	dkstd::curl	req;
	std::string sContent;

	std::string sId = getId(sUrl);
	if (sId.size() == 0) {
		return false;
	}

	std::string sApiUrl = "http://api.mp3.zing.vn/api/mobile/song/getsonginfo?requestdata={\"id\":\"" + sId + "\"}";

	req.set_url(sApiUrl);
	req.send_request();
	sContent = req.get_content();

	Json::Value		root;
	Json::Reader	reader;
	Json::Value		links;
	Json::Value		link;
	bool			bParsingSuccessul = false;

	bParsingSuccessul = reader.parse(sContent, root);
	if (bParsingSuccessul == false) {
		return false;
	}

	m_sName = root["title"].asString();
	m_sArtist = root["artist"].asString();

	links = root["source"];

	req = dkstd::curl();
	req.set_url(links["128"].asString());
	req.send_request();
	m_sUrl128 = req.get_redirect();

	req = dkstd::curl();
	req.set_url(links["320"].asString());
	req.send_request();
	m_sUrl320 = req.get_redirect();

	req = dkstd::curl();
	req.set_url(links["lossless"].asString());
	req.send_request();
	m_sUrlLossless = req.get_redirect();

	return true;
}

std::string Song::getName() {
	return m_sName;
}

std::string Song::getArtist() {
	return m_sArtist;
}

bool Song::isHas128() {
	if (m_sUrl128.size() > 0) {
		return true;
	}
	return false;
}

std::string Song::get128() {
	return m_sUrl128;
}

void Song::download128(std::string sFilePath)
{
	download(m_sUrl128, sFilePath);
}

bool Song::isHas320() {
	if (m_sUrl320.size() > 0) {
		return true;
	}
	return false;
}

void Song::download320(std::string sFilePath)
{
	download(m_sUrl320, sFilePath);
}

bool Song::isHasLossless() {
	if (m_sUrlLossless.size() > 0) {
		return true;
	}
	return false;
}

void Song::downloadLossless(std::string sFilePath)
{
	download(m_sUrlLossless, sFilePath);
}

std::string Song::getId(std::string sUrl)
{
	std::string	sId;
	std::regex id_regex("ZW\\w{6}");
	std::smatch id_match;
	if (std::regex_search(sUrl, id_match, id_regex)) {
		sId = id_match[0];
	}
	return sId;
}

void Song::download(std::string sLink, std::string sFile)
{
	dkstd::curl	req;
	if (sLink.size() > 0) {
		req.set_url(sLink);
		req.download_to_file(sFile);

		std::string sNewUrl = req.get_redirect();
		if (sNewUrl.size() > 0) {
			req = dkstd::curl();
			req.set_url(sNewUrl);
			req.download_to_file(sFile);
		}
	}
}