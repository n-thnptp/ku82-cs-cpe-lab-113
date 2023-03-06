/*
หาวันในสัปดาห์
ให้นิสิตกำหนด enum ของ DayOfWeek และเขียนฟังก์ชันชื่อ findDayOfWeek() เพื่อหาวันของสัปดาห์จากวันและเดือน (เป็นตัวเลข) ของปีพ.ศ. 2556 ที่ผู้ใช้พิมพ์เข้ามา สังเกตว่าวันที่ 1 เดือน 1 ของปีพ.ศ. 2556 นั้นเป็นวันอังคาร

ตัวอย่าง
    Day:1 Month:1 of Year 2013 is Tuesday.
    Enter Day and Month: 26 7
    Day:26 Month:7 of Year 2013 is Friday.
*/

#include <stdio.h>

typedef enum {
    SUN, MON, TUE, WED, THU, FRI, SAT
}DayOfWeek;

DayOfWeek findDayOfWeek(int day, int month) {
    int i, j;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    DayOfWeek current;
    current = TUE;

    // checks if it is target month, then days loop only go up to that day and not the whole month
    for (int i = 1; i <= month; i++) {                                      /* months loop */
        for (int j = 1; j <= daysInMonth[i-1]; j++) {                       /* days loop */
            if (i == month && j == day) {
                break;
            } else {
                if (current < SAT) {
                    current++;
                } else {
                    current = SUN;
                }
            }
        }
        if (i == month && j == day) {
            break;
        }
    }
    return current;
}

int main() {
    int day, month;
    DayOfWeek dow;

    printf("Day:1 Month:1 of Year 2013 is Tuesday.\n");
	printf("Enter Day and Month: ");
	scanf("%d %d", &day, &month);
	dow = findDayOfWeek(day, month);
	printf("Day:%d Month:%d of Year 2013 is ", day, month);

	switch(dow){
		case 0: printf("Sunday.\n"); break;
        case 1: printf("Monday.\n"); break;
        case 2: printf("Tuesday.\n"); break;
        case 3: printf("Wednesday.\n"); break;
        case 4: printf("Thursday.\n"); break;
        case 5: printf("Friday.\n"); break;
        case 6: printf("Saturday.\n"); break;
	}
}