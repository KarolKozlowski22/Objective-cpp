#pragma once 
#include <iostream>

//template class to create vectors with various types and sizes
template <typename T, size_t size>
class Vect{

    //operator to print vector
    friend std::ostream & operator<<(std::ostream & out, const Vect & v){
        out << "[" << " ";
        for (unsigned i = 0; i < size; i++) {
            out << v._array[i] << " ";
        }
        out << "]";
        return out;
    }

    //vector
    private:
    T _array[size];

    public:
    //constructor assigning given value in main to the vector
    Vect(const T value){
        for (unsigned i = 0; i < size; i++) {
        _array[i] = value;
        }
    }

    //simple getter
    T getData(size_t index)const{
        return _array[index];
    }

    //operator returning value from given index - to modify it later
    T & operator[](size_t index){
        return _array[index];
    }

    //operator * to calculate dot product of two vectors
    //declared as template to deduce apropriate type of data
    //decltype is used to deduce type of result
    template<typename U>
    auto operator*(const Vect<U,size>&other)const{
        decltype(_array[0] * other.getData(0)) result = 0;
        for (unsigned i = 0; i < size; i++) {
            result += _array[i] * other.getData(i);
        }
        return result;
    }
};