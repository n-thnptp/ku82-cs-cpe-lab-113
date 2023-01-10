/*
จงเขียนโปรแกรมเพื่อรับจํานวนเต็มบวกมาหนึ่งจํานวน และพิมพ์สามเหลี่ยมตามขนาดที่ผู้ใช้กําหนดดังตัวอย่างด้านล่าง

Output :                | Output 3 : 
    Enter n: 1          |   Enter n: 2
    -                   |   -
​                        |   -x
Output 2 :              |   -
    Enter n: 10         |
    -                   |
    -x                  |
    -x-                 |
    -x-x                |
    -x-x-               |
    -x-x-x              |
    -x-x-x-             |
    -x-x-x-x            |
    -x-x-x-x-           |
    -x-x-x-x-x          |
    -x-x-x-x-           |
    -x-x-x-x            |
    -x-x-x-             |
    -x-x-x              |
    -x-x-               |
    -x-x                |
    -x-                 |
    -x                  |
    -                   |
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, rowLength = 1;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i=0; i < (n*2)-1; ++i) {
        for (int j=0; j < rowLength; ++j) {
            // increase rowlength by 1 but do not pass the n length
            if (j % 2 == 0) {
                printf("-");
            } else {
                printf("x");
            }
        }

        if (rowLength < n && i <= n-1) {
            rowLength += 1;
        } else if (i >= n-1) {
            rowLength -= 1;
        }
        printf("\n");
    }
}