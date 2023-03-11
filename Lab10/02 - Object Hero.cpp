/*
โปรแกรมมี class ชื่อ Hero ที่ประกอบด้วย data member ต่อไปนี้
    * name เก็บข้อมูลชื่อของ Hero
    * level เก็บข้อมูลเลเวลของ Hero (เป็นจำนวนเต็มบวก)
class Hero มี member function ดังนี้
    * constructor ที่รับ Parameter 2 ค่า คือ ชื่อและเลเวลตามลำดับ
    * getter ของชื่อ
    * getter ของเลเวล
ให้เขียนโปรแกรมใน main function เพื่อรับข้อมูลชื่อ และเลเวล มาสร้าง object hero จาก class Hero
และให้แสดงชื่อและเลเวลจาก object ที่สร้าง โดยเว้นวรรคระหว่างชื่อและเลเวล

ตัวอย่างโปรแกรม
    HeroName 10
    HeroName 10
*/

#include <iostream>
#include <string>
using namespace std;

class Hero {
    private:
        string name;
        int level;
    public:
        Hero(string name, int level) {
            this->name = name;
            this->level = level;
        }

        string getName() {
            return name;
        }

        int getLevel() {
            return level;
        }    
};

int main() {
    string name;
    int lvl;
    cin >> name >> lvl;
    Hero new_hero(name, lvl);

    cout << new_hero.getName() << " " << new_hero.getLevel() << endl;
}