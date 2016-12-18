#pragma once

class IPipe
{
public:
	virtual ~IPipe() = default;
	virtual void Read(void* buffer, size_t size) = 0;
	virtual void Write(const void* buffer, size_t size) = 0;
	virtual void Open(const std::wstring& name) = 0;
	virtual void Close() = 0;
};