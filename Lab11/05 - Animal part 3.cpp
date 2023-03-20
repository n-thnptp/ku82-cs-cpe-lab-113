/*
Class Pet inherit Animal

จงเขียน Implementation ของ Class Animal ซึ่งเป็นคลาสแทนสัตว์ และ Class Pet ซึ่งเป็นคลาสแทนสัตว์เลี้ยง

Animal ประกอบด้วย attributes ดังนี้
    * happiness คือ ค่าความสุข มีค่าอยู่ในช่วงตั้งแต่ 0 ถึง 100
    * energy คือ ค่าพลังงาน มีค่าอยู่ในช่วงตั้งแต่ 0 ถึง 100
    * fullness คือ ค่าความอิ่ม มีค่าอยู่ในช่วงตั้งแต่ 0 ถึง 100
Animal มี methods ต่อไปนี้
    * Constructor ที่กำหนดค่าเริ่มต้นของ happiness, energy และ fullness ตามลำดับ
    * limitStat() ใช้ควบคุมค่า happiness, energy และ fullness ไม่ให้เกินขอบเขตของช่วง 0 ถึง 100
    * getter ของ attributes ทั้งสาม
    * eat(int food) สัตว์มีพฤติกรรมการกินอาหาร โดยรับค่าพลังงานของอาหาร มาเพิ่ม fullness ตามจำนวนค่าพลังงานอาหารที่รับเข้ามา แต่ถ้าฝืนกินจนเกินค่าความอิ่มสูงสุด จะทำให้ความสุขลดลง 10 หน่วยด้วย
    * play(int hour) สัตว์มีพฤติกรรมการเล่น โดยแต่ละครั้งสัตว์จะเล่นเป็นจำนวนชั่วโมงติดต่อกัน ซึ่งแต่ละครั้งจะทำให้พลังงานลดลง 10 หน่วยต่อชั่วโมง ทำให้ความอิ่มลดลง 20 หน่วยต่อชั่วโมง
      แต่ทำให้ค่าความสุขเพิ่มขึ้น 5 หน่วยต่อชั่วโมง แต่หากในครั้งนั้น ค่าพลังงาน หรือค่าความอิ่ม เป็น 0 ก็จะไม่เล่น
    * sleep(int hour) สัตว์มีพฤติกรรมการนอน โดยแต่ละครั้งสัตว์จะนอนเป็นจำนวนชั่วโมงติดต่อกัน ซึ่งแต่ละครั้งจะทำให้ค่าพลังงานเพิ่มขึ้น 10 หน่วยต่อชั่วโมง และค่าความอิ่มลดลง 10 หน่วยต่อชั่วโมง

Pet ประกอบด้วย attributes ที่สืบทอดจากสัตว์ และมี attribute ต่อไปนี้เพิ่มจากสัตว์
    * name ชื่อของสัตว์ เนื่องจากเจ้าของสัตว์เลี้ยง มักจะตั้งชื่อให้สัตว์เลี้ยงด้วย

Pet มีพฤติกรรมเดียวกับสัตว์ และเพิ่มพฤติกรรมต่อไปนี้
    * Constructor ของ Pet จะระบุ name, happiness, energy และ fullness เป็นค่าเริ่มต้น ตามลำดับ
    * getter และ setter ของ name
*/

#include <iostream>
using namespace std;

class Animal {
protected:
    int happiness;
    int energy;
    int fullness;
    const int MAX_HAPPINESS = 100;
    const int MAX_ENERGY = 100;
    const int MAX_FULLNESS = 100;
    void limitStat();
public:
    Animal(int, int, int);
    int getHappiness();
    int getEnergy();
    int getFullness();
    void eat(int);
    void play(int);
    void sleep(int);
};

class Pet : public Animal {
private:
    string name;
public:
    Pet(string, int, int, int);
    string getName();
    void setName(string);
};

Animal::Animal(int happiness, int energy, int fullness)
    : happiness(happiness) , energy(energy) , fullness(fullness) {
        limitStat();
    }

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

// starts here
Pet::Pet(string pet_name, int happiness, int energy, int fullness)
    : name(pet_name), Animal(happiness, energy, fullness) {}

string Pet::getName() {
    return name;
}

void Pet::setName(string pet_name) {
    name = pet_name;
}

int main() {
    // happiness, energy, fullness
    Pet pet1("wowee", 15, 100, 97);
    cout << "Name: " << pet1.getName() << "\n";
    cout << "Happiness: " << pet1.getHappiness() << "\n"
         << "Energy: " << pet1.getEnergy() << "\n"
         << "Fullness: " << pet1.getFullness();
}