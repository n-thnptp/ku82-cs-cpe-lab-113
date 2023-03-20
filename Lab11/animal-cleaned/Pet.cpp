#include "Pet.h"
using namespace std;

Pet::Pet(string pet_name)
    : name(pet_name) {}

string Pet::getName() {
    return name;
}

void Pet::setName(string pet_name) {
    name = pet_name;
}