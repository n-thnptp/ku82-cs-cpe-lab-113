// เขียนโปรแกรมเพื่อรับจำนวนเต็มบวก N (N <= 26) เพื่อแสดงรูปแบบสะท้อนขนาด N ของชุดตัวอักษร
// รูปแบบสะท้อนมีลักษณะดังนี้

// #size N = 3
// c-b-a-b-c

// #size N = 5
// e-d-c-b-a-b-c-d-e

// #size N = 10
// j-i-h-g-f-e-d-c-b-a-b-c-d-e-f-g-h-i-j

// หมายเหตุ
// * หากไม่สามารถสร้างรูปแบบสะท้อนขนาด N ของชุดตัวอักษรได้ ให้พิมพ์ -
// * ให้ใช้ Loop ในการแสดงรูปแบบสะท้อนดังกล่าว

#include <stdio.h>
#include <stdlib.h>

int alphabet_reflect(int n) {
    int i, j;
    char c, ref_c;

    if (n <= 0 || n >= 27) {
        printf("-");
    } else {
        // reflect [ex. d-c-b]
        for (i = 0; i < n; ++i) {
            ref_c = (char)97+(n-1)-i;
            if (ref_c != 97) {
                printf("%c-", ref_c);
            }
        }
        // normal [ex. a-b-c-d]
        for (j = 0; j < n; ++j) {
            c = (char)97+j;
            if (j == n-1) {
                printf("%c", c);
            } else {
                printf("%c-", c);
            }
        }
    }
}

int main() {
    char n_str[10];
    int n;

    fgets(n_str, 10, stdin);

    n = atoi(n_str);

    alphabet_reflect(n);
}