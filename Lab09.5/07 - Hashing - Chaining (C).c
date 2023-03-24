/*
เขียนโปรแกรมทดสอบการเก็บข้อมูลเลขจำนวนเต็มลงใน hash table ที่มีการแก้ไขการชนแบบ chaining โดยใช้ hash function เป็นการ modulo ด้วย 97 ซึ่งโปรแกรมจะคอยรับคำสั่งจากผู้ใช้ คำสั่งที่ใช้ได้ทั้งหมดมี 3 คำสั่งดังนี้

    * p เป็นคำสั่ง แสดงข้อมูลใน hash table ตามรูปแบบดังตัวอย่าง
    * a x เป็นคำสั่ง add เลขจำนวนเต็มบวก x ลงในตาราง hash table โดยเพิ่มเข้าที่หัวตาราง
    * q เป็นคำสั่ง จบการทำงานของโปรแกรม

การ add ถ้าทำไม่ได้ ไม่ต้องแสดงข้อความใด ๆ ทั้งสิ้น

และกำหนดให้ข้อมูลจำนวนเต็มบวก ต้องเก็บใน struct Node

ตัวอย่างที่ 1 เป็นการกำหนดให้ hash table มีขนาดเท่ากับ 7 และ hash function เป็นการ modulo ด้วย 7

ตัวอย่างผลลัพธ์ที่ 1
    input> a 42
    input> a 53
    input> a 66
    input> a 28
    input> a 59
    input> a 91
    input> p
    KEY  0: 91 28 42 
    KEY  1: 
    KEY  2: 
    KEY  3: 59 66 
    KEY  4: 53 
    KEY  5: 
    KEY  6: 
    input> a 66
    input> a 28
    input> p
    KEY  0: 28 91 28 42 
    KEY  1: 
    KEY  2: 
    KEY  3: 66 59 66 
    KEY  4: 53 
    KEY  5: 
    KEY  6: 
    input> q

ตัวอย่างที่ 2 เป็นการกำหนดให้ hash table มีขนาดเท่ากับ 97 และ hash function เป็นการ modulo ด้วย 97
ตัวอย่างผลลัพธ์ที่ 2
    input> a 4675
    input> a 7641
    input> a 5467
    input> a 3375
    input> a 6831
    input> a 3021
    input> a 3118
    input> p
    KEY  0: 
    KEY  1: 
    KEY  2: 
    KEY  3: 
    KEY  4: 
    KEY  5: 
    KEY  6: 
    KEY  7: 
    KEY  8: 
    KEY  9: 
    KEY 10: 
    KEY 11: 
    KEY 12: 
    KEY 13: 
    KEY 14: 3118 3021 
    KEY 15: 
    KEY 16: 
    KEY 17: 
    KEY 18: 
    KEY 19: 4675 
    KEY 20: 
    KEY 21: 
    KEY 22: 
    KEY 23: 
    KEY 24: 
    KEY 25: 
    KEY 26: 
    KEY 27: 
    KEY 28: 
    KEY 29: 
    KEY 30: 
    KEY 31: 
    KEY 32: 
    KEY 33: 
    KEY 34: 
    KEY 35: 5467 
    KEY 36: 
    KEY 37: 
    KEY 38: 
    KEY 39: 
    KEY 40: 
    KEY 41: 6831 
    KEY 42: 
    KEY 43: 
    KEY 44: 
    KEY 45: 
    KEY 46: 
    KEY 47: 
    KEY 48: 
    KEY 49: 
    KEY 50: 
    KEY 51: 
    KEY 52: 
    KEY 53: 
    KEY 54: 
    KEY 55: 
    KEY 56: 
    KEY 57: 
    KEY 58: 
    KEY 59: 
    KEY 60: 
    KEY 61: 
    KEY 62: 
    KEY 63: 
    KEY 64: 
    KEY 65: 
    KEY 66: 
    KEY 67: 
    KEY 68: 
    KEY 69: 
    KEY 70: 
    KEY 71: 
    KEY 72: 
    KEY 73: 
    KEY 74: 
    KEY 75: 7641 
    KEY 76: 
    KEY 77: 3375 
    KEY 78: 
    KEY 79: 
    KEY 80: 
    KEY 81: 
    KEY 82: 
    KEY 83: 
    KEY 84: 
    KEY 85: 
    KEY 86: 
    KEY 87: 
    KEY 88: 
    KEY 89: 
    KEY 90: 
    KEY 91: 
    KEY 92: 
    KEY 93: 
    KEY 94: 
    KEY 95: 
    KEY 96: 
    input> q
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 97

typedef struct nodeType {
    int item;
    struct nodeType* next;
} Node;

typedef Node* NodePtr;

void print_table(int size, NodePtr* table) {
    for (int i = 0; i < size; i++) {
        NodePtr curr = table[i];
        printf("KEY %2d: ", i);
        while (curr != NULL) {
            printf("%d ", curr->item);
            curr = curr->next;
        }
        printf("\n");
    }
}

void insert_table(int value, NodePtr* table) {
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    int key_index = value % SIZE;
    temp->item = value;
    temp->next = table[key_index];
    table[key_index] = temp;
}

int main() {
    NodePtr table[SIZE] = {NULL};
    char command = ' ';
    int num = 0;

    while(command != 'q'){
        printf("input> ");
        scanf(" %c", &command);

        if(command == 'a'){
            scanf("%d", &num);
            insert_table(num, table);
        }

        if(command == 'p'){
            print_table(SIZE, table);
        }
    }
}