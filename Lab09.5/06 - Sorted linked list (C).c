/*
ให้ผู้เรียนสร้างโครงสร้างข้อมูลแบบ linked list (ใช้วิธีใดก็ได้) สำหรับข้อมูลประเภทจำนวนเต็มและข้อมูลใน linked list ต้องเรียงลำดับจากน้อยไปมาก พร้อมสร้างฟังก์ชั่นในการจัดการ 3 ฟังก์ชั่น คือ insert delete และ print

insert รับค่าเป็นจำนวนเต็มหนึ่งตัวเพื่อเพิ่มเข้าไปใน linked list
delete รับค่าเป็นจำนวนเต็มหนึ่งตัวเพื่อลบข้อมูลทุกตัวที่มีค่าเท่ากับจำนวนเต็มนั้น
print แสดงข้อมูลทั้งหมดใน linked list (แสดงออกทาง stdout หนึ่งบรรทัด)
โปรแกรมจะรับคำสั่งผ่านทาง stdin โดยคำสั่งมีทั้งหมด 4 คำสั่งคือ

i k เป็นคำสั่ง insert: เพิ่มข้อมูล k เข้าไปใน linked list
d k เป็นคำสั่ง delete: ลบข้อมูลที่มีค่าเท่ากับ k ทุกตัวออกจาก linked list
p เป็นคำสั่ง print: แสดงข้อมูล
q เป็นคำสั่ง quit: จบการทำงาน

ตัวอย่างข้อมูลส่งออก
    input> p
    [ ]
    input> i 5
    input> i 4
    input> i 1
    input> p
    [ 1 4 5 ]
    input> i 10
    input> i 4
    input> d 4
    input> d 2
    input> i 9
    input> d 5
    input> i 6
    input> p
    [ 1 6 9 10 ]
    input>q
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node;
typedef Node* NodePtr;

void print_list(NodePtr start) {
    NodePtr current = start;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("]\n");
}

void insert_node(NodePtr* startPtr, int num) {
    NodePtr temp = (NodePtr) malloc(sizeof(Node));
    temp->num = num;
    temp->next = NULL;

    if (*startPtr == NULL || (*startPtr)->num > num) {
        temp->next = *startPtr;
        *startPtr = temp;
    } else {
        Node *current = *startPtr;
        
        while ( current->next != NULL && current->next->num < num) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void delete_node(NodePtr* startPtr, int num) {
    if (startPtr != NULL) {
        while (*startPtr && (*startPtr)->num == num)
            *startPtr = (*startPtr)->next;

        NodePtr current = *startPtr;
        NodePtr previous = NULL;

        while (current != NULL) {
            if (current->num == num) {
                previous->next = current->next;
            } else {
                previous = current;
            }
            current = current->next;
        }
    }
}


int main() {
    Node *startPtr = NULL;
    char command = ' ';
    int num = 0;
  
    while(command != 'q'){
        printf("input> ");
        scanf(" %c", &command);
    
        if(command == 'i'){
            scanf("%d", &num);
            insert_node(&startPtr, num);
        }

        if(command == 'd'){
            scanf("%d", &num);
            delete_node(&startPtr, num);
        }

        if(command == 'p'){
            print_list(startPtr);
        }
    }
}
