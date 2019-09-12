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
#include "vector_wrapper.h"
#include "DataHandle.h"
#include "Functor.h"

///////////////////
#include "Shape.h"

/****Test-Section****/
    
class BaseWithStatic
{
public:
    static int s_i;
};

class DerivedWithStatic : public BaseWithStatic
{

};
/********************/

int BaseWithStatic::s_i = 42;

int main(int argc, char const* argv[])
{
   using namespace Utils;
   ///////////////
   
   print(BaseWithStatic::s_i);
   print(DerivedWithStatic::s_i);

   DerivedWithStatic::s_i = 101;

   print(BaseWithStatic::s_i);
   print(DerivedWithStatic::s_i);
}