#include <iostream>
#include "TestClass.h"
#pragma once

class SmartPtr{

    private:

    //release() is a private method that decrements the reference count and deletes the object if the reference count is zero.
    void release();

    //The pointer to the object.
    TestClass* _ptr;

    //The reference count.
    size_t* _refCount;

    public:

    //The constructor initializes the pointer to the object and the reference count.
    SmartPtr(TestClass*ptr=nullptr):_ptr(ptr),_refCount(new size_t(1)){}

    //The destructor calls release().
    ~SmartPtr(){
        release();
    }

    //The copy constructor increments the reference count.
    SmartPtr(const SmartPtr & other):_ptr(other._ptr),_refCount(other._refCount){
        ++(*_refCount);
    }

    //The assignment operator calls release() and then copies the pointer to the object and the reference count.
    SmartPtr & operator=(const SmartPtr & other);
        

    //The move constructor moves the pointer to the object and the reference count.
    SmartPtr(SmartPtr && other):_ptr(other._ptr),_refCount(other._refCount){
        other.release();
    }

    //The move assignment operator moves the pointer to the object and the reference count.
    SmartPtr & operator=(SmartPtr && other);

    //useCount() returns the reference count.
    size_t useCount()const{
        return (_refCount!=nullptr)? *_refCount:0;
    }

    //The arrow operator returns a pointer to the object.
    TestClass* operator->()const{
        return _ptr;
    }

    //The reference operator returns a reference to the object.
    TestClass & operator*()const{
        return* _ptr;
    }

    //The bool operator returns true if the pointer to the object is not null.
    operator bool()const{
        return _ptr!=nullptr;
    }


};