/* 
ให้เขียนโปรแกรมเพื่อรับเลขจำนวนเต็มไม่เกินเก้าหลัก (n) และเลขจำนวนเต็มหนึ่งหลัก (x โดยที่ 0 <= x <= 9) แล้วให้นับจำนวนของ x ที่มีใน n เช่น

ตัวอย่างที่ 1                                       ตัวอย่างที่ 3
    346574390                                   |   23450
    3                                           |   0
    There are 2 "3"(s) in 346574390.            |   There is only 1 "0" in 23450.

ตัวอย่างที่ 2                                       ตัวอย่างที่ 4
    454578                                      |   111111111
    6                                           |   1
    There is no "6" in 454578.                  |   There are 9 "1"(s) in 111111111.
*/

#include <stdio.h>
#include <stdlib.h>

int count_target(int n, int target) {
    int store = 0, count_n = 0;
    for (int i=0; n > 0; ++i) {
        store = n % 10;
        if (store == target) {
            count_n += 1;
        }
        n /= 10;
    }
    return count_n;
}

int main() {
    char input_n[12], input_x[2];
    fgets(input_n, 12, stdin);
    fgets(input_x, 2, stdin);

    int n;
    int x, count;

    n = atoi(input_n);
    x = atoi(input_x);

    count = count_target(n, x);

    // Display output in separate cases
    //
    if (count <= 0) {
        printf("There is no \"%d\" in %d.\n", x, n);
    } else if (count == 1) {
        printf("There is only 1 \"%d\" in %d.\n", x, n);
    } else {
        printf("There are %d \"%d\"(s) in %d.\n", count, x, n);
    }
    return 0;
}