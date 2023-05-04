#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
#include <utility>
#include <algorithm>

class MyArray{

    //operator << in order to print the array
    friend std::ostream & operator<<(std::ostream & out, const MyArray & arr){
        if(arr._tab!=nullptr){
           for(int i=0;i<arr._size;i++){
            if(i==0){
                out<<"["<<arr._tab[i]<<", ";
            }
            else if(i!=0&&i<arr._size-1){
                out<<arr._tab[i]<<", ";
            }
            else{
                out << arr._tab[i] << "]";
            }
            
           }
            return out<<"\n";
        }
        else{
            return out<<"[]"<<"\n";
        }
    }

    //operator + in order to add a value to the array
    friend MyArray operator+(const MyArray arr, const int val) {
        MyArray result(arr);
        for (int i = 0; i < result._size; ++i) {
            result[i] += val;
        }
        return result;
    }


    //operator + in order to add a value to the array using operator + above
    friend MyArray operator+(int val, const MyArray& arr) {
        return arr + val;
    }


    private:
    //pointer to the array
    int* _tab;
    //size of the array
    size_t _size;

    public:
    //default constructor
    MyArray(){}

    //constructor with size
    MyArray(size_t);

    //copy constructor
    MyArray(const MyArray&);

    //move constructor
    MyArray(MyArray&&)noexcept;

    //operator [] in order to access the array
    int & operator[](size_t);

    //operator [] in order to access the array const version
    const int & operator[](size_t)const;

    //operator ++ in order to increment the array
    void operator++()const;

    //print the array
    void print(std::string)const;

    //size of the array
    int size()const;

    //operator = in order to assign the array
    MyArray & operator=(const MyArray&);

    //operator += in order to add a value to the array
    void operator+=(const int);

    //destructor
    ~MyArray();





};



#endif