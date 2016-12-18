#pragma once
#include "MessageAgregator.h"

class CProcessAgregator
{
public:
	std::vector<std::string> GetProcessesMessages()const;
	void CreateSubprocesses(int processesCount, int iterationsCount);
	void SubprocessCalculation(int iterationsCount);

private:
	std::vector<std::string> m_messages;
};