#ifndef OWNEDBIRD_H
#define OWNEDBIRD_H

#include "Bird.h"
#include "Pet.h"
#include <iostream>

class OwnedBird : public Bird, public Pet {
public:
    OwnedBird(string, int, int, int);
};

#endif