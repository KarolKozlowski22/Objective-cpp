#pragma once 
#include <iostream>
#include "Vect.h"

//template class to create matrices with various types and sizes
template <typename T, size_t n, size_t m>
class Array{

    //matrix
    private:
    T _array[n][m];

    public:
    //constructor assigning given value in main to the matrix
    Array(const T value){
        for(unsigned i=0;i<n;i++){
            for(unsigned j=0;j<m;j++){
            _array[i][j]=value;
            }
        }
    }

    //operator returning value from given indexes - to modify it later
    T & operator()(size_t index1, size_t index2){
        return _array[index1][index2];
    }

    //simpler ptinter
    void print(const std::string & sep)const{
        std::cout << sep << "\n";
        for(unsigned i=0;i<n;i++){
            for(unsigned j=0;j<m;j++){
                std::cout << _array[i][j] << "   ";
            }
            std::cout<<"\n";
        }
        std::cout << sep << "\n";
    }

    //operator do multiply matrix by vector - created as a template to deduce apropriate type of data
    //decltype is used to deduce type of result
    template <typename U, size_t size>
    auto operator*(const Vect<U,size>&other)const{
        Vect<decltype(_array[0][0]*other.getData(0)),n> result{0};
        if(size!=m){
            std::cout << "Unable to multiply\n";
            return result;
        }
        for(unsigned i=0;i<n;i++){
            for(unsigned j=0;j<m;j++){
                result[i]+=_array[i][j]*other.getData(j);
            }
        }
        return result;
    }
};