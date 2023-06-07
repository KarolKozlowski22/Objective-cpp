#include "hierarchy.h"
#pragma once

//Printer class
class Printer{

    public:
    //template print function to print different types of data 
    template <typename T>
    void print(const T & item){
        Derived<T> d(item);
        d.print();
        std::cout << "\n";
    }

    //template print function to print iterable types
    template <typename T, size_t size>
    void print(const T(&item)[size]){
        for(int i=0;i<size;i++){
            std::cout << item[i] << " ";
        }
        std::cout << "\n";
    }

    
};