// จงเขียนโปรแกรมเพื่อรับขนาดของด้าน 3 ด้านของสามเหลี่ยมเป็นจำนวนเต็ม แล้วให้คำตอบว่า 3 ด้านที่ให้นั้นเป็นสามเหลี่ยมประเภทใด โดยสามเหลี่ยมแต่ละประเภทมีลักษณะดังต่อไปนี้

// * ไม่ใช่สามเหลี่ยม (invalid) เกิดขึ้นเมื่อ
//   - ผลรวมของ 2 ด้านน้อยกว่าหรือเท่ากับอีกด้านที่เหลือ
//   - มีด้านอย่างน้อย 1 ด้านที่น้อยกว่าหรือเท่ากับ 0
// * สามเหลี่ยมด้านเท่า (equilateral) ทั้งสามด้านเท่ากัน
// * สามเหลี่ยมหน้าจั่ว (isosceles) เท่ากันแค่ 2 ด้าน
// * สามเหลี่ยมด้านไม่เท่า (scalene) ไม่มีด้านใดเท่ากัน

// ตัวอย่าง Input/Output 1                    | ตัวอย่าง Input/Output 3
// Enter length of side A: 3                | Enter length of side A: 3
// Enter length of side B: 3                | Enter length of side B: 4
// Enter length of side C: 3                | Enter length of side C: 5
// Triangle type is equilateral.            | Triangle type is scalene.

// ตัวอย่าง Input/Output 2                    | ตัวอย่าง Input/Output 4
// Enter length of side A: 3                | Enter length of side A: 4
// Enter length of side B: 2                | Enter length of side B: 2
// Enter length of side C: 2                | Enter length of side C: 2
// Triangle type is isosceles.              | Triangle type is invalid.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char A_str[5], B_str[5], C_str[5];
    int A, B, C;

    printf("Enter length of side A: ");
    fgets(A_str, 5, stdin);

    printf("Enter length of side B: ");
    fgets(B_str, 5, stdin);

    printf("Enter length of side C: ");
    fgets(C_str, 5, stdin);
    
    A = atoi(A_str);
    B = atoi(B_str);
    C = atoi(C_str);

    if (A <= 0 || B <= 0 || C <= 0) {
        printf("Triangle type is invalid.");
    } else if (A + B <= C || B + C <= A || A + C <= B) {
        printf("Triangle type is invalid.");
    } else if (A == B && B == C && A == C) {
        printf("Triangle type is equilateral.");
    } else if (A == B || A == C || B == C || B == A) {
        printf("Triangle type is isosceles.");
    } else {
        printf("Triangle type is scalene.");
    }

    return 0;
}