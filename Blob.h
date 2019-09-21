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
