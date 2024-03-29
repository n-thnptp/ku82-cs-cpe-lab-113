// สมมติว่ามีธนบัตรใบละ 50, 20, 5 และ 1 บาท ให้ตัวแปร amount เก็บค่าจำนวนเงินที่ต้องทอน (เป็นจำนวนเต็มเสมอ) แล้วแสดงผลลัพธ์เป็นจำนวนธนบัตรแต่ละชนิดที่ต้องทอน
// โดยกำหนดให้ทอนเป็นธนบัตรชนิดราคาสูงกว่าให้ได้มากที่สุดก่อน แต่ให้พิมพ์คำตอบเรียงลำดับจากธนบัตรชนิดราคาต่ำ ไปหาราคาสูงที่สุด

// ตัวอย่างผลลัพธ์เมื่อตัวแปร amount มีค่า 98
// 1: 3
// 5: 1
// 20: 2
// 50: 1

// ตัวอย่างผลลัพธ์เมื่อตัวแปร amount มีค่า 19
// 1: 4
// 5: 3
// 20: 0
// 50: 0

// ตัวอย่างผลลัพธ์เมื่อตัวแปร amount มีค่า 50
// 1: 0
// 5: 0
// 20: 0
// 50: 1

// พิมพ์โปรแกรมของคุณลงในช่องว่างข้างล่างนี้
#include <stdio.h>

int main() {
    int amount = 98;

    int fifty = amount / 50;
    int twenty = (amount % 50) / 20;
    int five = ((amount % 50) % 20) / 5;
    int one = (((amount % 50) % 20) % 5);

    printf("1: %d\n", one);
    printf("5: %d\n", five);
    printf("20: %d\n", twenty);
    printf("50: %d", fifty);

    return 0;
}