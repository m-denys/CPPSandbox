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

/*class Default
{
public:
	Default() = default;
	Default(Default const& other) = default;
	Default& operator=(Default const& other) = default;
	Default(Default&& other) = default;
	Default& operator=(Default&& other) = default;
	~Default() = default;

private:
	std::string str_;
};*/


struct Boo
{
public:
	Boo(int i)
	: i_(i)
	{
	}

/*	void info()
	{
		std::cout <<  i_ << std::endl;
	}*/

	void info() &
	{
		std::cout << "'&'" <<  i_ << std::endl;
	}

	void info() &&
	{
		std::cout << "'&&'" << i_ << std::endl;
	}

	Boo& operator=(Boo const& other)
	{
		i_ = other.i_;
		return *this;
	}

	Boo operator+(Boo const& other)
	{
		i_ += other.i_;
		return *this;
	}

private:
	int i_;
};

int main(int argc, char const* argv[])
{
	Boo b(10);
	Boo b1(41);

	(b + b1).info();
	b.info();
	(b + b1 = 31).info();
	b.info();




}