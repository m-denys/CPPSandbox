////////////////////
#include <iostream>
#include <vector>
#include <string>
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

///////////////////
#include "Shape.h"

/****Test-Section****/

struct Base
{
    int getProd(int a, int b)
    {
        return a * b;
    }

    int getProd(int a)
    {
        return a * a;
    }
};

struct Derived : public Base
{
    using Base::getProd;

    int getProd(int a, int b, int c)
    {
        return a * b * c;
    }
};

/********************/

int main(int argc, char const* argv[])
{
   using namespace Utils;
   

   Derived d;

   print(d.getProd(5, 2));
   print(d.getProd(2, 4));
   print(d.getProd(3, 3, 3));
}