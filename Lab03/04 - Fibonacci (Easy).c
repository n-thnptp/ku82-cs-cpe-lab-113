// พิจารณาลำดับต่อไปนี้

//  1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... 
// ลำดับดังกล่าวมีชื่อเรียกว่า "ลำดับฟีโบนัชชี (Fibonacci's sequence" !!
// คุณอาจทราบมาว่าลำดับที่ n ของฟีโบนัชชีหาได้จาก F(n) = F(n-2) + F(n-1) โดย F(0) = 0 และ F(1) = 1
// แต่ลำดับที่ n ของฟีโบนัชชี สามารถคำนวณจากสูตรต่อไปนี้

//        (1 + √5)^n - (1 - √5)^n
//  Fn = -------------------------
//                2^n(√5)

// จงเขียนฟังก์ชัน int fibo(int n) เพื่อคำนวณเลขฟีโบนัชชีลำดับที่ n
// และใช้ฟังก์ชันดังกล่าว แสดงเลขฟีโบนัชชีลำดับที่ 0 ถึงลำดับที่ n เมื่อ n คือข้อมูลนำเข้า ซึ่งเป็นจำนวนเต็ม และ n >= 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibo(int n) {
    int cal;
    cal = (pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * (sqrt(5)));
    printf("F(%d) = %d\n", n, cal);
}

int main() {
    char input_n[5];
    int n, i;

    fgets(input_n, 5, stdin);

    n = atoi(input_n);

    for (i = 0; i <= n; ++i) {
        if (i == 0) {
            printf("F(%d) = 0\n", i);
        } else if (i == 1) {
            printf("F(%d) = 1\n", i);
        } else {
            fibo(i);
        }
    }
}