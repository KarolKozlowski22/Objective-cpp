#include "Fraction.h"
#include <vector>
#pragma once

class FractionArray{

    private:

    //class members
    std::vector<Fraction> m_fractions;

    public:

    //constructors
    FractionArray(size_t size):m_fractions(size){}

    //operator [] in order to access the elements of the array
    Fraction & operator[](size_t index){
        if(index>m_fractions.size()){
            return m_fractions[m_fractions.size()-1];
        }
        else{
            return m_fractions[index];
        }
        
    }

    //operator [] in order to access the elements of the array const version in order to access the elements of a const array
    const Fraction & operator[](size_t index)const{
        if(index>m_fractions.size()){
            return m_fractions[m_fractions.size()-1];
        }
        else{
            return m_fractions[index];
        }
    }

};