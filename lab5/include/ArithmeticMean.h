#pragma once 
#include "Mean.h"

//ArithmeticMean class that inherits from Mean
class ArithmeticMean : public Mean{


    public:

    //constructor
    ArithmeticMean():Mean("Arithmetic"){}

    //returns the result of the arithmetic mean
    const double result() const override{
        if(_vec.empty()){
            return 0;
        }
        double sum1=0,sum2=0;
        for(auto i : _vec){
            sum2++;
            sum1+=i;
        }
        return sum1/sum2;
    }

    //returns the type of mean
    const string & getType()const override{
        return _type;
    }

};