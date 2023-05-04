#include "SmartPtr.h"

void SmartPtr::release(){
    if(_refCount!=nullptr){
        --(*_refCount);
        if(*_refCount==0){
            delete _ptr;
            delete _refCount;
        }
    }
    _ptr=nullptr;
    _refCount=nullptr;
}

SmartPtr & SmartPtr::operator=(const SmartPtr & other){
    if(this!=&other){
        release();
        _ptr=other._ptr;
        _refCount=other._refCount;
        ++(*_refCount);
        return* this;
    }
    return* this;
}

SmartPtr & SmartPtr::operator=(SmartPtr && other){
    if(this!=&other){
        release();
        _ptr=other._ptr;
        _refCount=other._refCount;
        other.release();
        return* this;
    }
    return* this;
}