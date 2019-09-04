////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

////////////////////
#include "debug.h"

////////////////////
#include "utils.h"

////////////////////
#include "HasPtr.h"
#include "Employee.h"

/****Test-Section****/

// class X
// {
// public:
//     X() { Utils::print("this is X()"); }
//     X(X const& rhs) { Utils::print("this is X(X const& rhs)"); }
//     X& operator=(X const& rhs) { Utils::print("this is operator=(X const& rhs)"); return *this; }
//     //~X() { Utils::print("this is ~X()"); }
//     ~X() = delete;HasPtr(std::string const& s, int const i)
// };

int&& boo(int i)
{
	return std::move(i);
}

/*int const& foo(int i)
{
	return i;
}*/

int main(int argc, char const* argv[])
{

	std::vector<HasPtr> v;
	HasPtr hp;
	v.push_back(hp);

	auto hp1 = hp;

    return 0;
}