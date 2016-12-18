#pragma once

struct ProcessData
{
	ProcessData(STARTUPINFOA startupInfo, PROCESS_INFORMATION processInfo, HANDLE handle);
	STARTUPINFOA startupInfo;
	PROCESS_INFORMATION processInfo;
	HANDLE handle;
};