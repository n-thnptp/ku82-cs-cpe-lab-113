/*
กำหนดโครงสร้างข้อมูล struct
ให้กำหนดโครงสร้างข้อมูล struct ที่ใช้เก็บข้อมูลเกี่ยวกับโทรศัพท์มือถือ ซึ่งมีชื่อฟิลด์และรายละเอียดข้อมูลด้งต่อไปนี้:

    name - ชื่อเจ้าของโทรศัพท์ ซึ่งมีชนิดข้อมูลเป็นอะเรย์ของตัวอักษรจำนวนไม่เกิน 40 ตัว
    brand - ยี่ห้อของโทรศัพท์ ซึ่งมีชนิดข้อมูลเป็นอะเรย์ของตัวอักษรจำนวนไม่เกิน 20 ตัว
    calls - จำนวนครั้งที่เคยโทรออก
    price - ราคาของโทรศัพท์ที่ยังไม่รวมภาษีมูลค่าเพิ่ม
    vat - ภาษีมูลค่าเพิ่ม

ให้กำหนดโครงสร้างนี้ในบริเวณที่เว้นไว้ให้
*/

#include <stdio.h>
#include <string.h>

struct cellphone {
    char name[41];
    char brand[21];
    int calls;
    float price;
    float vat;
};

int main() {
    struct cellphone str;

    strcpy(str.name,"Name56789012345678901234567890123456789");
    strcpy(str.brand,"Brand67890123456789");
    str.calls = 1234.56;
    str.price = 12745.60;
    str.vat = 345.67;

    // test
    printf("%s\n",str.name);
    printf("%s\n",str.brand);
    printf("%d\n",str.calls);
    printf("%10.2f\n",str.price);
    printf("%10.2f\n",str.vat);
}