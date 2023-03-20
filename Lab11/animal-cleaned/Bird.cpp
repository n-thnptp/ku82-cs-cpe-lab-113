#include "Bird.h"
using namespace std;

Bird::Bird(int happiness, int energy, int fullness) 
    : Animal(happiness, energy, fullness) {
        limitStat();
    }

void Bird::fly(int hour) {
    if (hour <= 0) {
        return;
    }
    energy -= hour * 5;
    limitStat();
}

void Bird::sing() {
    happiness += 5;
    limitStat();
}