#ifndef EXEPT_H
#define EXEPT_H

#include <string>

class Exept{
    std::string x;
public:
    Exept(std::string xx);
    Exept(){};
    
    std::string what();
};


#endif
