#pragma once

// Compiler instantiates template-class member functions only when they are used
// by class user code. If any function isn't used, there is no instance of this function.

template<typename T>
class Blob
{
public:
    using valueTpe = T;
    using sizeTpe = typename std::vector<T>::sizeTpe;

    Blob();
    Blob(std::vector<T>* ptr);

    sizeTpe size() const;

private:
    std::vector<T>* data_;
};

template<typename T>
Blob<T>::Blob()
{
    data_ = nullptr;
}

template<typename T>
Blob<T>::Blob(std::vector<T>* ptr)
{
    data_ = ptr;
}

template<typename T>
typename Blob<T>::sizeTpe Blob<T>::size() const
{
    return data_ ? data_->size() : 0;
}

// FRIENDSHIP
template<typename T> class Pal;
class C
{
    // Special instance is friend
    friend class Pal<C>;
    
    // Entire template is friend
    template <typename T> friend class Pal2;
};

template<typename T> class C2
{
    // Friendship for instances with the same type T
    friend class Pal<T>;

    // Friendship for all instances (T and X are different)
    template <typename X> friend class Pal2;
};

// Static Members
// Each instantiated class will have specific static memeber
template<typename T>
class MyBlob
{
public:
    MyBlob(){}
    ~MyBlob(){}

    static int index;
};

template<typename T>
int MyBlob<T>::index = 0;

// int main(int argc, char const *argv[])
// {
//     MyBlob<int> iObj;
//     MyBlob<float> fObj;
    
//     iObj.index = 101;
//     fObj.index = 404;
       
//     print(MyBlob<int>::index);
//     print(MyBlob<float>::index);

//     return 0;
// }
    
// Output:
// 101
// 404

// Default args
template<typename T = int, typename Comp = std::less<T>>
class Comparator
{
public:
    T operator()(T const& left, T const& right)
    {
       return Comp()(left, right);
    }
};
// Possible using: 
//     Comparator<> comp;
//     Comparator<int> comp1;
//     Comparator<int, std::equal<T>> comp2;

// Template function inside template class
template<typename T>
class Data
{
public:
    template<typename Iterator>
    Data(Iterator first, Iterator second);
    
private:
    std::vector<T> data_;
};

template<typename T>
template<typename Iterator>
Data<T>::Data(Iterator first, Iterator second)
: data_(first, second)
{
}

// Compiler and Instantiation
template<typename T>
class MyClass
{
public:
    T getSomething()
    {
         // there is no value to return
         // but compiler will not notify us
         // while this function be used   
    }
};

// Explicit template argument
template<typename T1, typename T2, typename T3>
T1 sum(T2 const& a, T3 const& b)
{
    return a + b;
}
// main()
// {
//     // T1 is explicitly defined in this case
//     auto res = sum<int>(10.f + 404);
// }

// When it is not possible to get return type before list of parameters
// Trailing edge return type declaration can be used
// Note: by c++14, only "auto" is enough
template<typename Iterator>
auto getMiddle(Iterator first, Iterator second) -> decltype(*first)
{
    return *(first + std::distance(first, second) / 2);
}

// TYPE_TRAITS -> <type_trait>
template<typename Iterator>
auto getMiddleNoRef(Iterator first, Iterator second) 
    -> typename std::remove_reference<decltype(*first)>::type
{
    return *(first + std::distance(first, second) / 2);
}

// std::move
// standard library implementation (lpmn)
namespace vs
{
    template<typename T>
    typename std::remove_reference<T>::type&& move(T&& t)
    {
        return static_cast<typename std::remove_reference<T>::type&&>(t);
    }
} // vs

// std::forward
// visual studio impl
    // FUNCTION TEMPLATE forward
namespace vs 
{
    template<class _Ty>
        /*_NODISCARD*/ constexpr _Ty&& forward(std::remove_reference_t<_Ty>& _Arg) /*_NOEXCEPT*/
        {    // forward an lvalue as either an lvalue or an rvalue
        return (static_cast<_Ty&&>(_Arg));
        }
} // vs

// Using string stream
// #include <sstream>

// main()
// {
//     std::ostringstream ss;
//     ss << 42;
//     print(ss.str());
// }

// Variadic TEMPLATES
namespace variadic 
{
    // Note: pay attention on "sizeof..."
    template<typename... Args>
    void foo(Args... args)
    {
        std::cout << "count of Args: " << sizeof...(Args) << std::endl;
        std::cout << "count of args: " << sizeof...(args) << std::endl;
    }

    // Recursive call
    template<typename T>
    void printArgs(T t)
    {
        std::cout << t << std::endl;
    }

    template<typename T, typename... Args>
    void printArgs(T t, Args... args)
    {
        std::cout << t << std::endl;
        printArgs(args...);
    }

    // Node: Args... and args.. -> pack expansion (разверTывание пакеTа),
    // Dots are signals that args should be expanded in specific place

} // variadic

// TEMPLATE SPECIALIZATION
// When there should be special template version for specific arguments
// 'template specialization' might be used
namespace specialization 
{
    // Function specialization
    // Generic version
    template<typename T1, typename T2>
    int compare(T1 const& lhs, T2 const& rhs)
    {
        return lhs == rhs ? 0 : (lhs < rhs ? -1 : 1); 
    }

    // Specialized version
    // Note: generic version declaration should be visible
    template<>
    int compare(char const* const& p1, char const* const& p2)
    {
        return strcmp(p1, p2);
    }

    // Class specialization
    namespace std 
    {
        template<typename T>
        struct hash
        {
            // template code
        };

        class Sales_data;
        template<>
        struct hash<Sales_data>
        {
            typedef size_t result_type;
            typedef Sales_data argument_type;
            size_t operator() (Sales_data const& s) const;
        };

        size_t hash<Sales_data>::operator() (Sales_data const& s) const
        {
            /*return hash<string>()(s.bookNo) ^
                   hash<unsigned>()(s.units_sold) ^
                   hash<double>()(s.revenue);*/
            return 42;
        }
    } // std

    // Class partial specialization
    template <class T> 
    struct remove_reference 
    { 
        typedef T type; 
    }; 

    template <class T> 
    struct remove_reference<T&>  
    { 
        typedef T type; 
    }; 

    template <class T> 
    struct remove_reference<T&&>  
    {  
        typedef T type; 
    };

} // specialization


