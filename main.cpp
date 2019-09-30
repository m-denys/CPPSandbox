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
#include <cassert>
#include <random>
#include <stdexcept>

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

///////////////////
#include "Shape.h"

//////////////////
#include "Blob.h"

/////////////////
#include "chap17.h"

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

unsigned getRandom()
{
   static std::default_random_engine e;
   return e();
}

int getValue(std::vector<int> const& v, size_t index)
{
    if (index >= v.size())
    {
        throw std::out_of_range("index in getValue is out of range");
    }

    return v[index];
}

/********************/

int main(int argc, char const* argv[])
{
    using namespace Utils;
   /*********************/

    std::vector<int> v{ 1, 2, 3, 4 };

    try
    {
        print(getValue(v, 10));
    }
    catch(std::out_of_range const& e)
    {
        print(e.what());
        print("error is catch");
    }

    return 0;
}