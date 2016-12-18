#pragma once
#include "NamedPipe.h"

class CMessageAgregator
{
public:
	static void SendMessage(std::string const &message, const std::wstring & pipeName);
	static void WaitMessages(std::vector<std::string> &messages, size_t amountMessages, const std::wstring & pipeName);
};