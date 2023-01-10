/*
Automorphic numbers คือตัวเลขใด ๆ ที่เมื่อนำมายกกำลังสองแล้วยังคงได้ตัวเลขที่ลงท้ายด้วยตัวเลขที่เอามายกกำลัง

ตัวอย่างเช่น
    1^2 = 1
    5^2 = 25
    6^2 = 36
    25^2 = 625
    76^2 = 5776
จากตัวอย่างข้างต้นจะได้ว่า 1, 5, 6, 25 และ 76 ต่างก็เป็น Automorphic numbers

จงเขียนโปรแกรมที่รับค่า input เป็นเลขจำนวนเต็มบวกใด ๆ โดยโปรแกรมจะทำการตรวจสอบว่าตัวเลขดังกว่าเป็น Automorphic numbers หรือไม่ดังตัวอย่าง

หมายเหตุ input ในชุดทดสอบ มีค่าไม่เกิน 100,000,000
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n, i, last_n, deno;
    long long n_sqr, cal;

    printf("Input n = ");
    scanf("%lld", &n);
    n_sqr = n*n;
    cal = n;
    deno = 10;

    printf("n^2 = %lld\n", n*n);

    // for counting digits of n
    for (i = 0; cal > 0; ++i) {
        cal =  cal / 10;
    }

    // finding denominator for n
    deno = pow(10,i);
    last_n = n_sqr % deno;

    if (last_n == n) {
        printf("Yes. %lld is automorphic number.\n", n);
    } else {
        printf("No. %lld is not automorphic number.\n", n);
    }
}