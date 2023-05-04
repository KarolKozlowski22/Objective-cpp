#include "MyArray.h"


void MyArray::print(std::string name)const{
    std::cout<<name<<" = ";
    if(_tab!=nullptr){
        
        for(int i=0;i<_size;i++){
            if(i==0){
                std::cout<<"["<<_tab[i]<<", ";
            }
            else if(i!=0&&i<_size-1){
                std::cout<<_tab[i]<<", ";
            }
            else{
                std::cout<<_tab[i]<< "]";
            }
         }
        std::cout<<"\n";
    }
    else{
        std::cout<<"[]"<<"\n";
    }
   
}

MyArray::MyArray(size_t size){
    _size=size;
    _tab=new int [_size];
}

int & MyArray::operator[](size_t index){
    if(index>_size){
        return _tab[_size-1];
    }
    return _tab[index];
}

const int & MyArray::operator[](size_t index)const{
    if(index>_size){
        return _tab[_size-1];
    }
    return _tab[index];
}

int MyArray::size()const{
    return _size;
}

void MyArray::operator++()const{
    for(int i=0;i<_size;i++){
        _tab[i]++;
    }
}

MyArray::MyArray(const MyArray & other){
    _size=other._size;
    _tab=new int[_size];
    for(int i=0;i<_size;i++){
        _tab[i]=other._tab[i];
    }
}

MyArray & MyArray::operator=(const MyArray & other){
    if(this!=&other){
        delete [] _tab;
        _size=other._size;
        _tab=new int [_size];
        std::copy(other._tab,other._tab+_size,_tab);
        return *this;
    }
    return *this;
}

void MyArray::operator+=(const int num){
    for(int i=0;i<_size;i++){
        _tab[i]+=num;
    }
}



MyArray::~MyArray(){
    std::cout<<"Usuwam tablice"<<"\n";
}

MyArray::MyArray(MyArray && other) noexcept{
    _tab=other._tab;
    _size=other._size;
    other._tab=nullptr;
    other._size=0;
}