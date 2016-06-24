#ifndef _SONG_H_
#define _SONG_H_

#include "string"
#include "regex"
#include "dkstd_curl.h"
#include "jsoncpp/json.h"

class Song
{
public:
	bool verifyLink(std::string sUrl);
	bool getLink(std::string sUrl);

	std::string getName();
	std::string getArtist();
	
	bool isHas128();
	std::string get128();
	void download128(std::string sFilePath);

	bool isHas320();
	void download320(std::string sFilePath);

	bool isHasLossless();
	void downloadLossless(std::string sFilePath);

private:
	std::string m_sName;
	std::string m_sArtist;

	std::string	m_sUrl128;
	std::string	m_sUrl320;
	std::string	m_sUrlLossless;

	std::string getId(std::string sUrl);
	void download(std::string sLink, std::string sFile);
};

#endif // !_SONG_H_