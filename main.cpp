////////////////////
#include <iostream>
#include <vector>
#include <string>

////////////////////
#include "utils.h"

////////////////////
#include "HasPtr.h"

/****Test-Section****/

class X
{
public:
	X() { Utils::print("this is X()"); }
	X(X const& rhs) { Utils::print("this is X(X const& rhs)"); }
	X& operator=(X const& rhs) { Utils::print("this is operator=(X const& rhs)"); return *this; }
	~X() { Utils::print("this is ~X()"); }
};

/********************/


int main(int argc, char const* argv[])
{
	//X x;
	std::vector<X> v;

	//v.push_back(x);
	v.emplace_back();

	return 0;
}