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

struct Boo
{
    int mem_ = 42;
};

/********************/

int main(int argc, char const* argv[])
{

    std::vector<int> v{1, 2};
    DataHandle<std::vector<int>> handle(&v);
    Utils::print(handle->size());

    DataHandle<Boo> handle1(new Boo());
    Utils::print(handle1->mem_);
    Utils::print((*handle1).mem_);
}