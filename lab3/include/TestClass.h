#include <iostream>
#pragma once

class TestClass{

    public:

    //The constructor initializes the name.
    TestClass(const std::string & name):_name(name){
        std::cout<<"++ Tworze obiekt TestClass: "<<_name<<"\n";
    }

    //The destructor prints a message.
    ~TestClass(){
        std::cout<<"-- Usuwam obiekt TestClass: "<<_name<<"\n";
    }

    //info() returns the name.
    std::string info()const{
        return _name;
    }

    private:

    //The name.
    std::string _name;

};