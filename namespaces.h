#pragma once

namespace nmsps 
{
    // Inline namespaces
    /***inline_namespace.h***/
    // inline namespace inline_namespace
    // {
    //         class FizzBazz
    //         {
    //         public:
    //             FizzBazz(){}
    //             ~FizzBazz(){}
    //         };
    // }

    // /***usual_namespace.h***/
    // namespace usual_namespace
    // {    
    //     #include "inline_namespace.h"
    //     // All members inside inline_namespace are acceptable through usual_namespace
    // }

    // main()
    // {
    //     // Equivalent to usual_namespace::inline_namespace::FizzBazz fz();
    //     usual_namespace::FizzBazz fz();
    // }

    // namespace aliasing
    namespace original 
    {
        int i = 42;
        // code
    } // original

    namespace alias = original;
    // main()
    // {
    //     printf("%d\n", alias::i);
    // }

    // using namespace directive
    //// global scope
    // {
    //     // local scope
    //     // directive spreads on local scope
    //     using namespace std;
    //     cout << "printing string without using of std::" << endl;
    // }
    // std::cout << "opposite" << std::endl;

} // nmsps