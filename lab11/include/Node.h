#include <iostream>
#pragma once


using std::cout;
template <typename T>
class Node{

    private:
    T _data;
    Node* _next;

    public:

    //basic constructor
    Node(const T & data):_data(data),_next(nullptr){}

    //copy constructor
    Node(const Node & other):_data(other._data),_next(nullptr){}

    //data geter
    T getVal()const{
        return _data;
    }

    //next getter
    Node* getNext(){
        return _next;
    }

    //next setter
    void setNext(Node<T>* newNode){
        _next=newNode;
    }

    //function printing the data
    void print()const{
        cout << _data;
    }

    //copy assignment operator overloaded
    Node & operator=(const Node & other){
        if(this!=&other){
            _data=other._data;
            _next=other._next;
            return *this;
        }
        return *this;
    }

};