#include "hierarchy.h"
#pragma once 
#include <memory>
#include <vector>
#include <algorithm>
#include <typeinfo>

class MyArray{

    //overloaded operator<<
    friend void operator<<(const char* p, const MyArray & arr){
        for(auto it = arr._vec.begin(); it != arr._vec.end(); ++it){
            if(std::next(it) != arr._vec.end()){
                (*it)->print();
                std::cout << p;
            }
            else{
                (*it)->print();
                std::cout << "\n";
            }
        }
    }

    private:
    //vector of shared pointers to Base class
    std::vector<std::shared_ptr<Base>> _vec;

    public:

    //add function template to add multiple types
    template <typename T>
    void add(const T & item){
        _vec.push_back(std::make_shared <Derived<T>>(item));
    }
    
    //destructor
    ~MyArray();

    //remove function template to remove multiple types - one chosen
    template <typename T>
    void remove(){
        auto new_end = std::remove_if(_vec.begin(),_vec.end(),[](std::shared_ptr<Base> & item){
            return typeid(*item) == typeid(Derived<T>);
        });
        _vec.erase(new_end,_vec.end());
    }


};

