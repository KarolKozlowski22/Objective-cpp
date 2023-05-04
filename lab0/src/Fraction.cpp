#include "Fraction.h"

Fraction::Fraction(const int numerator, const int denominator){
    _numerator=numerator;
    _denominator=denominator;
}

void Fraction::simplify(){
    const int temp=Maths::gcd(_numerator, _denominator);
    _numerator/=temp;
    _denominator/=temp;
}

Fraction Fraction::operator*(const Fraction & frac)const{
    const int val1=this->_numerator*frac._numerator;
    const int val2=this->_denominator*frac._denominator;
    return Fraction(val1,val2);
}

Fraction & Fraction::operator=(const Fraction & other){
    if(this!=&other){
        _numerator=other._numerator;
        _denominator=other._denominator;
    }
    return *this;
}

Fraction Fraction::operator+(const Fraction & frac)const{
    const int newNumerator=this->_numerator*frac._denominator+frac._numerator*this->_denominator;
    const int newDenominator=this->_denominator*frac._denominator;
    return Fraction(newNumerator, newDenominator);
}

