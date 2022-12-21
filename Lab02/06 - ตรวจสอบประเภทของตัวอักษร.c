// ให้เขียนโปรแกรมสำหรับตรวจสอบว่าตัวอักษรที่พิมพ์เข้ามาเป็นอักษรชนิด ตัวพิมพ์เล็ก (lower case), ตัวพิมพ์ใหญ่ (upper case), ตัวเลข (digit), หรือเป็นอักษรประเภทอื่น (others)
// ASCII Table
// digits = 48 - 57
// upper = 65 - 90
// lower = 97 - 122

// Expected output
// b
// Output: lower case 
// 7
// Output: digit
// W
// Output: upper case
// +
// Output: others

#include <stdio.h>

int main() {
    char c;
    c = getchar();

    if (c >= 48 && c <= 57) {
        printf("Output: digit");
    } else if (c >= 65 && c <= 90) {
        printf("Output: upper case");
    } else if (c >= 97 && c <= 122) {
        printf("Output: lower case");
    } else {
        printf("Output: other");
    }

    return 0;
}