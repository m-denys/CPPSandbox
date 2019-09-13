#pragma once

struct S1
{
    virtual void func()
    {

    }
};

struct S2 : S1
{
    void func() final override
    {

    }
};

// int main(int argc, char const* argv[])
// {
//     S1 s1;
//     S2 s2;

//     // Assignment is applicable, because there is used S1::operator=(S1 const&)
//     // And s2 can be passed as reference "operator=(s2)"
//     // BUT IT IS VERY BAD TECHNIQUE TO USE SUCH ASSIGNMENT
//     s1 = s2;
// }