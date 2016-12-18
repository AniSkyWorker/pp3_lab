#include "stdafx.h"
#include "NamedPipe.h"

void CNamedPipe::Read(void * buffer, size_t size)
{
	if (ConnectNamedPipe(m_hPipe, NULL))
	{
		DWORD dwRead;
		if (!ReadFile(m_hPipe, buffer, DWORD(size), &dwRead, NULL) || (dwRead == NULL))
		{
			throw std::runtime_error("Read pipe error.");
		}
	}
	DisconnectNamedPipe(m_hPipe);
}

void CNamedPipe::Write(const void * buffer, size_t size)
{
	if (ConnectNamedPipe(m_hPipe, NULL))
	{
		DWORD dwWritten;
		if (!WriteFile(m_hPipe, buffer, DWORD(size), &dwWritten, NULL))
		{
			throw std::runtime_error("Write pipe error.");
		}
	}
	DisconnectNamedPipe(m_hPipe);
}

void CNamedPipe::Open(const std::wstring& name)
{
	m_name = name;
	m_hPipe = CreateNamedPipe(
		(LPWSTR)m_name.data(),
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		BUFFER_PIPE_SIZE,
		BUFFER_PIPE_SIZE,
		NULL,
		NULL
	);
	if (m_hPipe == INVALID_HANDLE_VALUE)
	{
		throw std::runtime_error("Error for open pipe " + WstringToString(m_name));
	}
}

void CNamedPipe::Close()
{
	DisconnectNamedPipe(m_hPipe);
	CloseHandle(m_hPipe);
	m_hPipe = nullptr;
}