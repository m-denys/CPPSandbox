#pragma once

template<typename T>
class DataHandle
{
public:
	DataHandle()
	: data_(nullptr)
	{
	}

	DataHandle(T data)
	: data_(new T(data))
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

	T& operator*() const
	{
		return *data_;
	}

	T* operator->() const
	{
		return &(*this);
	}

private:
	T* data_;
};