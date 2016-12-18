#include "stdafx.h"
#include "ProcessData.h"

ProcessData::ProcessData(STARTUPINFOA startupInfo, PROCESS_INFORMATION processInfo, HANDLE handle)
	: startupInfo(startupInfo)
	, processInfo(processInfo)
	, handle(handle)
{}