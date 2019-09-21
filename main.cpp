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

//////////////////
#include "Blob.h"

/****Test-Section****/

/********************/

int main(int argc, char const* argv[])
{
   using namespace Utils;
   /*********************/

   Blob<int> blob = new std::vector<int>(10);
   Blob<int> blob1;

   print(blob.size());
   print(blob1.size());
}