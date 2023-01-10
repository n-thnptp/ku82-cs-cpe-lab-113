/*
ต้องการสร้าง array a ดังตัวอย่างด้านล่าง จงเติมโค้ดให้สมบูรณ์

    Enter the number of rows or columns: 10
     1  2  3  4  5  6  7  8  9 10
     2  3  4  5  6  7  8  9 10 11 
     3  4  5  6  7  8  9 10 11 12 
     4  5  6  7  8  9 10 11 12 13 
     5  6  7  8  9 10 11 12 13 14
     6  7  8  9 10 11 12 13 14 15
     7  8  9 10 11 12 13 14 15 16
     8  9 10 11 12 13 14 15 16 17
     9 10 11 12 13 14 15 16 17 18
    10 11 12 13 14 15 16 17 18 19
*/

#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows or columns: ");
    scanf("%d",&n);
    int a[n][n];

    // Assign value to array a
    for (i=0; i < n; ++i) {
        for (j=0; j < n; ++j)
            a[i][j] = i+j+1;
    }

    // Print all values in array a
    for(i=0; i < n; ++i) {
        for(j=0; j < n; ++j)
            printf("%2d ", a[i][j]);
        printf("\n");
    }
    return 0;
}