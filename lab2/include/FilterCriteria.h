#pragma once
#include <vector>
#include <functional>


class FilterCriteria{

    public:

    //basic constructor.

    FilterCriteria(){}

    //method adding a function to the vector.

    void add(std::function<bool(int)>);

    //method returning the size of the vector.
    int size()const;

    //method returning the function at the given index.
    const std::function<bool(int)> & get(size_t)const;
    
    private:

    //vector of functions.
    std::vector<std::function<bool(int)>> _vec;


};