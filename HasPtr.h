#pragma once

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);

public:
    HasPtr()
    : _ps(nullptr)
    , _i(0)
    {
    }

    HasPtr(std::string const& s = std::string(), int const i = 0)
    : _ps(new std::string(s))
    , _i(i)
    {
    }

    HasPtr(HasPtr const& rhs)
    : _ps(new std::string(*rhs._ps))
    , _i(rhs._i)
    {
    }

    // swap-copy idiom 
    // Assignment operators that use copy and swap are automatically exception 
    // safe and correctly handle self-assignment.
    HasPtr& operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }

    /*  
    HasPtr& operator=(HasPtr const& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        delete _ps;
        _ps = new std::string(*rhs._ps);
        _i = rhs._i;
        return *this;
    }
    */

    ~HasPtr()
    {
        delete _ps;
    }

    bool operator==(HasPtr const& rhs)
    {
        if (_ps && rhs._ps)
        {
            return *_ps == *rhs._ps;
        }
        return false;       
    }

    bool operator<(HasPtr const& rhs)
    {
        return _i < rhs._i;
    }

    void printInfo() { std::cout << "_ps: " << *_ps << " _i: " << _i << std::endl; }

private:
    std::string* _ps;
    int _i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::swap(lhs._ps, rhs._ps);
    std::swap(lhs._i, rhs._i);

#ifdef DEBUG
    std::cout << "void swap(HasPtr&, HasPtr&) is called\n";
#endif
}
