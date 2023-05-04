#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<functional>

class List{

    public:

    //basic constructor.
    List(){}

    //method inserting an int at the end of the vector.
    void insert(const int);

    //method printing the vector.
    void print(const std::string&)const;

    //method printing the vector.
    void print()const;

    //overloaded operator[] returning the int at the given index.
    int & operator[](size_t);

    //overloaded operator[] returning the int at the given index.
    const int & operator[](size_t)const;

    //method filtering the vector with the given function.
    List filter(std::function <bool(int)>);

    //method List returning a new List containing the elements of the current List that are divisible by the given int.
    List(const List&);
   
    private:

    //vector of ints.
    std::vector<int> _vec;




};