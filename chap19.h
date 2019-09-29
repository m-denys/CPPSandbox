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
// Note: explicit destructor call destroy an object, but doesnt free memory
// so, this memory can be used over and over again

