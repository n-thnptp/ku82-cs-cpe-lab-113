// เขียนโปรแกรมเพื่อรับค่าเศษส่วนในรูป a/b เมื่อ a และ b เป็นจำนวนเต็มบวกใด ๆ โดย a และ b มีค่าไม่เกิน 10000 บรรทัดแรกเป็นค่าเศษ a และบรรทัดที่สองเป็นค่าส่วน b
// จากนั้นแสดงเศษส่วนอย่างต่ำของเศษส่วนดังกล่าว

// * เศษส่วนอย่างต่ำ คือ เศษส่วนที่อยู่ในรูป p/q โดย ห.ร.ม. ของ p และ q เป็น 1
// * กรณีที่ตัวส่วนของเศษส่วนอย่างต่ำ มีค่าเป็น 1 จะแสดงเฉพาะตัวเศษ
// * เศษส่วนอย่างต่ำ อาจอยู่ในรูป เศษส่วนแท้ หรือ เศษเกิน ก็ได้

#include <stdio.h>
#include <stdlib.h>

int main() {
    char a_str[7], b_str[7];
    int i, a, b, a_cal, b_cal, AB_swap, result;
    double deno, numer, GCD;

    fgets(a_str, 7, stdin);
    fgets(b_str, 7, stdin);

    a = atoi(a_str);
    b = atoi(b_str);
    a_cal = a;
    b_cal = b;

    for (i = 0 ;; ++i) {    // GCD loop
        if (b > a) {
            AB_swap = a;
            a = b;
            b = AB_swap;
        }
        result = a % b;
        if (result == 0) {
            GCD = b;
            break;
        } else {
            a = b;
            b = result;
        }
    }

    deno = a_cal/GCD;
    numer = b_cal/GCD;
    if (numer == 1) {
        printf("= %.0f", deno);
    } else {
        printf("= %.0f/%.0f", deno, numer);
    }
}