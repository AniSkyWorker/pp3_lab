#include "stdafx.h"
#include "MessageAgregator.h"

void CMessageAgregator::SendMessage(std::string const & message, const std::wstring & pipeName)
{
	auto pipePath = L"\\\\.\\Pipe\\" + pipeName;
	CPipe pipe;
	pipe.Open(pipePath);
	pipe.Write(message.data(), message.size());
	pipe.Close();
}

void CMessageAgregator::WaitMessages(std::vector<std::string>& messages, size_t amountMessages, const std::wstring & pipeName)
{
	auto pipePath = L"\\\\.\\Pipe\\" + pipeName;
	CNamedPipe pipe;
	pipe.Open(pipePath);
	for (size_t index = 0; index < amountMessages; ++index)
	{
		char buffer[BUFFER_PIPE_SIZE] = "";
		pipe.Read(buffer, BUFFER_PIPE_SIZE);
		messages.push_back(buffer);
	}
	pipe.Close();
}