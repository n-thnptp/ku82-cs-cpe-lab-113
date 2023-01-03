/* 
ให้นิสิตเขียนโปรแกรมรับเลขจำนวนเต็มฐานสิบซึ่งมีค่าตั้งแต่ 0 ถึง 15 และแปลงค่าเป็นเลขฐานสองขนาด 4 บิต แล้วพิมพ์ออกมา

ให้นิสิตเขียนโปรแกรมโดยใช้ bitwise operator และไม่ใช้ if statement

ตัวอย่างข้อมูลส่งออก
    7
    Binary number of 7 is 0111. 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char n_str[5];
    int n;
    fgets(n_str, 5, stdin);
    n = atoi(n_str);

    int n_cal = n;
    int p = 1;
    int result = 0;
    while (n_cal != 0) {
        result += (n_cal % 2) * p;
        p *= 10; // used for selecting digits
        n_cal = n_cal >> 1; // >> = right shift (divide by 2)
    }
    printf("Binary number of %d is %04d.", n, result);
}