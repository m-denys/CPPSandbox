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

// template<typename A, typename B>
// A sum(A const& a, B const& b)
// {
//     return a + b;
// }


template<typename A>
A sum1(A const& a, A const& b)
{
    return a + b;
}
/********************/

bool b()
{
    Utils::print("b");
    return true;
}

bool b1()
{
    Utils::print("b1");
    return true;
}


bool b2()
{
    Utils::print("b2");
    return true;
}

int main(int argc, char const* argv[])
{
   using namespace Utils;
   /*********************/

   //variadic::foo(13, 42, 3.14, 'c', "str");
   //variadic::printArgs(13, 42, 3.14, 'c', "str");

   if (b1() == b() && b2())
   {
       print("...");
   }
   
}