#pragma once
#include <string>
class NewException{
    std::string place;
    std::string base = "Could not load ";
public:
    NewException(std :: string temp) {
        place = temp;
    }
    std::string what(){
        return base+place;
    }
};

