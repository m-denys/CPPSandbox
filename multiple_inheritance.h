#pragma once

namespace mi 
{
    // Note: in MI reference or pointer on derived class can be transformed to 
    // any base class from hierarchy

    class A
    {
    public:
        A(){}
        ~A(){}

        virtual void info() const
        {
            std::cout << "A" << std::endl;
        }
    };

    class B1 : public A
    {
    public:
        B1(){}
        ~B1(){}
    };

    class B2 
    {
    public:
        B2(){}
        ~B2(){}
    };

    class C : public B1, public B2
    {
    public:
        C(){}
        ~C(){}

        void info() const override
        {
            std::cout << "C" << std::endl;
        }
    };

    // main()
    // {
    //     mi::A* ptr = new mi::C();
    //     ptr->info();
    // }

    // Ambiguity
    class AA
    {
    public:
        int i_ = 42;
    };

    class BLeft : public AA
    {
    public:
        float f_ = 3.14159;
    };

    class BRight : public AA
    {
    public:
        float f_ = 3.14159;
    };

    class CC : public BLeft, public BRight
    {
    public:
        // Will not compile, the call is ambiguous
        // int getI() { return BLeft::i_;} // ambiguous
        // int getF() { return f_;} // ambiguous

        // Will compile, ambiguity is removed
        int getI() { return BLeft::i_;} 
        float getF() { return BRight::f_;} 
    };

    // Virtual inheritance
    namespace virtual_inheritance 
    {
        class Base
        {
        public:
            int i_ = 13;       
        };

        class DerivedL : public virtual Base
        {
        };

        class DerivedR : public virtual Base
        {   
        };

        class Derived : public DerivedL, public DerivedR
        {
        public:
            // There is no ambiguity
            // Virtual inheritance merged member from Base class
            // And for derived it is considered as one member: int i_
            int getMember() { return i_; }
        };

        // Initialization
        // Virtual parts always are initialized first
        // Without their reference in hierarhy
        // For exanmple, in hierarhy above its -> Base -> DerivedL, DerivedR -> Derived
        // Without virtual inheritance every class would initialize his parent
        // Derived -> DerivedL -> Base, DerivedR -> Base, init of Derived 

    } // virtual_inheritance

} // mi


