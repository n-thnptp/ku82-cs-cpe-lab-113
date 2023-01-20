/*
ให้เติมส่วนของโปรแกรมที่มีการเก็บข้อความ "Computer Programming"
และให้โปรแกรมแสดงข้อความตามตัวอย่าง โดยใช้หลักการของ pointer

Sample Output
    Computer Programming
    ter Programming
    Programming
*/

#include <stdio.h>

int main() {
    char item[25] = "Computer Programming";
    char *a1 = item, *a2;

    printf("%s\n", a1);
    a2 = a1 + 5;
    printf("%s\n", a2);
    a2 = a2 + 3;
    printf("%s\n", a2);
    return 0;
}