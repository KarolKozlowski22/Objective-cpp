#pragma once

class DivisibleBy{

    public:

    //basic constructor 
    DivisibleBy(const int divisor):_divisor(divisor){}

    //overloaded operator() returning true if the given int is divisible by the divisor
    bool operator()(const int);

    private:

    //divisor
    int _divisor;

};

class GreaterThan{

    public:

    //basic constructor.
    GreaterThan(const int threshold):_threshold(threshold){}

    //overloaded operator() returning true if the given int is greater than the threshold.
    bool operator()(const int);

    private:

    //threshold
    int _threshold;
};