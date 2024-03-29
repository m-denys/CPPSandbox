#pragma once

struct Abs
{
	template<typename T>
	T operator()(T const& val)
	{
		return val > 0 ? val : -val;
	}

    template<typename T>
    T operator()(T const& lhs, T const& rhs)
    {
        return lhs * rhs;
    }
};

class Ternary
{
public:
    template<typename T>
    T operator()(bool cond, T ifTrue, T ifFalse)
    {
        return cond ? ifTrue : ifFalse;
    } 
};

/*
int main(int argc, char const* argv[])
{
    Utils::print(Abs()(-42.134123));
    Utils::print(Abs()(-42.134123,-404.13));
}
*/