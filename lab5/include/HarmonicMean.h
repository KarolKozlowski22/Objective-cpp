#pragma once 
#include "Mean.h"

//HarmonicMean class that inherits from Mean
class HarmonicMean : public Mean{

    public:

    //constructor
    HarmonicMean():Mean("Harmonic"){}

    //returns the result of the harmonic mean
    const double result()const override{
        if(_vec.empty()){
            return 0;
        }
        double sum1=0,sum2=0;
        for(auto i : _vec){
            if(i==0){
                return 0;
            }
            sum1++;
            sum2+=1/i;
        }
        return sum1/sum2;
    }

    //returns the type of mean
    const string & getType()const override{
        return _type;
    }

};