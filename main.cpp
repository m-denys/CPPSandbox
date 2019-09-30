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

class Bits
{
    // Bit fields
public:
    // Only integral types are available
    unsigned is_colored  : 1; // Reserves 1 bit [0 - 1]
    unsigned num_of_events : 4; // Reserves 4 bits [0 - 15]
    unsigned line_counter : 8; // Reserves 8 bits [0 - 255]
// Other members can exists in such class    
public:
    std::string name_;

private:
    int age_;
};

/********************/

int main(int argc, char const* argv[])
{
    using namespace Utils;    
    
    Bits bits;
    bits.is_colored = 1;
    bits.num_of_events = 15;
    bits.line_counter = 255;
    
    print(bits.is_colored);
    print(bits.num_of_events);
    print(bits.line_counter);

}