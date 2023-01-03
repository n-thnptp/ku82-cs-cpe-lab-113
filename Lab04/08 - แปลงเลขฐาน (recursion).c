/*
ให้เขียนโปรแกรม เพื่อแปลงเลขฐานสิบ เป็นเลขฐานสอง โดยใช้ Recursion

ตัวอย่าง
    10
    1010
ตัวอย่าง 2
    123
    1111011
*/

#include <stdio.h>
#include <stdlib.h>

void toBinary(int n) {
    // if n is 0 then return
    if (n == 0) {
        return;
    }
    // if not then call the function (n divide by 2 then store in n)
    toBinary(n/2);
    // print the remainder in base 2
    printf("%d", n%2);
}

int main() {
    char n_str[20];
    int n;
    fgets(n_str, 20, stdin);
    n = atoi(n_str);

    if (n == 0) {
        printf("0");
    } else {
        toBinary(n);
    }
}