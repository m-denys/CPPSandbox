#pragma once

namespace Utils 
{
/*	template<typename T>
	void print(T const& obj, bool const isContainer = false)
	{
		if (isContainer)
		{
			for (auto const& item : obj)
			{
				std::cout << item << " ";
			}
			std::cout << std::endl;
	    }
	    else
	    {
	    	std::cout << obj << std::endl;
	    }
	}*/

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
} // Utils
