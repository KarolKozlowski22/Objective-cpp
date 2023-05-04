#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
#include <utility>
#include <algorithm>

class MyArray{
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

    friend MyArray operator+(const MyArray arr, const int val) {
        MyArray result(arr);
        for (int i = 0; i < result._size; ++i) {
            result[i] += val;
        }
        return result;
    }


    friend MyArray operator+(int val, const MyArray& arr) {
        return arr + val;
    }


    private:
    int* _tab;
    size_t _size;

    public:
    MyArray(){}

    MyArray(size_t);

    MyArray(const MyArray&);

    MyArray(MyArray&&)noexcept;

    int & operator[](size_t);

    const int & operator[](size_t)const;

    void operator++()const;

    void print(std::string)const;

    int size()const;

    MyArray & operator=(const MyArray&);

    void operator+=(const int);

    ~MyArray();





};



#endif