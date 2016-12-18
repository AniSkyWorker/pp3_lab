#pragma once
#include "IPipe.h"
#include <codecvt>

namespace
{

std::string WstringToString(const std::wstring & text)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.to_bytes(text);
}

}

class CPipe : public IPipe
{
public:
	void Read(void* buffer, size_t size) override;
	void Write(const void* buffer, size_t size) override;
	void Open(const std::wstring& name) override;
	void Close() override;


protected:
	std::wstring m_name;
	HANDLE m_hPipe;
};