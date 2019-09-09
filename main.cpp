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

/****Test-Section****/

/********************/

int main(int argc, char const* argv[])
{
    Utils::print(Abs()(-42.134123));
    Utils::print(Abs()(-42.134123,-404.13));
}