#include <iostream>
#pragma once 

//This is an auxiliary file. Its role is to create an artificial hierarchy in order to 
//enable MyArray container to store different types of data.


//Base class
class Base{
    public:
    virtual ~Base()=default;
    virtual void print()const=0;
};


//Derived class template
template <typename T>
class Derived : public Base{
    private:
    T _data;
    public:
    Derived(const T & data):_data(data){}
    void print()const override{
        std::cout << _data;
    }
};



