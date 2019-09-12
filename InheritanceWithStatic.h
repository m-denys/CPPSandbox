#pragma once

class StaticInBase
{
public:
    static int s_i;
};
int StaticInBase::s_i = 42;

class StaticInDerived : public StaticInBase
{
    // code
};

// int main(int argc, char const* argv[])
// {
//    using namespace Utils;
//    ///////////////
   
//    print(StaticInBase::s_i);
//    print(StaticInDerived::s_i);

//    StaticInDerived::s_i = 101;

//    print(StaticInBase::s_i);
//    print(StaticInDerived::s_i);
// }

// Output:
// 42
// 42
// 101
// 101