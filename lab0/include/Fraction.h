#include <iostream>
#include "Maths.h"
#pragma once 

class Fraction{

    private:
    //class members
    int _numerator;
    int _denominator;

    public:
    //constructors
    Fraction(){};
    Fraction(const int, const int);

    //operator double in order to convert to double
    operator double()const{
        return static_cast<double>(_numerator)/static_cast<double>(_denominator);
    }

    //void function simplify in order to simplify the fraction
    void simplify();

    //operator * in order to multiply two fractions
    Fraction operator*(const Fraction &)const;

    //operator = in order to assign a fraction to another
    Fraction & operator=(const Fraction & );

    //operator + in order to add two fractions
    Fraction operator+(const Fraction &)const;

    //operator * in order to multiply a fraction by an integer
    friend Fraction operator*(const int num, const Fraction & frac){
        return Fraction(num*frac._numerator, frac._denominator);
    }

    //operator << in order to print a fraction
    friend std::ostream& operator<<(std::ostream & out, const Fraction & frac){
        return out << frac._numerator << "/" << frac._denominator;
    }



};