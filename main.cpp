////////////////////
#include <iostream>
#include <vector>
#include <string>

////////////////////
#include "utils.h"

////////////////////
#include "HasPtr.h"
#include "Employee.h"

/****Test-Section****/

class X
{
public:
	X() { Utils::print("this is X()"); }
	X(X const& rhs) { Utils::print("this is X(X const& rhs)"); }
	X& operator=(X const& rhs) { Utils::print("this is operator=(X const& rhs)"); return *this; }
	//~X() { Utils::print("this is ~X()"); }
	~X() = delete;
};

class Singletone
{
public:
	static Singletone& instance()
	{
		static Singletone inst;
		return inst;
	}

protected:
	Singletone(){}
	~Singletone(){}
};


/********************/

int main(int argc, char const* argv[])
{
	Employee emp1("Denys");
	Employee emp2 = emp1;

	Utils::print(emp1.getId());
	Utils::print(emp1.getName());
	Utils::print(emp2.getId());
	Utils::print(emp2.getName());

	return 0;
}