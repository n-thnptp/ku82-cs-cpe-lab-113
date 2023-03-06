/*
โปรแกรมเก็บข้อมูลสินค้าขนาดไม่จำกัด (ภาษา C)

โปรแกรมในข้อนี้เป็นโปรแกรมที่ใช้ในการเก็บชื่อของสินค้าความยาวไม่เกิน 20 อักขระ โดยโปรแกรมสามารถเก็บข้อมูลสินค้าในหน่วยความจำของคอมพิวเตอร์โดยใช้โครงสร้างข้อมูลแบบ Linkedlist ผู้ใช้งานโปรแกรมสามารถพิมพ์รายชื่อสินค้าได้โดยไม่จำกัดจำนวน เมื่อใส่รายชื่อสินค้าจนพอใจแล้วให้พิมพ์คำสั่ง done เพื่อทำการจบการทำงานของโปรแกรม

ให้นักเรียนทำความเข้าใจการทำงานของโปรแกรมและเขียนฟังก์ชัน print_all_goods() ให้สมบูรณ์ โดยฟังก์ชัน print_all_goods() จะทำการพิมพ์ข้อมูลสินค้าทั้งหมดที่เก็บอยู่ใน Linkedlist พร้อมทั้ง return ค่าออกมาเป็นจำนวนรายชื่อสินค้าทั้งหมดใน Linkedlist

ตัวอย่าง 1
    Name: Good1
    Name: Good2
    Name: done
    Good1
    Good2
    Total = 2

ตัวอย่าง 2
    Name: Lay
    Name: Pepsi
    Name: Fanta
    Name: Taro
    Name: Pocky
    Name: done
    Lay
    Pepsi
    Fanta
    Taro
    Pocky
    Total = 5
    
Youtube Explanation : https://www.youtube.com/watch?v=VOpjAHCee7c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct good
{
    char name[20];
    struct good *next;
} Good;

Good *start = NULL;

void add_good(Good *new_good) {
    Good *current_good = start;
    Good *previous_good = NULL;
    while (current_good) {
        previous_good = current_good;
        current_good = current_good->next;
    }
    if (previous_good != NULL) {
        previous_good->next = new_good;
    } else {
        start = new_good;
    }
}
int print_all_goods() {
    Good *curr = start;                     /* curr pointer to store the start (or current node) */
    int total = 0;
    while (curr != NULL) {                  /* as long as the list has not ended */
        printf("%s\n", curr->name);         /* current points to name in struct */
        curr = curr->next;                  /* now current points to the next node */
        total++;
    }
    return total;
}
main() {
    char name[20];
    int price;
    Good *new_node;
    printf("Name: ");
    scanf("%20s", name);

    while (strcmp(name, "done")) {
        new_node = (Good *)malloc(sizeof(Good));
        strcpy(new_node->name, name);
        new_node->next = NULL;
        add_good(new_node);

        printf("Name: ");
        scanf("%20s", name);
    }

    printf("total = %d\n", print_all_goods());
}