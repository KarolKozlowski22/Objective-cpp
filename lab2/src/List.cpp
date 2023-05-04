#include "List.h"

void List::insert(const int num){
    _vec.push_back(num);
}

void List::print(const std::string & name)const{
    std::cout<<name<<"[";
    for(int i=0;i<_vec.size();i++){
        std::cout << _vec[i] << " ";
    }
    std::cout<<"]\n";
}

void List::print()const{
    std::cout<<"[ ";
    for(int i=0;i<_vec.size();i++){
        std::cout << _vec[i] << " ";
    }
    std::cout<<"]\n";
}

int & List::operator[](size_t num){
    return _vec[num];
}

const int & List::operator[](size_t num)const{
    return _vec[num];
}


List List::filter(std::function<bool(int)> f){
    List new_List;
    for(int i=0;i<_vec.size();i++){
        if(f(_vec[i])){
            new_List.insert(_vec[i]);
        }
    }
    return new_List;
}

List::List(const List & other){
    for(int i=0;i<other._vec.size();i++){
        _vec.push_back(other._vec[i]);
    }
}

