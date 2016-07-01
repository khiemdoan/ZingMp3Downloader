
// author: Khiêm Đoàn Hoà - 2016-03-19

#ifndef _DK_STRING_H_
#define _DK_STRING_H_

#include <string>
#include <codecvt>

namespace dkstd {

	// convert std::string to std::wstring
	std::wstring s2ws(std::string str);
	// convert std::wstring to std::string
	std::string ws2s(std::wstring wstr);

	inline std::wstring s2ws(std::string str)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;
		return converterX.from_bytes(str);
	}
	
	inline std::string ws2s(std::wstring wstr)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;
		return converterX.to_bytes(wstr);
	}

}

#endif // !_DK_STRING_H_