#pragma once

// There is "new operator" (new expression or new keyword) and "operator new"
// in C++. 
// In expression - "T* = new T" return type, as it's seen, is T.
// "new operator" allocates memory (heap) required to placed a new object and
// call default ctor to initialize this object
// for expression - T* = new T(args), also called specific ctor and object initializes
// by specific value.
// "operator new" has following signature
//--------------------
// void* operator new(size_t)
//--------------------
// that is very similar to malloc function in C language
// Behavior of "operator new" is quite different from the "new expression or keyword"
// "operator new" allocates memory required for new object, and returns void* to this memory
// it doesn't call ctor for allocated block(blocks), but usually compiler still do it on his own
// The logic for delete is very close to logic for new
// "operator delete" has a following signature
//--------------------
// void delete(void*);
//--------------------

// Placement new operator
// Placement new is a variation new operator in C++. Normal new operator does two things: 
// (1) Allocates memory 
// (2) Constructs an object in allocated memory.

// Placement new allows us to separate above two things. In placement new, we can pass 
// a preallocated memory and construct an object in the passed memory.

// new vs placement new
//     Normal new allocates memory in heap and constructs objects tehre whereas using 
//     placement new, object construction can be done at known address.
//     With normal new, it is not known that, at what address or memory location it’s 
//     pointing to, whereas the address or memory location that it’s pointing is known 
//     while using placement new.
//     The deallocation is done using delete operation when allocation is done by new 
//     but there is no placement delete, but if it is needed one can write it with the help 
//     of destructor

// Syntax:
// new (address) (type) initializer

// int main() 
// { 
//     // buffer on stack 
//     unsigned char buf[sizeof(int)*2] ; 
  
//     // placement new in buf, inits blocks by 3 and 5
//     int *pInt = new (buf) int(3); 
//     int *qInt = new (buf + sizeof (int)) int(5); 

//     int *pBuf = (int*)(buf+0) ; 
//     int *qBuf = (int*) (buf + sizeof(int)); 
//     return 0; 
// } 

// Explicit call for destructor
// main()
// {
//     string* sp = new string("a value");
//     sp->~string();    
// }
// Note: explicit destructor call destroy an object, but doesn't free memory
// so, this memory can be used over and over again

// RTTI (Runtime Type Identification)
// In C++ Provided by "typeid" and "dynamic_cast"

// DYNAMIC_CAST (dynamic_cast)
// Note: If it's possible, avoid using of dynamic_cast
// It is better to implement virtual functions mechanism where it is applicable
//--------------------
// Forms:
// dynamic_cast<T*>(objPtr);
// dynamic_cast<T&>(objRef);
// dynamic_cast<T&&>(objRvalueRef);
// Fail during objPtr casting -> returns nullptr or 0
// Fail during refs casting -> raise bad_cast exception
//--------------------

//--------------------
// Note: dynamic_cast is applicable only for polymorphic classes (virtual function should be in class hierarchy)
// struct Base
// {
//      virtual void func(){}   
// };

// struct Derived : public Base
// {
// };

// main()
// {
//     // Pointer casting
//     Base* basePtr = new Derived;
//     if (auto ptr = dynamic_cast<Derived*>(basePtr))
//     {
//         print("yes");
//     }
//     else
//     {
//         print("no");
//     }

//     // Reference casting
//     Base& baseRef = derivedObj;
//     try
//     {
//         auto& derivedRef = dynamic_cast<Derived&>(baseRef)
//     }
//     catch (bad_cast& e)
//     {
//         // handle exception somehow
//     }
// }
//---------------------

