#include "FileSystemElement.h"
#pragma once

class File : public FileSystemElement {
    public:
    //basic constructor using main abstract class constructor
    File(const std::string& name) : FileSystemElement(name) {}

    //default destructor
    ~File() = default;

    //function printing name of the file
    void print(int depth=0) const override;

    //overwritten clone function
    FileSystemElement* clone()const override { return new File(*this); }

};
