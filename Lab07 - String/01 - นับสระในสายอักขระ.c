/*
เขียนโปรแกรมภาษาซี รับ string เข้ามาหนึ่ง string ด้วย scanf() แล้วแสดงสระที่มีทั้งหมดใน string ดังกล่าวออกมา พร้อมกับแสดงจำนวนตัวอักขระที่เป็นสระด้วย ดังตัวอย่าง

ตัวอย่างผลลัพธ์ที่ 1
    String (without a space): hello
    e o 
    This string contains 2 vowels.
ตัวอย่างผลลัพธ์ที่ 2
    String (without a space): string
    i 
    This string contains 1 vowel.
ตัวอย่างผลลัพธ์ที่ 3
    String (without a space): zzzZZ!

    This string contains 0 vowel.
*/

#include <stdio.h>

int main() {
    int count_v = 0, s_length = 0;
    char string[80];

    printf("String (without a space): ");
    scanf("%s", string);
    
    // counts length of inputted string
    while (string[s_length] != '\0') {
        s_length++;
    }

    // checks each index of inputted string
    for (int i = 0; i < s_length; i++) {
        switch (string[i]) {
            case 'A':
            case 'a':
                printf("%c ", string[i]);
                count_v++;
                break;
            case 'E':
            case 'e':
                printf("%c ", string[i]);
                count_v++;
                break;
            case 'I':
            case 'i':
                printf("%c ", string[i]);
                count_v++;
                break;
            case 'O':
            case 'o':
                printf("%c ", string[i]);
                count_v++;
                break;
            case 'U':
            case 'u':
                printf("%c ", string[i]);
                count_v++;
                break;
        }
    }

    printf("\n");
    if (count_v <= 1) {
        printf("This string contains %d vowel.", count_v);
    } else {
        printf("This string contains %d vowels.", count_v);
    }
}