// TYPEID (typeid)
// Derived *dp = new Derived; 
// Base *bp = dp; // bothpointers point to a Derived object
// // compare the type of two objects at run time 
// if (typeid(*bp) == typeid(*dp)) 
// { 
//     // bp and dp point to objects of the same type 
// } 
// // test whether the run-time type is a speciﬁc type 
// if (typeid(*bp) == typeid(Derived)) 
// { 
//     // bp actually points to a Derived 
// }
// In the ﬁrst if, we compare the dynamic types of the objects to which bp and dp point. If both point to the same type, 
// then the condition succeeds. Similarly, the second if succeeds if bp currently points to a Derived object. 
// Note that the operands to the typeid are objects—we used *bp, not bp:
// // test always fails: the type of bp is pointer to Base  
// if (typeid(bp) == typeid(Derived)) 
// { 
//     // code never executed 
// }

// Note: typeid(arg) returns reference to static object of type_info declared in <type_info> header.
// Useful methods: t1 == t2, t1 != t2, t.name(), t1.before(t2) ( Is t1 goes before t2 )

// USING RTTI
// class Base 
// { 
//     friend bool operator==(const Base&, const Base&); 
// public: 
//     // interface members for Base 
// protected: 
//     virtual bool equal(const Base&) const;     
//     // data and other implementation members of Base 
// };

// class Derived : public Base 
// { 
// public: 
// // other interface members for Derived 
// protected: 
//     bool equal(const Base&) const; 
//     // data and other implementation members of Derived
// }; 

// bool operator==(const Base &lhs, const Base &rhs) 
// { 
//     // returns false if typeids are different; otherwise makes a virtual call to equal
//     return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
// } 

// bool Derived::equal(const Base &rhs) const 
// { 
//     // we know the types are equal, so the cast won’t throw 
//     auto r = dynamic_cast<const Derived&>(rhs); 
//     // do the work to compare two Derived objects and return the result 
// }

// bool Base::equal(const Base &rhs) const 
// { 
//     // do whatever is required to compare to Base objects 
// } 

// ENUMERATIONS
// scoped enumerators
// enum class name {...}; enum struct name {...};

// unscoped enumerators
// enum name (name is optional) {...};
// Note: names declared in unscoped enumerators extend on whole scope where they defined

// Specifying the Size of an enum
// Although each enum deﬁnes a unique type, it is represented by one of the built-in integral types. 
// Under the new standard, we may specify that type by following the enum name with a colon and the 
// name of the type we want to use:

enum intValues : unsigned long long 
{ 
    charTyp = 255, 
    shortTyp = 65535, 
    intTyp = 65535, 
    longTyp = 4294967295UL, 
    long_longTyp = 18446744073709551615ULL 
};

// If we do not specify the underlying type, then by default SCOPED enums have int as the underlying type. 
// There is no default for UNSCOPED enums; all we know is that the underlying type is large enough to hold the enumerator 
// values. When the underlying type is specified (including implicitly specified for a scoped enum), it  
// is an error for an enumerator to have a value that is too large to fit in that type. Being able to specify 
// the underlying type of an enum lets us control the type used across different implementations. We can be confident that our program compiled 
// under one implementation will generate the same code when we compile it on another.

// enum class Scoped // by default : int
// {
// };

// enum class ScopedSpecified : long long
// {
// };

// enum Unscoped
// {
// };

// enum UnscopedSpecified : short
// {
// };

// main()
// {
//     print(sizeof(Scoped));
//     print(sizeof(ScopedSpecified));
//     print(sizeof(Unscoped));
//     print(sizeof(UnscopedSpecified));
// }

// Output:
// 4
// 8
// 4
// 2

// Forward declaration for enums
// Under the new standard, we can forward declare an enum. An enum forward declaration must specify (implicitly or explicitly) 
// the underlying size of the enum:
// // forward declaration of unscoped enum named intValues 
// enum intValues : unsigned long long; // unscoped, must specify a type 
// enum class open_modes; // scoped enums can use int by default

// Conversion to int
//For unscoped enums it is possible to convert enum value (enumerator) to integral type
// enum Pos 
// {
//     Pos_Up = 0,
//     Pos_Down = 1
// };

