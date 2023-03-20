#include "OwnedBird.h"

OwnedBird::OwnedBird(string pet_name, int happiness, int energy, int fullness)
    : Bird(happiness, energy, fullness), Pet(pet_name) {}