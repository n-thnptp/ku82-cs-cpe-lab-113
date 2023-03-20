/*
จงเขียนคลาส MusicPlaylist เพื่อแทนเพลย์ลิสต์ของเพลง ซึ่งมีพฤติกรรมดังนี้
    * สามารถเก็บเพลงได้มากถึง 20 เพลง
    * เพิ่มเพลงลงเพลย์ลิสต์ ผ่าน method add(string)
    * เลือกลำดับของเพลงที่ต้องการจะฟังจากเพลย์ลิสต์ ด้วย method setCurrentTrack(int)
    * เล่นเพลงที่เลือกจากลำดับของเพลง ด้วย method play() ในที่นี้ให้ return string ของเพลงที่ตรงกับลำดับที่เลือก
*/

#include <iostream>
#include <string>
using namespace std;

class MusicPlaylist {
    private:
        string list[20] = {};
        int i;
        int addIndex;
    public:
        // setter
        void setCurrentTrack(int current) {
            this->i = current;
        }

        // methods
        void add(string str_input) {
            list[addIndex] = str_input;
            this->addIndex += 1;
        }

        string play() {
            return list[this->i-1];    
        }
};

int main()
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(1);
    cout << mp.play() << endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You
}