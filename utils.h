#pragma once

#define PRINT_CONTAINER(expr) for (auto item : (expr)) std::cout << item << ", "; std::cout <<"\n";

namespace Utils 
{
	template<typename T>
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
	}
} // Utils
