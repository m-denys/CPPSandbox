#pragma once

template<typename T>
class VectorWrapper
{
public:
	VectorWrapper() = default;
	VectorWrapper(std::vector<T> const& vec)
	: vec_(vec) 
	{
	}
	VectorWrapper(std::initializer_list<T> const& il)
	: vec_(il)
	{
	}

	T const& operator[](std::size_t const index) const { return vec_[index]; }
	T& operator[](std::size_t const index) { return vec_[index]; }

private:
	std::vector<T> vec_;
};