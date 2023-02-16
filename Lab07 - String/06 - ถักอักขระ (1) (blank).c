/*
จงเติมโค้ดเพื่อให้โปรแกรมสามารถทำงานได้อย่างสมบูรณ์ โดยที่ฟังก์ชัน int charcount(char *s) จะนับจำนวนอักขระที่ปรากฏอยู่ในสายอักษรที่ส่งผ่านเข้ามาในฟังก์ชันตั้งแต่อักขระตัวแรกจนถึงอักขระตัวสุดท้ายก่อนหน้าอักขระนัลล์ (null character)

ส่วนฟังก์ชัน void charweave(char *s,char *result) จะถักอักขระโดยเก็บผลลัพธ์ของการถักนี้ไว้ในตัวแปร result การถักอักขระมีลักษณะดังนี้ สมมติให้ตัวแปร s มีอักขระอยู่ n ตัวและรูปแบบการเรียงของอักขระเป็น C1C2C3C4...Cn ดังนั้นผลลัพธ์ที่ได้จากถักจะมีลักษณะเป็น C1CnC2Cn-1C3Cn-2C4Cn-3...Cn-1C2CnC1

Output 1:
    String: hello, world
    Output: hdellrloow,  ,woolrlledh
Output 2:
    String: 12345
    Output: 1524334251
*/
#include <stdio.h>

int charcount(char *s) {
    int i = 0;
    while (s[i]) {
        i++;
    }
    return i;
}

void charweave(char *s, char *result) {
    int i = 0, sel = 0, rev = charcount(s)-1, switchFlag = 0;
    for (i = 0; i < charcount(s)*2; i++) {
        if (switchFlag == 0) {
            result[i] = s[sel];
            printf("result[%d] = %c\n", i, s[sel]);
            sel++;
            switchFlag = 1;
        } else {
            printf("result[%d] = %c\n", i, s[rev]);
            result[i] = s[rev];
            rev--;
            switchFlag = 0;
        }
    }
    result[i] = '\0';
}

int main() {
    char str[100], result[200];

    printf("String: ");
    gets(str);          /* read a line of characters from the input to "str" variable */
    charweave(str,result);
    printf("Output: %s\n", result);
    return 0;
}