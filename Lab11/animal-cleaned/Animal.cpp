#include "Animal.h"
using namespace std;

// member list initialization
/*
class MyClass {
public:
    int x;
    MyClass(int my_x) : x(my_x) {}
}
*/
Animal::Animal(int happiness, int energy, int fullness)
    : happiness(happiness) , energy(energy) , fullness(fullness) {
        limitStat();
    }

// or
// Animal::Animal(int happiness, int energy, int fullness) {
//     this->happiness = happiness;
//     this->energy = energy;
//     this->fullness = fullness;
//     limitStat();
// }

void Animal::limitStat() { 
    if (happiness > MAX_HAPPINESS) {
        happiness = 100;
    } else if (happiness < 0) {
        happiness = 0;
    }

    if (fullness > MAX_FULLNESS) {
        fullness = 100;
    } else if (fullness < 0) {
        fullness = 0;
    }

    if (energy > MAX_ENERGY) {
        energy = 100;
    } else if (energy < 0) {
        energy = 0;
    }
}
int Animal::getHappiness() {
    return happiness;
}
int Animal::getEnergy() {
    return energy;
}
int Animal::getFullness() {
    return fullness;
}

void Animal::eat(int food) {
    if (food <= 0) {
        return;
    }
    fullness += food;
    if (fullness > MAX_FULLNESS) {
        happiness -= 10;
    }
    limitStat();
}
void Animal::play(int hour) {
    if (hour <= 0) {
        return;
    }

    if (energy <= 0 || fullness <= 0) {
        return;
    }
    energy -= hour * 10;
    fullness -= hour * 20;
    happiness += hour * 5;
    limitStat();
}
void Animal::sleep(int hour) {
    if (hour <= 0) {
        return;
    }
    energy += hour * 10;
    fullness -= hour * 10;
    limitStat();
}