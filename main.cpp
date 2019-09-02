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
//     ~X() = delete;
// };
    
int main(int argc, char const* argv[])
{
    std::vector<HasPtr> v 
    {
        HasPtr("eggs", 13),
        HasPtr("$$!", 42),
        HasPtr("$$*!", 14),
        HasPtr(")!(@*&#", 51),
        HasPtr("!@##", 123123),
        HasPtr("!@!#^", 3)
    };
    
    std::sort(v.begin(), v.end());

    return 0;
}