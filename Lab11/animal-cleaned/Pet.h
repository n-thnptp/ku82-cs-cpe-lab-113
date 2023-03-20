#ifndef PET_H
#define PET_H

#include <iostream>
using namespace std;

class Pet {
protected:
    string name;
public:
    Pet(string);
    string getName();
    void setName(string);
};

#endif