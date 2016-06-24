#ifndef _DKSTD_CURL_
#define _DKSTD_CURL_

#include "string"
#include "fstream"
#include "map"

#define CURL_STATICLIB
#include "curl/curl.h"
#pragma comment(lib, "curl/libcurl_a.lib")

namespace dkstd
{
	class curl
	{
	public:
		curl();
		~curl();

		void add_header(std::string name, std::string value);
		void add_data(std::string name, std::string value);
		void set_url(std::string sUrl);
		bool send_request();
		std::string get_content();
		bool download_to_file(std::string file_path);
		std::string get_redirect();

	private:
		std::map<std::string, std::string>	m_mapHeaders;
		std::map<std::string, std::string>	m_mapData;
		std::string			m_sUrl;
		std::string			m_sContent;
		std::string			m_sLocation;

		static size_t write_data(char *contents, size_t size, size_t nmemb, std::string *stream);
		static size_t write_file(char *contents, size_t size, size_t nmemb, std::ofstream *file);
	};
}

inline dkstd::curl::curl()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

inline dkstd::curl::~curl()
{
	curl_global_cleanup();
}

inline void dkstd::curl::add_header(std::string name, std::string value)
{
	m_mapHeaders[name] = value;
}

inline void dkstd::curl::add_data(std::string name, std::string value)
{
	m_mapData[name] = value;
}

inline void dkstd::curl::set_url(std::string sUrl)
{
	m_sUrl = sUrl;
}

inline bool dkstd::curl::send_request()
{
	CURL				*curl_handle = nullptr;
	CURLcode			res = CURLE_OK;
	bool				bReturn = false;
	struct curl_slist	*chunk = NULL;
	std::string			post_field;

	m_sLocation = "";

	curl_handle = curl_easy_init();

	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &m_sContent);

	// header
	for (auto i : m_mapHeaders) {
		std::string s = i.first + ":" + i.second;
		chunk = curl_slist_append(chunk, s.c_str());
	}
	res = curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, chunk);

	// data
	for (auto i : m_mapData) {
		post_field += "&" + i.first + "=" + i.second;
	}
	post_field.erase(0, 1);

	curl_easy_setopt(curl_handle, CURLOPT_URL, m_sUrl.c_str());

	curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, post_field.c_str());
	curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDSIZE, post_field.size());

	res = curl_easy_perform(curl_handle);
	if (res == CURLE_OK) {
		bReturn = true;
	}

	char *location;
	res = curl_easy_getinfo(curl_handle, CURLINFO_REDIRECT_URL, &location);
	if ((res == CURLE_OK) && location) {
		m_sLocation = location;
	}

	curl_easy_cleanup(curl_handle);
	curl_slist_free_all(chunk);

	return bReturn;
}

inline std::string dkstd::curl::get_content()
{
	return m_sContent;
}

inline bool dkstd::curl::download_to_file(std::string file_path)
{
	CURL				*curl_handle = nullptr;
	struct curl_slist	*chunk = NULL;
	CURLcode			res = CURLE_OK;
	bool				bReturn = false;

	m_sContent = file_path;
	std::ofstream file(file_path, std::fstream::out | std::fstream::binary);

	if (file.good() == true) {
		curl_handle = curl_easy_init();

		curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_file);
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &file);

		// header
		for (auto i : m_mapHeaders) {
			std::string s = i.first + ":" + i.second;
			chunk = curl_slist_append(chunk, s.c_str());
		}
		res = curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, chunk);

		curl_easy_setopt(curl_handle, CURLOPT_URL, m_sUrl.c_str());

		res = curl_easy_perform(curl_handle);
		if (res == CURLE_OK) {
			bReturn = true;
		}

		char *location;
		res = curl_easy_getinfo(curl_handle, CURLINFO_REDIRECT_URL, &location);
		if ((res == CURLE_OK) && location) {
			m_sLocation = location;
		}

		curl_easy_cleanup(curl_handle);
		curl_slist_free_all(chunk);
		file.close();
	}

	return bReturn;
}

inline std::string dkstd::curl::get_redirect()
{
	return m_sLocation;
}

inline size_t dkstd::curl::write_data(char * contents, size_t size, size_t nmemb, std::string * stream)
{
	size_t realsize = size * nmemb;
	stream->append(contents, realsize);
	return realsize;
}

inline size_t dkstd::curl::write_file(char * contents, size_t size, size_t nmemb, std::ofstream * file)
{
	size_t realsize = size * nmemb;
	if (file->good() == true) {
		file->write(contents, realsize);
	}
	return realsize;
}

#endif // !_DKSTD_CURL_