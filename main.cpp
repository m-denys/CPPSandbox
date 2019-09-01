////////////////////
#include <iostream>
#include <vector>
#include <string>

////////////////////
#include "utils.h"

////////////////////
#include "HasPtr.h"

/****Test-Section****/

class Test
{
public:
	Test()
	: _i(42)
	, _f(3.14159)
	{
	}

	~Test()
	{
	}

	int _i;
	float _f;
};

/********************/


int main(int argc, char const* argv[])
{

	Test t;
	std::cout << t._i << "\n";
	std::cout << t._f << "\n";

/*	HasPtr none();
	HasPtr ptr1("hello");
	HasPtr ptr2(ptr1);
	HasPtr ptr3("junk");

	ptr1 = ptr3;

	std::cout << (ptr1 == ptr3 ? "y" : "n") << std::endl;*/

	return 0;
}