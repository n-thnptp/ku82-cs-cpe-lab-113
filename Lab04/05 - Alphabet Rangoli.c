/*
ภาพวาดรูปแบบหนึ่งที่มักเห็นประจำในอินเดียก็คือ ภาพวาดที่เรียกว่า รังโกลี (Rangoli) ซึ่งเป็นรูปแบบหนึ่งของศิลปะที่นิยมมากที่สุดในอินเดียก็ว่าได้ เป็นการวาดภาพด้วยทรายหรือผงสี บนพื้นขาวหรือพื้นสี ซึ่งมักใช้ตกแต่งหน้าบ้านของชาวอินเดียในงานเทศกาลต่างๆ หรือในสถานที่จัดงานสำคัญๆ หมายถึงการต้อนรับขับสู้อย่างอบอุ่นของเจ้าบ้านหรือเจ้าภาพต่อแขกที่มาเยือน

ในข้อนี้จะให้เขียนโปรแกรมเพื่อวาดภาพรังโกลี จากตัวอักษรภาษาอังกฤษ โดยรับข้อมูลเป็นจำนวนเต็มบวก N (N <= 26) ซึ่งเป็นขนาดของภาพรังโกลี และเป็นลำดับอักษรภาษาอังกฤษสูงสุดที่ใช้ในภาพ เช่น N = 3 หมายถึงใช้ตัวอักษรภาษาอังกฤษ a, b และ c เท่านั้น

ขนาดของภาพรังโกลีมีลักษณะดังนี้

#Size N = 3
----c----       @ index 4
--c-b-c--       @ index 2
c-b-a-b-c       @ index 0
--c-b-c--       @ index 2
----c----       @ index 4

#Size N = 10
------------------j------------------
----------------j-i-j----------------
--------------j-i-h-i-j--------------
------------j-i-h-g-h-i-j------------
----------j-i-h-g-f-g-h-i-j----------
--------j-i-h-g-f-e-f-g-h-i-j--------
------j-i-h-g-f-e-d-e-f-g-h-i-j------
----j-i-h-g-f-e-d-c-d-e-f-g-h-i-j----
--j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j--
j-i-h-g-f-e-d-c-b-a-b-c-d-e-f-g-h-i-j
--j-i-h-g-f-e-d-c-b-c-d-e-f-g-h-i-j--
----j-i-h-g-f-e-d-c-d-e-f-g-h-i-j----
------j-i-h-g-f-e-d-e-f-g-h-i-j------
--------j-i-h-g-f-e-f-g-h-i-j--------
----------j-i-h-g-f-g-h-i-j----------
------------j-i-h-g-h-i-j------------
--------------j-i-h-i-j--------------
----------------j-i-j----------------
------------------j------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char n_str[10];
    int n, j, rows = 0, col, alpha, start, end;

    fgets(n_str, 10, stdin);
    n = atoi(n_str);

    rows = (2*n)-1;
    start = ((2*n)-1)-1;
    end = start;

    if (n <= 0 || n > 26) {
        printf("-");
    } else {
        for (int i=0; i < rows; ++i) {
            // left most letter
            alpha = (97+n)-1;
            for (int j=0; j <= (rows*2)-2; ++j) {
                if (j % 2 == 0 && (j >= start && j <= end+1)) {
                    if (j <= (2*n)-1) {
                        printf("%c", alpha);
                        // alphabet + 1 before going to the letter after the first half
                        if (j == (2*n)-2) {
                            alpha += 1;
                            continue;
                        // first half
                        } else {
                            alpha -= 1;
                        }
                    // reflection
                    } else if (j >= 2*n) {
                        printf("%c", alpha);
                        alpha += 1;
                    }
                } else {
                    printf("-");
                }
            }
            // move start and end index
            // upper half (if row/i is in upper half)
            if (i < n-1) {
                start -= 2;
                end += 2;
            // lower half
            } else {
                start += 2;
                end -= 2;
            }
            printf("\n");
        }
    }
}