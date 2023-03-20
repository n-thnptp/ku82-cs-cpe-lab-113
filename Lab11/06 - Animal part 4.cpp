/*
Class OwnedBird multiple inheritance

จงเขียน Implementation ของ Class Animal ซึ่งเป็นคลาสแทนสัตว์
Implementation ของ Class Bird ซึ่งเป็นคลาสของนกที่สืบทอดคุณสมบัติและพฤติกรรมของสัตว์
Implementation ของ Class Pet ซึ่งเป็นคลาสของความเป็นสัตว์เลี้ยง (ตัดการสืบทอดจากสัตว์ออกไป)
และ Implementation ของ Class OwnedBird ซึ่งเป็นคลาสของนกที่มีเจ้าของ คลาสนี้สืบทอดคุณสมบัติและพฤติกรรมจากนก และ ความเป็นสัตว์เลี้ยง

Animal ประกอบด้วย attributes ดังนี้
    * happiness คือ ค่าความสุข มีค่าอยู่ในช่วงตั้งแต่ 0 ถึง 100
    * energy คือ ค่าพลังงาน มีค่าอยู่ในช่วงตั้งแต่ 0 ถึง 100
    * fullness คือ ค่าความอิ่ม มีค่าอยู่ในช่วงตั้งแต่ 0 ถึง 100

Animal มี methods ต่อไปนี้
    * Constructor ที่กำหนดค่าเริ่มต้นของ happiness, energy และ fullness ตามลำดับ
    * limitStat() ใช้ควบคุมค่า happiness, energy และ fullness ไม่ให้เกินขอบเขตของช่วง 0 ถึง 100
    * getter ของ attributes ทั้งสาม
    * eat(int food) สัตว์มีพฤติกรรมการกินอาหาร โดยรับค่าพลังงานของอาหาร มาเพิ่ม fullness ตามจำนวนค่าพลังงานอาหารที่รับเข้ามา แต่ถ้าฝืนกินจนเกินค่าความอิ่มสูงสุด จะทำให้ความสุขลดลง 10 หน่วยด้วย
    * play(int hour) สัตว์มีพฤติกรรมการเล่น โดยแต่ละครั้งสัตว์จะเล่นเป็นจำนวนชั่วโมงติดต่อกัน ซึ่งแต่ละครั้งจะทำให้พลังงานลดลง 10 หน่วยต่อชั่วโมง ทำให้ความอิ่มลดลง 20 หน่วยต่อชั่วโมง แต่ทำให้ค่าความสุขเพิ่มขึ้น 5 หน่วยต่อชั่วโมง แต่หากในครั้งนั้น ค่าพลังงาน หรือค่าความอิ่ม เป็น 0 ก็จะไม่เล่น
    * sleep(int hour) สัตว์มีพฤติกรรมการนอน โดยแต่ละครั้งสัตว์จะนอนเป็นจำนวนชั่วโมงติดต่อกัน ซึ่งแต่ละครั้งจะทำให้ค่าพลังงานเพิ่มขึ้น 10 หน่วยต่อชั่วโมง และค่าความอิ่มลดลง 10 หน่วยต่อชั่วโมง

Bird มี attributes และ methods ที่สืบทอดจาก Animal และมี methods เพิ่มเติมดังนี้
    * fly(int hour) นกมีพฤติกรรมการบิน โดยการบินแต่ละครั้งจะบินเป็นจำนวนชั่วโมงติดต่อกัน ซึ่งแต่ละครั้งจะทำให้ค่าพลังงานลดลง 5 หน่วยต่อชั่วโมง
    * sing() นกมีพฤติกรรมการร้องเพลง โดยการร้องแต่ละครั้งจะทำให้ความสุขเพิ่มขึ้น 5 หน่วย

Pet ประกอบด้วย attribute name
    * name ชื่อของสัตว์ เนื่องจากเจ้าของสัตว์เลี้ยง มักจะตั้งชื่อให้สัตว์เลี้ยงด้วย

Pet มีพฤติกรรมต่อไปนี้
    * Constructor ของ Pet จะระบุ name เป็นค่าเริ่มต้น
    * getter และ setter ของ name

OwnedBird สืบทอด attributes, methods จาก Bird และ Pet และมีข้อกำหนดของ Constructor ดังนี้
    * Constructor จะระบุ name, happiness, energy และ fullness เป็นค่าเริ่มต้น ตามลำดับ
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

class Bird : public Animal {
public:
    Bird(int, int, int);
    void fly(int);
    void sing();
};

class Pet {
protected:
    string name;
public:
    Pet(string);
    string getName();
    void setName(string);
};

class OwnedBird : public Bird, public Pet {
public:
    OwnedBird(string, int, int, int);
};

// constructor, methods for class Animal (base class)
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

// constructor, methods for class Pet
Pet::Pet(string pet_name)
    : name(pet_name) {}

string Pet::getName() {
    return name;
}

void Pet::setName(string pet_name) {
    name = pet_name;
}

// constructor, methods for class Bird (inherits from class Animal)
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

// constructor for class OwnedBird (inherits from class Pet and class Bird)
OwnedBird::OwnedBird(string pet_name, int happiness, int energy, int fullness)
    : Bird(happiness, energy, fullness), Pet(pet_name) {}

int main()
{
    char action;
    int hour;
    int happiness, energy, fullness;
    cin >> happiness >> energy >> fullness;
    OwnedBird animal("Dobby", happiness, energy, fullness);
    while (1) {
        cin >> action;
        if (action == 'q') break;
        cin >> hour;
        switch (action) {
            case 'e':
                animal.eat(hour);
                break;
            case 'p':
                animal.play(hour);
                break;
            case 's':
                animal.sleep(hour);
                break;
            case 'f':
                animal.fly(hour);
                break;
            case 'i':
                for (int i = 0; i < hour; i++)
                    animal.sing();
                break;
            case 'n':
                if (hour < 5)
                    animal.setName("Debby");
                else
                    animal.setName("Shogun");
                break;
        }
    }

    cout << "Name: " << animal.getName() << "\n";
    cout << "Happiness: " << animal.getHappiness() << "\n"
         << "Energy: " << animal.getEnergy() << "\n"
         << "Fullness: " << animal.getFullness();
}
