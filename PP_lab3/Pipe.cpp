#include "stdafx.h"
#include "Pipe.h"

void CPipe::Read(void * buffer, size_t size)
{
	DWORD dwRead;
	BOOL bSuccess = ReadFile(m_hPipe, buffer, DWORD(size), &dwRead, NULL);
	if (!bSuccess || (dwRead == 0))
	{
		throw std::runtime_error("Read error");
	}
}

void CPipe::Write(const void * buffer, size_t size)
{
	DWORD dwWritten;
	if (!WriteFile(m_hPipe, buffer, DWORD(size), &dwWritten, NULL))
	{
		throw std::runtime_error("Write error");
	}
}

void CPipe::Open(const std::wstring& name)
{
	m_name = name;
	m_hPipe = CreateFile(LPCWSTR(name.c_str()), GENERIC_ALL, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_hPipe == INVALID_HANDLE_VALUE)
	{
		throw std::runtime_error("Error for open pipe " + WstringToString(m_name));
	}
}

void CPipe::Close()
{
	CloseHandle(m_hPipe);
	m_hPipe = nullptr;
}