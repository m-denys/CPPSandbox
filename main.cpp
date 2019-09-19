////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

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

/****Test-Section****/

/********************/

int main(int argc, char const* argv[])
{
   using namespace Utils;
   /*********************/

   std::vector<int> v{ 1, 2, 3, 4 };
   auto iter = Templates::find(v.begin(), v.end(), 3);

   print(*iter);
}