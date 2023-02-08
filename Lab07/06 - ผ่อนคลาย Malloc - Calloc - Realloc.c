#include <stdio.h>
#include <stdlib.h>

int main() {
    int *A, *B;
    // (int *) = cast for allocation
    
    // 1. เขียนประโยคคำสั่งเพื่อทำการจองพื้นที่หน่วยความจำ ที่ทำการเก็บตัวแปรชนิด int ขนาด 20 integers โดยหน่วยความจำดังกล่าวถูกชี้โดย pointer A
    // ptr = (cast-type*) malloc(byte-size);
    // malloc initializes each block with no default value
    A = (int *)malloc(20 * sizeof(int));        // this allocates memory for 20 integers

    // 2. เขียนประโยคคำสั่งเพื่อทำการจองพื้นที่หน่วยความจำ ที่ทำการเก็บตัวแปรชนิด int ขนาด 40 byte โดยกำหนดให้ค่าเป็น 0 ของหน่วยความจำที่ชี้โดย pointer B
    // ptr = (cast-type*)calloc(n, element-size); = allocates memory of n size, each element size of element-size
    // calloc also initializes each block with default value of 0 
    B = (int *)calloc(10, sizeof(int));         // this allocates memory for 40 bytes

    // 3. ให้ทำการลดพื้นที่การจองในข้อ 1 เป็น 10 intergers
    // ptr = realloc(ptr, newSize);
    A = realloc(A, 10 * sizeof(int));           // this reallocates memory down to 10 integers (or 10 * 4 bytes)

    // 4. ให้ทำการเพิ่มพื้นที่การจองในข้อ 2 เป็น 15 intergers
    // ptr = realloc(ptr, newSize);
    B = realloc(B, 15 * sizeof(int));           // this increases allocated memory to 15 integers (or 15 * 4 bytes)
}