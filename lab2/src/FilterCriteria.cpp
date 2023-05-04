#include "FilterCriteria.h"

void FilterCriteria::add(std::function<bool(int)>f){
    _vec.push_back(f);
}

int FilterCriteria::size()const{
    return _vec.size();
}

const std::function<bool(int)> & FilterCriteria::get(size_t index)const{
    return _vec[index];
}