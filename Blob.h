#pragma once

// Compiler instantiates template-class member functions only when they are used
// by class user code. If any function isn't used, there is no instance of this function.

template<typename T>
class Blob
{
public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

    Blob();
    Blob(std::vector<T>* ptr);

    size_type size() const;

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
typename Blob<T>::size_type Blob<T>::size() const
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
