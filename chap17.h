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

    // rEGEX
    // string pattern("[^c]ei"); 
    // pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
    // regex r(pattern); 
    // smatch results;  
    // string test_str = "receipt freind theif receive";  
    // cout << results.str() << endl; 

    // rANDOM
   // std::default_random_engine e;
   // for (int i = 0; i < 10; ++i)
   // {
   //     print(e());
   // }
    // Output(The same output for each machine, without defined seed):
    // 16807
    // 282475249
    // 1622650073
    // 984943658
    // 1144108930
    // 470211272
    // 101027544
    // 1457850878
    // 1458777923
    // 2007237709

    // Small trick
    unsigned getRandom(unsigned const seed = 0)
    {
        // With static, random engine saves his 
        // state and produces new number on every call
        static unsigned used_seed = seed;
        static std::default_random_engine e;
        static std::uniform_int_distribution<unsigned> u(0, 9); 
        
        if (used_seed != seed)
        {
            e.seed(used_seed = seed);
        }

        return u(e);
    }

} // chap17
