#pragma once

namespace Templates
{
    // A name used in a template declaration or definition and that is dependent on 
    // a template-parameter is assumed not to name a type unless the applicable name
    // lookup finds a type name or the name is qualified by the keyword typename.

    // In short, if the compiler can't tell if a dependent name is a value or a type, 
    // then it will assume that it is a value.

    template<typename Iterator, typename V>
    Iterator find(Iterator first, Iterator last, V value)
    {
        for (; first != last; ++first)
        {
            if (*first == value)
            {
                return first;
            }
        }        
        return last;    
    }

    template<typename T>
    class Boo
    {
    public:
        using value_type = T;

    private:
        value_type value;
    };

} // namespace Templates