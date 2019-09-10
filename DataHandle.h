#pragma once

template<typename T>
class DataHandle
{
public:
	DataHandle()
	: data_(nullptr)
	{
	}

	DataHandle(T* data)
	: data_(data)
	{
	}

	~DataHandle()
	{
		delete data_;
	}

	bool isValid()
	{
		return data_ != nullptr;
	}

	T& operator*()
	{
		return *data_;
	}

	T* operator->()
	{
		return data_;
	}

private:
	T* data_;
};