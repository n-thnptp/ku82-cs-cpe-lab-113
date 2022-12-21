// จงเขียนโปรแกรมภาษาซี ซึ่งรับข้อมูลจำนวนจริง salary แสดงถึงรายได้ต่อปีของบุคคล

// โปรแกรมนี้จะคำนวณว่า จากรายได้ต่อปีของบุคคลนั้น จะต้องจ่ายภาษีเป็นจำนวนเท่าใด (ให้แสดงเป็นทศนิยม 2 ตำแหน่ง)
// โดยการเก็บภาษีจะเป็นแบบขั้นบันได กล่าวคือ 300,000 บาทแรกจะต้องจ่าย 5% และ 300,000.01 บาทขึ้นไปจะจ่าย 10%

// เช่น ถ้ารายได้ต่อปีเป็น 100,000 บาท จะจ่ายภาษี 5% เท่ากับ 5,000 บาท

// แต่ถ้ารายได้ต่อปีเป็น 500,000 บาทแล้ว การจ่ายภาษีจะคำนวณดังนี้
// 300,000 บาทแรกจะจ่าย 5% เท่ากับ 15,000 บาท และที่เหลือ 200,000 บาทจะจ่าย 10% เท่ากับ 20,000 บาท ดังนั้น เสียภาษีรวมเป็นเงิน (15,000+20,000=35,000 บาท)

// นอกจากนั้น ถ้ารายได้เป็นค่าลบ ให้แสดงข้อความเตือน Error: Salary must be greater or equal to 0

// Expected output 1                            | Expected output 2
// 100000.00                                    | 500000
// 5000.00                                      | 35000.00

#include <stdio.h>
#include <stdlib.h>

int main() {
    char sal_str[12];
    float total = 0;

    fgets(sal_str, 12, stdin);

    float sal = atof(sal_str);

    if (sal < 0) {
        printf("Error: Salary must be greater or equal to 0");
    } else {
        if (sal <= 300000) {
            total += (sal * 5) / 100;
        } else {
            total += ((300000 * 5) / 100) + (((sal - 300000) * 10) / 100);
        }
        printf("%.2f", total);
    }
    
    return 0;
}