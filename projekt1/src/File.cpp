#include "File.h"

void File::print(int depth)const{
    for(int i=0;i<depth;i++){
        std::cout<<"__";
    }
    std::cout<<_name<<std::endl;

}