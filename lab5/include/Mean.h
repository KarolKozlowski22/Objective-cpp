#pragma once 
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::ostream;
using std::cout;


class Mean{

    //friend ostream & operator<<(ostream & out, const Mean & m);
    friend ostream & operator<<(ostream & out, const Mean & m){
        return out << m.getType();
    } 

    protected:

    //_type is a string that will be used to identify the type of mean
    string _type;

    //vector of doubles that will be used to store the values
    vector <double> _vec;

    public:

    //constructor
    Mean(const string & type):_type(type){}

    //destructor
    virtual const string &  getType()const=0;

    //virtual function that will be used to add a value to the vector
    void reset(){_vec.clear();}

    //virtual function that will be used to return the result of the mean
    virtual const double result()const=0;

    //operator that will be used to add a value to the vector
    Mean & operator<<(const double value){
        _vec.push_back(value);
        return *this;
    }

    //operator that will be used to add a value to the vector, const added to avoid adding a value to a const object
    const Mean & operator<<(const double value)const{
        cout<<"cannot add value " << value << " to const\n";
        return *this;
    }

};