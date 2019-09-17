#pragma once

struct A
{
    A& operator=(A const& other)
    {
        std::cout << "assignment in A" << std::endl;
        return *this;
    }
};

struct B : public A
{
    B& operator=(B const& other)
    {
        // There is no automatic assignment for base class
        A::operator=(other);
        std::cout << "assignment in B" << std::endl;
        return *this;
    }
};

// int main()
// {
//     A a, a1;
//     B b, b1;
    
//     b1 = b; 
// }