#pragma once

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);

public:
    HasPtr()
    : _ps(nullptr)
    , _i(0)
    {
#ifdef DEBUG
    std::cout << "HasPtr() is called\n";
#endif
    }

    HasPtr(std::string const& s, int const i)
    : _ps(new std::string(s))
    , _i(i)
    {
#ifdef DEBUG
    std::cout << "HasPtr(std::string const& s, int const i) is called\n";
#endif
    }

    HasPtr(HasPtr& other)
    : _ps(new std::string(*other._ps))
    , _i(other._i)
    {
#ifdef DEBUG
    std::cout << "HasPtr(HasPtr& other) is called\n";
#endif
    }

    // swap-copy idiom 
    // Assignment operators that use copy and swap are automatically exception 
    // safe and correctly handle self-assignment.
    HasPtr& operator=(HasPtr other)
    {
#ifdef DEBUG
    std::cout << "HasPtr& operator=(HasPtr other) is called\n";
#endif  
        swap(*this, other);
        return *this;
    }

    HasPtr(HasPtr&& other)
    {
#ifdef DEBUG
    std::cout << "HasPtr(HasPtr&& other) is called\n";
#endif
        swap(*this, other);
    }

    HasPtr& operator=(HasPtr&& other)
    {
#ifdef DEBUG
    std::cout << "HasPtr& operator=(HasPtr&& other) is called\n";
#endif
        swap(*this, other);
        return *this;
    }

    /*  
    HasPtr& operator=(HasPtr const& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete _ps;
        _ps = new std::string(*other._ps);
        _i = other._i;
        return *this;
    }
    */

    ~HasPtr()
    {
        delete _ps;
    }

    bool operator==(HasPtr const& other)
    {
        if (_ps && other._ps)
        {
            return *_ps == *other._ps;
        }
        return false;       
    }

    bool operator<(HasPtr const& other)
    {
        return _i < other._i;
    }

    void printInfo() { std::cout << "_ps: " << *_ps << " _i: " << _i << std::endl; }

private:
    std::string* _ps;
    int _i;
};

inline void swap(HasPtr& lhs, HasPtr& other)
{
    std::swap(lhs._ps, other._ps);
    std::swap(lhs._i, other._i);

#ifdef DEBUG
    std::cout << "void swap(HasPtr&, HasPtr&) is called\n";
#endif
}