// void f(char ch)
// {
// }

// main()
// {
//     f(Pos::Pos_Up); // works
//     Pos pos = 10; // error: invalid conversion from 'int' to 'Pos'
// }

// Pointer to Class Member
// class Screen 
// { 
// public: 
//     typedef std::string::size_type pos; 
//     char get_cursor() const { return contents[cursor]; } 
//     char get() const; 
//     char get(pos ht, pos wd) const; 

//     // Public for an ability to use it with pointers to members
//     std::string contents; 

// private: 
//     pos cursor; 
//     pos height, width; 
// };

// // pdata can point to a string member of a const (or non const ) Screen object
// string const Screen::*pdata;
// pdata = &Screen::contents;

// // Or much simpler way
// auto pdata = &Screen::contents; 

// Screen myScreen, *pScreen = &myScreen; 
// // .* dereferences pdata to fetch the contents member from the object myScreen
// auto s = myScreen.*pdata; 
// // ->* dereferences pdata to fetch contents from the object to which pScreen points
// s = pScreen->*pdata;

// A Function Returning a Pointer to Data Member 
// Because data members are typically private, we normally can’t get a pointer to data member directly.
// Instead, if a class like Screen wanted to allow access to its contents member, it would deﬁne a function 
// to return a pointer to that member:

// class Screen 
// { 
// public:
//     // data is a static member that returns a pointer to member 
//     static const std::string Screen::* data() { return &Screen::contents; } 
//     // other members as before
// };

// //data() returns a pointer to the contents member of class Screen 
// const string Screen::*pdata = Screen::data();

// // fetch the contents of the object named myScreen
// auto s = myScreen.*pdata;

// BITFIELDS
// class Bits
// {
//     // Bit fields
// public:
//     // Only integral types are available
//     unsigned is_colored  : 1; // Reserves 1 bit [0 - 1]
//     unsigned num_of_events : 4; // Reserves 4 bits [0 - 15]
//     unsigned line_counter : 8; // Reserves 8 bits [0 - 255]
// // Other members can exists in such class    
// public:
//     std::string name_;

// private:
//     int age_;
// };

// // Using
//     Bits bits;
//     bits.is_colored = 1;
//     bits.num_of_events = 15;
//     bits.line_counter = 255;
    
//     print(bits.is_colored);
//     print(bits.num_of_events);
//     print(bits.line_counter);

// volatile Qualifier
// The precise meaning of volatile is inherently machine dependent and can be understood only by reading the compiler documentation. 
// Programs that use volatile usually must be changed when they are moved to new machines or compilers. 
//The volatile keyword is a directive to the compiler that it should not perform optimizations on such objects

// The volatile qualifier is used in much the same way as the const qualifier. 
// It is an additional modifier to a type:
// volatile int display_register; // int value that might change
// volatile Task *curr_task; // curr_task points to a volatile object
// volatile int iax[max_size]; // each element in iax is volatile
// volatile Screen bitmapBuf; // each member of bitmapBuf is volatile
// There is no interaction between the const and volatile type qualifiers. A type can be both const and volatile, in which case 
// it has the properties of both. 

// Linkage Directives: extern "C" 
// // illustrative linkage directives that might appear in the C++ header <cstring>
// // single-statement linkage directive 
// extern "C" size_t strlen(const char *); 
// // compound-statement linkage directive 
// extern "C" 
// { 
//     int strcmp(const char*, const char*); 
//     char *strcat(char*, const char*); 
// }

// PREPROCESSOR SUPPORT FOR LINKING TO C
// To allow the same source ﬁle to be compiled under either C or C++, the preprocessor 
// defines _ _cplusplus (two underscores) when we compile C++. Using this variable, we can conditionally include 
// code when we are compiling C++: 
// #ifdef __cplusplus 
// // ok:we’re compiling C++ 
// extern "C" 
// #endif 
// int strcmp(const char*, const char*);
