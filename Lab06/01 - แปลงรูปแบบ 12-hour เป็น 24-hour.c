/*
จงเขียนโปรแกรมที่รับเวลาในรูปแบบ 12-hour (เช่น 12:59 pm โดยคำว่า am/pm เป็น upper/lower case ก็ได้) แล้วแสดงผลลัพธ์เป็นเวลาเดียวกันในรูปแบบ 24-hour ดังตัวอย่าง

ตัวอย่างผลลัพธ์ที่ 1
    Enter a 12-hour time [eg. 12:34 am]: 11:11 PM
    Equivalent 24-hour time: 23:11
ตัวอย่างผลลัพธ์ที่ 2
    Enter a 12-hour time [eg. 12:34 am]: 1:23 am
    Equivalent 24-hour time: 01:23
ตัวอย่างผลลัพธ์ที่ 3
    Enter a 12-hour time [eg. 12:34 am]: 12:00 am
    Equivalent 24-hour time: 00:00
ตัวอย่างผลลัพธ์ที่ 4
    Enter a 12-hour time [eg. 12:34 am]: 12:05 PM
    Equivalent 24-hour time: 12:05
*/

#include <stdio.h>
int main() {
    int hours, mins;
    char time[3];

    printf("Enter a 12-hour time [eg. 12:34 am]: ");
    scanf("%d:%d %s", &hours, &mins, time);

    if (( (time[0] == 'P' && time[1] == 'M') || (time[0] == 'p' && time[1] == 'm') ) && hours < 12) {
        hours += 12;
    } else if (( (time[0] == 'A' && time[1] == 'M') || (time[0] == 'a' && time[1] == 'm') ) && hours == 12) {
        hours -= 12;
    }
    printf("Equivalent 24-hour time: %.2d:%.2d", hours, mins);
}