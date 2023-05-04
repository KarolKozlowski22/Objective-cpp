#include "FileSystemElement.h"
#include "File.h"
#include <vector>
#pragma once


class Directory : public FileSystemElement {
    public:
    //basic constructor using main abstract class constructor
    Directory (const std::string& name) : FileSystemElement(name) {}
    
    //destructor
    ~Directory();	

    //operator pushing file or directory on a vector
    void operator+=(FileSystemElement*);

    //function printing name of the directory and all files and directories in it
    void print(int depth=0)const override;

    //operator removing file or directory from a vector
    File* operator-=(const std::string &);

    //overwritten clone function
    FileSystemElement* clone()const override;

    //copy function using clone in order to make a deep copy
    void copy(Directory*);
       
    private:
    //vector of files and directories
    std::vector<FileSystemElement*> _elements;

};