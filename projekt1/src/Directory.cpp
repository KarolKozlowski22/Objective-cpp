#include "Directory.h"

void Directory::operator+=(FileSystemElement* element) {
    _elements.push_back(element);
}

void Directory::print(int depth)const{
    for(int i=0;i<depth;i++){
        std::cout<<"__";
    }
    std::cout<<_name<<std::endl;
    for(auto& element : _elements){
        element->print(depth+1); 
    }
}

File* Directory::operator-=(const std::string & name){
    for(auto it = _elements.begin(); it != _elements.end(); ++it){
        if((*it)->name() == name){
            File* file = dynamic_cast<File*>(*it);
            _elements.erase(it);
            return file;
        }
    }
    return nullptr;
}

void Directory::copy(Directory* other) {
    //_elements.clear();
    _elements.push_back(other->clone());
  
}
Directory::~Directory() {
   for (auto& element : _elements) {
        delete element;
    }
}


FileSystemElement* Directory::clone()const{
    Directory *newDir = new Directory(_name);
    for(auto& element : _elements){
        newDir->_elements.push_back(element->clone());
    }
    return newDir;
}