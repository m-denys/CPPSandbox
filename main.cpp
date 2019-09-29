////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <type_traits>
#include <sstream>
#include <tuple>
#include <utility>
#include <numeric>
#include <bitset>
#include <exception>


////////////////////
#include "debug.h"

////////////////////
#include "utils.h"

////////////////////
#include "HasPtr.h"
#include "Employee.h"
#include "vector_wrapper.h"
#include "DataHandle.h"
#include "Functor.h"
#include "templates.h"
#include "multiple_inheritance.h"

///////////////////
#include "Shape.h"

//////////////////
#include "Blob.h"

/****Test-Section****/

class MyClass
{
public:
    explicit MyClass(int const i)
    : i_(i)
    {
    }

private:
    int i_;
};


void unsafeFunc()
{
    std::vector<char> v;
    // Access to empty vector
    if (v.empty())
    {
        throw std::out_of_range("Exception: out of range in unsafeFunc");
    }
}


/********************/

int main(int argc, char const* argv[])
{
    using namespace Utils;

    mi::A* ptr = new mi::C();
    ptr->info();

    mi::CC cc;
    print(cc.getI());
    print(cc.getF());
    
}