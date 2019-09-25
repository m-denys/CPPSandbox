#pragma once

namespace chap17 
{
    class MyClass
    {
    public:
        explicit MyClass(int const i)
        : i_(i)
        {
        }

    private:
        int i_;
    };

    // int main(int argc, char const* argv[])
    // {
    //     Note: only direct initialization is applicable
    //     ctor is declared as explicit
    //     MyClass obj(10);
    //     MyClass obj1 = 10; // error
    // }

    // tUPLES
    // std::tuple<T1, T2 ..., Tn> t;
    // std::make_tuple<T1, T2..., Tn>;
    // std::get<i>(t);
    // std::tuple_size<TupleType>::value;
    // std::tuple_element<i, tupleType>::type;

    // bITSET
    // Note: very useful when u64 isn't enough
    //std::bitset<128> mask(1);
    //std::cout << mask << std::endl; -> Output: 000...0001 (128 element)



} // chap17
