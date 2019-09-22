////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include<type_traits>

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



int main(int argc, char const* argv[])
{
   using namespace Utils;
   /*********************/
   std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
   auto& element = getMiddle(v.begin(), v.end());
   element = 10;
   auto element1 = getMiddleNoRef(v.begin(), v.end());

   print(element);
   print(element1);
   element1 = 42;
   auto element2 = getMiddleNoRef(v.begin(), v.end());
   print(element2);
  
}