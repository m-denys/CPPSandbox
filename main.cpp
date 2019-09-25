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

/********************/

int main(int argc, char const* argv[])
{
    using namespace Utils;
   /*********************/
 
    std::bitset<128> mask(1);
    mask.set(10, true);
    print(mask);
}