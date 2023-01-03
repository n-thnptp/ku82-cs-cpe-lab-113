/* 
เขียนโปรแกรมภาษาซี ที่รับเลขจำนวนเต็ม 2 จำนวน เช่น x กับ y (โดย x และ y มีค่าอย่างต่ำเป็น 4) แล้วแสดงสี่เหลี่ยมขนมเปียกปูนที่ยาว x และสูง y ที่มีลักษณะเอียงตามรูป ตัวอย่างเช่น

Output :
6
4
******          space = 0
 *    *         4
  *    *        4
   ******       0
   
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char horizontal[6], vertical[6];
    int h = 0, v = 0, s = 0, front = 0;
    
    fgets(horizontal, 6, stdin);
    fgets(vertical, 6, stdin);

    h = atoi(horizontal);
    v = atoi(vertical);

    for (int i=0; i < v; ++i) {
        for (int j=0; j < h; ++j) {
            if (i == 0 || (i+1 == v && j >= v)) {
                printf("*");
            } else if (j == front && i != 0) {
                printf("*");
            } else {
                if (j == h-1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        front += 1;
        h += 1;
        printf("\n");
    }
}