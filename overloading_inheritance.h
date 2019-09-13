#pragma once

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
    // Let compliler to be awared about getProd in Base
    using Base::getProd;

    int getProd(int a, int b, int c)
    {
        return a * b * c;
    }
};

// int main(int argc, char const* argv[])
// {
//    using namespace Utils;
   
//    Derived d;
//    print(d.getProd(5, 2));
//    print(d.getProd(2, 4));
//    print(d.getProd(3, 3, 3));
// }

// Output:
// 10
// 8
// 27
