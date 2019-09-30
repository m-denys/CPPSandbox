#pragma once

// Exception Handling

// The fact that destructors are run during stack unwinding affect show we write destructors. 
// During stack unwinding, an exception has been raised but is not yet handled. If a new exception 
// is thrown during stack unwinding and not caught in the function that threw it, 
// terminate is called. Because destructors may be invoked during stack unwinding, 
// they should never throw exceptions that the destructor it self does not handle. That is, 
// if a destructor does an operation that might throw, it should wrap that operation in 
// a try block and handle it locally to the destructor. In practice, because destructors free resources, 
// it is unlikely that they will throw exceptions. All of the standard library types guarantee that 
// their destructors will not raise an exception. 

namespace chap18 
{
    // int getValue(std::vector<int> const& v, size_t index)
    // {
    //     if (index >= v.size())
    //     {
    //         throw std::out_of_range("index in getValue is out of range");
    //     }

    //     return v[index];
    // }
   
    // std::vector<int> v{ 1, 2, 3, 4 };
    // try
    // {
    //     print(getValue(v, 10));
    // }
    // catch(std::out_of_range const& e)
    // {
    //     print(e.what());
    //     print("error is catch");
    // }
}

} // chap18
