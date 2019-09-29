#pragma once

namespace try_catch 
{
    // Try catch idiom for handling exception durion initialization
    template<typename T>
    Blob<T>::Blob(std::initializer_list<T> il) 
    try
    : data(std::make_shared<std::vector<T>(il))
    {
        // body
    }
    catch(std::bad_alloc const& e)
    {
        handle_out_of_range_memory(e);
    }

    // Will not rise an exception
    void func() noexcept;
    void func2() noexcept(true);
    void func3() noexcept(g()); // if g() not raise an exception
    void func4() throw(); // deprecated
    
    // Possible can rise an excpetion
    void func5() noexcept(false);
    
    // Possible can rise a specific exceptions
    void func6() throw(std::out_of_range, std::bad_alloc); // deprecated

    // Note:: using throw(...) declaration for describing possible exception which
    // can occur inside function or for insisting that any exception will not occur
    // is deprecated technique since c++11
} // try_catch
