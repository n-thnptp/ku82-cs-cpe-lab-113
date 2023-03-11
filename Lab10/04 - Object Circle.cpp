/*
กำหนดให้ Class Circle ที่มี attributes ดังนี้
    * จุดศูนย์กลางของวงกลม (center) เป็นข้อมูลชนิด point (struct _point)
    * รัศมีของวงกลม (radius) เป็นข้อมูลชนิด double

และ Object ที่ instantiate จาก Class Circle มี behaviors ดังนี้
    * Constructor เพื่อกำหนดค่า center และ radius ของ object ตามลำดับ
    * คืนค่าพื้นที่ของตนเอง (ชนิด double) ผ่าน method area()
    * คืนค่าระยะทางจากจุดที่รับผ่าน parameter ถึงจุดศูนย์กลางของตนเอง ผ่าน method distanceFromCenter(point pt)
    * คืนค่า 1 เมื่อกำหนดจุดให้ แล้วตรวจสอบแล้วว่าจุดนั้นไม่เกินขอบเขตของวงกลม
      หรือ คืนค่า 0 เมื่อกำหนดจุดให้ แล้วตรวจสอบแล้วว่าจุดนั้นอยู่นอกขอบเขตของวงกลม ผ่าน method contains(point pt)

ให้เขียนโปรแกรมเพื่อรับข้อมูลจุดศูนย์กลาง (บรรทัดที่ 1) และรัศมีของวงกลม (บรรทัดที่ 2) แล้วนำไปสร้าง Object จาก Class Circle
จากนั้นรับจุด P บนพิกัด XY (บรรทัดที่ 3) เพื่อแสดงผลข้อมูลต่อไปนี้โดยใช้ behaviors ของ Object ที่สร้างจาก Class Circle

    * บรรทัดที่ 4 แสดงพื้นที่ของวงกลม (object ที่สร้างขึ้น)
    * บรรทัดที่ 5 แสดงระยะจากจุดศูนย์กลางของวงกลม (object ที่สร้างขึ้น) ถึงจุด P
    * บรรทัดที่ 6 แสดงผลลัพธ์ว่าจุด P อยู่นอกขอบเขตของวงกลม (object ที่สร้างขึ้น) หรือไม่
        - ถ้าเกินขอบเขต ให้แสดงข้อความ This point is not in this circle.
        - ถ้าไม่เกินขอบเขต ให้แสดงข้อความ This circle contains this point.
        
ตัวอย่างโปรแกรม 1
    Center of Circle: 0 0
    Radius of Circle: 5
    Point to Check: 3.3 4.4
    Area of Circle is 78.5398
    Distance from Center to Point (3.3, 4.4) is 5.5
    This point is not in this circle.
ตัวอย่างโปรแกรม 2
    Center of Circle: 7.5 -2.5
    Radius of Circle: 7.2
    Point to Check: 6.9 0
    Area of Circle is 162.86
    Distance from Center to Point (6.9, 0) is 2.57099
    This circle contains this point.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef struct _point {
    double xPosition;
    double yPosition;
} point;

class Circle {
    private:
        point center;
        double radius;

    public:
        Circle(point center, double radius) {
            this->center = center;
            this->radius = radius;
        }

        double area() {
            return M_PI * (pow(radius,2));
        }

        double distanceFromCenter(point pt) {
            return sqrt( pow( (center.xPosition - pt.xPosition), 2) + pow( (center.yPosition - pt.yPosition), 2));
        }

        int contains(point pt) {
            double distance = sqrt( pow( (center.xPosition - pt.xPosition), 2) + pow( (center.yPosition - pt.yPosition), 2));
            if (distance <= radius) {
                return 1;
            } else {
                return 0;
            }
        }
};

int main() {
    double radius;
    point center_input, point_check;

    cout << "Center of Circle: ";
    cin >> center_input.xPosition >> center_input.yPosition;
    
    cout << "Radius of Circle: ";
    cin >> radius;

    cout << "Point to Check: ";
    cin >> point_check.xPosition >> point_check.yPosition;

    Circle circleIn(center_input, radius);
    Circle pt(point_check, radius);

    cout << "Area of Circle is " << circleIn.area() << "\n";
    cout << "Distance from Center to Point (" << point_check.xPosition << ", " << point_check.yPosition << ") is " << circleIn.distanceFromCenter(point_check) << "\n";

    if (circleIn.contains(point_check)) {
        cout << "This circle contains this point." << "\n";
    } else {
        cout << "This point is not in this circle." << "\n";
    }
}