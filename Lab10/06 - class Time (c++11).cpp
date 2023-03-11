/*
Time (c++11)
    *** เปลี่ยนแค่ function toString()

    ในข้อนี้ให้ใช้ฟังก์ชัน to_string() ใน library string ตามมาตรฐาน c++11 มาช่วย
*/

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Time {
    private:
        int hour;
        int minute;
        int second;
    public:
        // getter
        int getHour() {
            return this->hour;
        }
        int getMinute() {
            return this->minute;
        }
        int getSecond() {
            return this->second;
        }

        // constructor
        Time(int hour, int minute, int second) {
            // for seconds over 59
            if (second > 59) {
                minute += second % 60;
                second -= (second % 60) * 60;
            }

            // for minutes over 59
            if (minute > 59) {
                hour += minute / 60;
                minute = minute % 60;
            }

            this->second = second;
            this->minute = minute;
            this->hour = hour % 24;
        }

        Time(int duration) {
            this->hour = duration / 3600;
            this->minute = duration % 3600 / 60;
            this->second = duration % 3600 % 60;
            while (this->hour >= 24) {
                this->hour -= 24;
            }
        }

        // methods
        int getDuration() {
            return (this->hour)*3600 + (this->minute)*60 + this->second;
        }

        Time add(Time other) {
            return other.getDuration() + getDuration();
        }

        int subtract(Time other) {
            if (other.getDuration() > getDuration()) {
                // 86400 = 24 hours
                return 86400 - other.getDuration() + getDuration();
            } else {
                return getDuration() - other.getDuration();
            }
        }

        int equals(Time other) {
            if (getDuration() == other.getDuration()) {
                return 1;
            } else {
                return 0;
            }
        }

        string toString() {
            string output;
            // if either hour, minute, or second is a single digit then add "0" to string "output" first
            if (this->hour <= 9) {
                output += "0";
            }
            output += to_string(this->hour) + ":";

            if (this->minute <= 9) {
                output += "0";
            }
            output += to_string(this->minute) + ":";

            if (this->second <= 9) {
                output += "0";
            }
            output += to_string(this->second);

            return output;
        }
};

int main() {
    Time timeIn(45,121,59);
    Time other(00,00,00);

    cout << "Time: " << timeIn.toString() << "\n";
    cout << "duration: " << timeIn.getDuration() << "\n";
    cout << "( a ) -> " << timeIn.toString() << "\n\n";

    cout << "Other time: " << other.toString() << "\n";
    cout << "duration: " << other.getDuration() << "\n";
    cout << "( b ) -> " << other.toString() << "\n\n";

    cout << "( a ) - ( b ) -> " << timeIn.subtract(other) << " sec.\n";
    cout << "( b ) - ( a ) -> " << other.subtract(timeIn) << " sec.\n";    
    cout << "\n" << "is a = b ?" << "\n";
    if (timeIn.equals(other)) {
        cout << "yes";
    } else {
        cout << "no";
    }

}