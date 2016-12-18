// PP_lab3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ProcessAgregator.h"

int main(int argc, char*argv[])
{
	if (argc == 2 && argv[1] == "/\?")
	{
		std::cout << "\t\tHelp:\n"
			<< "PP_lab3.exe <processes count> <iterations count>\n"
			<< "PP_lab3.exe /? - to print help\n";
		return 1;
	}
	else if(argc == 3)
	{
		try
		{
			CProcessAgregator executer;
			int processCount = atoi(argv[1]);
			int iterations = atoi(argv[2]);
			if (processCount != 0)
			{
				executer.CreateSubprocesses(processCount, iterations);
				for (auto const & message : executer.GetProcessesMessages())
				{
					std::cout << message.c_str() << "\n";
				}
			}
			else
			{
				executer.SubprocessCalculation(iterations);
			}
		}
		catch (std::exception const &exc)
		{
			std::cerr << exc.what() << "\n";
		}
	}
	else
	{
		std::cout << "Incorrect arguments: Use \"/?\" to get help." << "\n";
	}
	
	return 0;
}

