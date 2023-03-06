/*
จงเขียนโปรแกรมเพื่อรับค่าพิกัดจุดเริ่มต้น และจุดสิ้นสุดบนแกนสองมิติ (X, Y) จำนวน n คู่จากผู้ใช้
แล้วคำนวณและแสดงผลระยะห่างระหว่างจุด 2 จุดอย่างต่อเนื่องตั้งแต่จุดที่ 1 ถึงจุดที่ N
โปรแกรมมีโครงสร้างของชุดคำสั่งดังนี้
    1. ประกาศโครงสร้างข้อมูล struct Point เพื่อใช้เก็บตำแหน่งของจุดทั้ง 2 ที่อยู่บนแกน X, Y ซึ่งมีชนิดข้อมูลเป็น double
    2. ที่ main() ประกาศตัวแปร array of struct ชื่อ points ให้มีชนิดข้อมูลเป็น struct Point เพื่อเก็บคู่อันดับของพิกัด X, Y จากผู้ใช้ จำนวน n คู่
    3. เขียนคำสั่ง for เพื่ออ่านคู่อันดับของพิกัด X, Y จำนวน n คู่จากผู้ใช้ ตามตัวอย่างการรับค่าจาก standard input
    4. เขียนคำสั่ง for โดยกำหนดให้ภายใน for loop ประกอบด้วย statements ต่อไปนี้
        - กำหนดตัวแปร dX,dY ให้มีชนิดข้อมูลเป็น double ใช้เก็บความยาวจากจุดหนึ่งไปยังอีกจุดหนึ่งตามแนวแกน X และแนวแกน Y ตามลำดับ
        - คำนวณระยะห่าง (length) ระหว่างจุด 2 จุด
        - แสดงผลลัพธ์ตามรูปแบบที่กำหนดให้ในตัวอย่างการแสดงผล (ต้องการทศนิยม 2 ตำแหน่ง)

ตัวอย่างโปรแกรม
    Number of Points: 5
    P1.X: 1
    P1.Y: 1
    P2.X: 1
    P2.Y: -5
    P3.X: -5
    P3.Y: 25
    P4.X: 19
    P4.Y: -3
    P5.X: 15
    P5.Y: 20
    Length:
    Length from P1(1.00, 1.00) to P2(1.00, -5.00) is 6.00
    Length from P2(1.00, -5.00) to P3(-5.00, 25.00) is 30.59
    Length from P3(-5.00, 25.00) to P4(19.00, -3.00) is 36.88
    Length from P4(19.00, -3.00) to P5(15.00, 20.00) is 23.35
*/

#include <stdio.h>
#include <math.h>

struct Point {
    double X, Y;
};

int main() {
    int points = 0;
    double X, Y;
    printf("Number of Points: ");
    scanf("%d", &points);
    struct Point list[points];

    for (int i = 1; i <= points; i++) {

        struct Point temp;

        printf("P%d.X: ", i);
        scanf("%lf", &temp.X);
        printf("P%d.Y: ", i);
        scanf("%lf", &temp.Y);

        list[i-1] = temp;

    }

    printf("Length:\n");
    for (int i = 1; i < points; i++) {
        printf("Length from P%d(%.2lf, %.2lf) ", i, list[i-1].X, list[i-1].Y);
        printf("to P%d(%.2lf, %.2lf) is ", i+1, list[i].X, list[i].Y);
        printf("%.2lf\n", sqrt( (list[i-1].X-list[i].X)*(list[i-1].X-list[i].X) + (list[i-1].Y-list[i].Y)*(list[i-1].Y-list[i].Y) ));
    }

}