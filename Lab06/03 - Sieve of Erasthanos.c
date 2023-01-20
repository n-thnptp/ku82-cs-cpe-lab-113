/*
เป็นวิธีการหาค่า prime ตั้งแต่ 2 ถึง n เมื่อ n เป็นจำนวนเต็มบวก โดยเป็นการตัดค่าที่ไม่ใช่ prime ออกไปเรื่อยๆ ซึ่งมีวิธีการดังนี้

    สร้างอาร์เรย์เก็บค่าตั้งแต่ 2 - n
    เริ่มต้นที่ค่า p = 2
    ตัดค่าที่ p หารลงตัวออกให้หมด
    หาค่าต่อไปในอาร์เรย์ที่ยังไม่ถูกตัด ค่านี้เป็น prime ตัวต่อไป
    ทำข้อ 3-4 ซ้ำจน p ยกกำลัง 2 มากกว่า n
    ค่าที่เหลือเป็น prime
    จงเขียนโปรแกรมหา prime เมื่อ n = 97 ด้วยวิธีนี้

ดูตัวอย่างการทำงานของโปรแกรมนี้ได้ที่ http://upload.wikimedia.org/wikipedia/commons/8/8c/New_Animation_Sieve_of_Eratosthenes.gif
*/

#include <stdio.h>
#define ARRAY_SIZE 98

int main() {
    int i, j;
    int A[ARRAY_SIZE] = {0};

    for (i = 2; i < ARRAY_SIZE; i++)
        A[i] = 1;

    for (i = 2; i * i < ARRAY_SIZE; i++) {
        for (j = 2; j * i < ARRAY_SIZE; j++) {
            A[j * i] = 0;
        }
    }

    for (i = 2; i < ARRAY_SIZE; i++)
        if (A[i] != 0)
            printf("%d ", i);

    printf("\n");

    return 0;
}

// 1 1 0 1 1 1 1 1 1 1 1