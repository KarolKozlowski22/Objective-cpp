#include "Fraction.h"
#include <vector>
#pragma once

class FractionArray{
    private:
    std::vector<Fraction> m_fractions;
    public:
    FractionArray(size_t size):m_fractions(size){}
    Fraction & operator[](size_t index){
        if(index>m_fractions.size()){
            return m_fractions[m_fractions.size()-1];
        }
        else{
            return m_fractions[index];
        }
        
    }
    const Fraction & operator[](size_t index)const{
        if(index>m_fractions.size()){
            return m_fractions[m_fractions.size()-1];
        }
        else{
            return m_fractions[index];
        }
    }

};