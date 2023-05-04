#include <iostream>
#include "Maths.h"
#pragma once 

class Fraction{
    private:
    int _numerator;
    int _denominator;
    public:
    Fraction(){};
    Fraction(const int, const int);
    operator double()const{
        return static_cast<double>(_numerator)/static_cast<double>(_denominator);
    }
    void simplify();
    Fraction operator*(const Fraction &)const;
    Fraction & operator=(const Fraction & );
    Fraction operator+(const Fraction &)const;
    friend Fraction operator*(const int num, const Fraction & frac){
        return Fraction(num*frac._numerator, frac._denominator);
    }
    friend std::ostream& operator<<(std::ostream & out, const Fraction & frac){
        return out << frac._numerator << "/" << frac._denominator;
    }



};