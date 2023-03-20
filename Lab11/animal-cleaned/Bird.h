#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
using namespace std;

class Bird : public Animal {
public:
    Bird(int, int, int);
    void fly(int);
    void sing();
};

#endif