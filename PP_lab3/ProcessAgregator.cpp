#include "stdafx.h"
#include "ProcessAgregator.h"
#include "PiMonteCarloCalculator.h"
#include "ProcessData.h"
#include <chrono>
#include <sstream>

std::vector<std::string> CProcessAgregator::GetProcessesMessages()const
{
	return m_messages;
}

void CProcessAgregator::CreateSubprocesses(int processesCount, int iterationsCount)
{
	std::vector<ProcessData> processesData;

	for (int i = 0; i < processesCount; ++i)
	{
		STARTUPINFOA si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(si));
		ZeroMemory(&pi, sizeof(pi));
		std::string appArguments =  "PP_lab3.exe 0 " + std::to_string(iterationsCount);
		si.dwFlags = STARTF_USESIZE | STARTF_USESHOWWINDOW;
		si.wShowWindow = SW_SHOW;

		if (!CreateProcessA(NULL, _strdup(appArguments.c_str()), NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
		{
			throw std::runtime_error("Error while creating subprocess.");
		}

		processesData.emplace_back(si, pi, pi.hThread);
	}

	CMessageAgregator::WaitMessages(m_messages, processesCount, L"pipe");

	for (size_t i = 0; i != processesCount; i++)
	{
		CloseHandle(processesData[i].processInfo.hProcess);
		CloseHandle(processesData[i].processInfo.hThread);
	}
}

void CProcessAgregator::SubprocessCalculation(int iterationsCount)
{
	auto startTime = std::chrono::steady_clock::now();
	double result = CPiMonteCarloCalculator::CalculatePi(iterationsCount);
	auto endTime = std::chrono::steady_clock::now();

	std::stringstream resultStrm;
	resultStrm << "Result: " << result
		<< ", spent time: " << (endTime - startTime).count();

	CMessageAgregator::SendMessage(resultStrm.str(), L"pipe");
}