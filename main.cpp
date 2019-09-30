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
#include <exception>
#include <typeinfo>

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

/////////////////
#include "chap17.h"

/****Test-Section****/

class Boo
{
public:
    Boo()
    : content_("eggs")
    {
    }

    static std::string const Boo::* data()
    {
        return &Boo::content_;
    }
    
private:
    std::string content_;
};

/********************/

int main(int argc, char const* argv[])
{
    using namespace Utils;
    
    auto pdata = Boo::data();
    
    Boo b;
    print(b.*pdata);
}