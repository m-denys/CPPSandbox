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
    
int main(int argc, char const* argv[])
{
/*    std::vector<HasPtr> v 
    {
        HasPtr("eggs", 13),
        HasPtr("$$!", 42),
        HasPtr("$$*!", 14),
        HasPtr(")!(@*&#", 51),
        HasPtr("!@##", 123123),
        HasPtr("!@!#^", 3)
    };*/
    //std::sort(v.begin(), v.end());
    
  /*  HasPtr const hp;
    //HasPtr hp1(Utils::move(hp)));
    HasPtr hp1(Utils::move(hp));*/

    std::vector<int> v1{1, 2, 3, 4};
    std::vector<int> v2{11, 22, 33, 44};

    /*Utils::print(v1);
    Utils::print(v2);


    v1 = Utils::move(v2);

    Utils::print(v1);
    Utils::print(v2);*/

    HasPtr hp1("!#!@", 42);
    {
    	HasPtr hp2("^*&%#)", 13);	
    	hp1 = Utils::move(hp2);
    }
    
    return 0;
}