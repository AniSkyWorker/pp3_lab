#pragma once
#include "Pipe.h"

static const size_t BUFFER_PIPE_SIZE = 512;

class CNamedPipe : public CPipe
{
public:
	void Read(void* buffer, size_t size) override;
	void Write(const void* buffer, size_t size) override;
	void Open(const std::wstring& name) override;
	void Close() override;
};