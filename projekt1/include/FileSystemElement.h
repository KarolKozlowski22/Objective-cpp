#include <iostream>
#pragma once 

//basic abstract class
class FileSystemElement {

    public:
    //baisc constructor
    FileSystemElement(const std::string& name) : _name(name) {}

    //virtual destructor considering polymorphism
    virtual ~FileSystemElement() = default;

    //pure virtual function
    virtual void print(int depth=0) const = 0;

    //pure virtual function 
    virtual FileSystemElement* clone()const=0;

    //virtual function renaming name of the file or directory 
    virtual void rename(const std::string& name) { _name = name; }

    //virtual function returning name of the file or directory
    virtual const std::string & name() const { return _name; }

    protected:
    //name of the file or directory
    std::string _name;

};