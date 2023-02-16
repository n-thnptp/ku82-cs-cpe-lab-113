/*
จงเขียนฟังก์ชันเพื่อลบสระที่ปรากฏในสายอักขระที่ส่งผ่านฟังก์ชันเข้ามาออกให้หมด

ตัวอย่างผลลัพธ์ 1
     Input: hello, world
    Output: hll, wrld
ตัวอย่างผลลัพธ์ 2
     Input: abcdef 123456
    Output: bcdf 123456
*/

#include <stdio.h>

int remove_vowel(char* str) {
    int i = 0, j;
    while (str[i] != '\0') {
        // checks for vowels in string
        if (str[i] == 'A' || str[i] == 'a' || str[i] == 'E' || str[i] == 'e' || str[i] == 'I' || str[i] == 'i' || str[i] == 'O' || str[i] == 'o' || str[i] == 'U' || str[i] == 'u') {
            // moves letters that come after the deleted vowel
            for (j = i; str[j] != '\0'; j++) {
                str[j] = str[j+1];
            }
            i--;
        }
        i++;
    }
}

int main() {
    char str[80];

    printf(" Input: ");
    gets(str);

    remove_vowel(str);
    printf("Output: %s\n", str);

    return 0;
}