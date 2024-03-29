#pragma once

namespace Utils 
{
	template<typename T>
	void print(std::vector<T> const& vec)
	{
		for (auto const& item : vec)
		{
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}

	template<typename T>
	void print(T const& val)
	{
	    std::cout << val << std::endl;
	}

	template<typename T>
	T&& move(T& value)
	{
		return static_cast<T&&>(value);
	}

	// Swap idiom with move semantic
	// If object has a shared resource (pointer)
	// It is better to use object's own swap function
	template<typename T>
	void swap(T& lhs, T& rhs)
	{
		T temp = std::move(lhs);
		lhs = std::move(rhs);
		rhs = std::move(temp);
	}

} // Utils
