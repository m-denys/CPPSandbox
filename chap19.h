#pragma once

// There is "new operator" (new expression or new keyword) and "operator new"
// in C++. 
// In expression - "T* = new T" return type, as it's seen, is T.
// "new operator" allocates memory (heap) required to placed a new object and
// call default ctor to initialize this object
// for expression - T* = new T(args), also called specific ctor and object initializes
// by specific value.
// "operator new" has following signature
// void* operator new(size_t)
// that is very similar to malloc function in C language
// Behavior of "operator new" is quite different from the "new expression or keyword"
// "operator new" allocates memory required for new object, and returns void* to this memory
// it doesn't call ctor for allocated block(blocks), but usually compiler still do it on his own
// The logic for delete is very close to logic for new
// "operator delete" has a following signature
// void delete(size_t);