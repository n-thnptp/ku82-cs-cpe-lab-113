/*
Implement a class Time with three attributes: hour, minute, second. All of them are integer.
Write mutator (set) and accessor (get) methods of these attributes. The constructors and other methods are listed below.

    *               Time(int hour, int minute, int second)	    Construct and initialize Time object
    *               Time(int duration)	                        Construct and initialize Time object. The duration parameter has second unit
    * int           getDuration()	                            return duration in seconds
    * Time          add(Time other)	                            return Time that is the result of adding this Time and other Time together
    * int           subtract(Time other)	                    return duration in seconds between this Time and other Time
    * int           equals(Time other)	                        return 1 if this Time and other Time are the same; otherwise, return 0
    * string        toString()	                                return String of hour:minute:second, e.g., "09:08:04"

Note that
Example of subtract the time :
( a ) -> 02:02:02
( b ) -> 01:01:01
(a) - (b) => 3661 sec.
(b) - (a) => 82739 sec.

*** ในข้อนี้ให้ใช้ stringstream จาก library sstream มาช่วย ***
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
            stringstream ss;
            ss << setfill('0') << setw(2) << this->hour << ":"
            << setfill('0') << setw(2) << this->minute << ":"
            << setfill('0') << setw(2) << this->second;
            return ss.str();
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