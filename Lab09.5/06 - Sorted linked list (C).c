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

void insert_node(int num, Node **head) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->num = num;
    new_node->next = NULL;

    if(*head == NULL || (*head)->num > num) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node *curr = *head;
        while(curr->next != NULL && curr->next->num < num) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void delete_node(int num, Node **head){
    Node *curr;
    Node *temp;
    while ( (*head) && (*head)->num == num)
        *head = (*head)->next;
  
    curr = *head;
    Node *prev = NULL;
    while (curr != NULL) {
        if (curr->num == num) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
}

void print_list(Node *head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    Node *data = NULL;
    char command = ' ';
    int num = 0;
  
    while(command != 'q'){
        printf("input> ");
        scanf(" %c", &command);
    
        if(command == 'i'){
            scanf("%d", &num);
            insert_node(num, &data);
        }

        if(command == 'd'){
            scanf("%d", &num);
            delete_node(num, &data);
        }

        if(command == 'p'){
            print_list(data);
        }
    }
}
