// จงเขียนโปรแกรมเพื่อคำนวณค่าปริมาตร (volume) ของทรงกลม ในรูปแบบทศนิยม 2 ตำแหน่ง โดยค่ารัศมี (ตัวแปร radius) เป็นจำนวนจริง

// โดยใช้การคำนวณจากสูตร
// volume = 4/3 * π * radius^3
// ตัวอย่างผลลัพธ์ เมื่อตัวแปร radius มีค่า 1.5

// The volume of this sphere is 14.14

#include <stdio.h>
#include <stdlib.h>

// กำหนดค่าคงที่ PI = 22.0/7
#define PI 22.0/7

int main() {
    float radius = 1.5;
    float vol = 4.0/3 * PI * pow(radius, 3.0);

    printf("The volume of this sphere is %.2f", vol);
    return 0;
}