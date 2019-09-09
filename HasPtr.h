#pragma once

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
    friend std::ostream& operator<<(std::ostream&, HasPtr const&);
    friend bool operator==(HasPtr const&, HasPtr const&);
    friend bool operator!=(HasPtr const&, HasPtr const&);
    friend HasPtr operator+(HasPtr const&, HasPtr const&);

public:
    HasPtr()
    : ps_(nullptr)
    , i_(0)
    {
#ifdef DEBUG
    std::cout << "HasPtr() is called\n";
#endif
    }

    HasPtr(std::string const& s, int const i)
    : ps_(new std::string(s))
    , i_(i)
    {
#ifdef DEBUG
    std::cout << "HasPtr(std::string const& s, int const i) is called\n";
#endif
    }

    HasPtr(HasPtr const& other)
    : ps_(new std::string(*other.ps_))
    , i_(other.i_)
    {
#ifdef DEBUG
    std::cout << "HasPtr(HasPtr& other) is called\n";
#endif
    }

    HasPtr& operator=(HasPtr const& other)
    {
#ifdef DEBUG
    std::cout << "HasPtr& operator=(HasPtr const& other) is called\n";
#endif
        if (this == &other)
        {
            return *this;
        }
        delete ps_;
        ps_ = new std::string(*other.ps_);
        i_ = other.i_;
        return *this;
    }

    // swap-copy idiom 
    // Assignment operators that use copy and swap are automatically exception 
    // safe and correctly handle self-assignment.
/*
    HasPtr& operator=(HasPtr other)
    {
#ifdef DEBUG
    std::cout << "HasPtr& operator=(HasPtr other) is called\n";
#endif  
        swap(*this, other);
        return *this;
    }
*/

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

    ~HasPtr()
    {
        delete ps_;
    }

    bool operator<(HasPtr const& other)
    {
        return i_ < other.i_;
    }

    void printInfo() { std::cout << "ps_: " << *ps_ << " i_: " << i_ << std::endl; }

private:
    std::string* ps_;
    int i_;
};

bool operator==(HasPtr const& lhs, HasPtr const& rhs)
{
#ifdef DEBUG
    std::cout << "HasPtr operator==(HasPtr const&, HasPtr const&) is called\n";
#endif
    if (lhs.ps_ && rhs.ps_)
    {
        return *lhs.ps_ == *rhs.ps_ && lhs.i_ == rhs.i_;
    }
    else if (!lhs.ps_ && !rhs.ps_)
    {
        return lhs.i_ == rhs.i_;
    }
    return false;       
}

bool operator!=(HasPtr const& lhs, HasPtr const& rhs)
{
#ifdef DEBUG
    std::cout << "HasPtr operator!=(HasPtr const&, HasPtr const&) is called\n";
#endif
    return !(lhs == rhs);       
}

HasPtr operator+(HasPtr const& lhs, HasPtr const& rhs)
{
#ifdef DEBUG
    std::cout << "HasPtr operator+(HasPtr const&, HasPtr const&) is called\n";
#endif
    if (lhs.ps_ && rhs.ps_)
    {
        return HasPtr(*lhs.ps_ + *rhs.ps_, lhs.i_ + rhs.i_);
    }
    return HasPtr();
}

inline void swap(HasPtr& lhs, HasPtr& other)
{
#ifdef DEBUG
    std::cout << "void swap(HasPtr&, HasPtr&) is called\n";
#endif
    std::swap(lhs.ps_, other.ps_);
    std::swap(lhs.i_, other.i_);
}

std::ostream& operator<<(std::ostream& os, HasPtr const& hp)
{
#ifdef DEBUG
    std::cout << "std::ostream& operator<<(std::ostream& os, HasPtr const& hp) is called\n";
#endif
    os << (*hp.ps_) << " " << hp.i_;
    return os;
}