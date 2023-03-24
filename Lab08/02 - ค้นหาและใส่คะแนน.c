/*
ค้นหาและใส่คะแนน
ให้นิสิตสร้าง struct ของ studentRecord ซึ่งมี data member 2 ตัว คือ id ซึ่งเป็น string ขนาด 12 ตัวอักษรเก็บรหัสนิสิต และ score ซึ่งเป็นเลขจำนวนเต็มเก็บคะแนนของนิสิต

จากนั้นให้เขียนฟังก์ชันชื่อ init() ซึ่งจะใส่ข้อมูลของนิสิต 3 คน โดยใส่รหัสนิสิตเป็น “55100001”, “55100002”, และ “55100003” ตามลำดับ และใส่คะแนนของนิสิตเป็น 0 ไว้ก่อน

จากนั้นให้เขียนฟังก์ชันชื่อ enterScore() ซึ่งจะรับข้อมูลจากผู้ใช้มาสองค่า คือรหัสกับคะแนน (จาก standard input) เป็นจำนวน size บรรทัด คั่นรหัสนิสิตและคะแนนด้วยช่องว่าง
ฟังก์ชันนี้จะต้องนำคะแนนไปใส่ใน struct ของรหัสนิสิตให้ถูกต้อง
ผู้ใช้สามารถใส่รหัสนิสิตแค่บางส่วนได้ เช่นถ้าจะกรอกคะแนนของนิสิตรหัส 55100001 นั้นผู้ใช้สามารถพิมพ์แค่ 01 หรือ 001 หรือ 0001 หรือ 00001 ตามด้วยคะแนน ก็สามารถกรอกคะแนนได้ กำหนดว่ารหัสบางส่วนที่กรอกเข้ามาจะไม่คลุมเครือ (นั่นคือไม่ไปตรงกับบันทึกของนิสิตมากกว่า 1 คน) แต่อาจจะไม่มีนิสิตที่มีรหัสนั้น

นิสิตสามารถใช้ฟังก์ชันที่อยู่ใน string.h ช่วยในการเขียนโปรแกรมได้

ตัวอย่าง 1
    01 50
    ID        Score
    55100001       50
    55100002       0
    55100003       0
ตัวอย่าง 2
    002 75
    ID        Score
    55100001       0
    55100002       75
    55100003       0
    
หมายเหตุ: นิสิตสามารถเขียนฟังก์ชัน printRecords() ไว้ทดสอบเองได้ ตอนตรวจอาจารย์จะมีฟังก์ชัน printRecords() ของอาจารย์เอง
ดังนั้นนิสิตจึงไม่จำเป็นต้องระวังเรื่องรูปแบบการแสดงผลของ printRecords() แต่นิสิตต้องสร้าง struct ให้ถูกต้องตามข้อกำหนดไม่อย่างนั้นฟังก์ชัน printRecords() ของอาจารย์จะใช้ struct ของนิสิตไม่ได้

การตรวจจะทำเป็นส่วน คือจะตรวจฟังก์ชัน init() ก่อน ถ้าถูกต้องก็จะให้คะแนนส่วนหนึ่ง จากนั้นค่อยตรวจฟังก์ชัน enterScore() ดังนั้นนิสิตควรพยายามเขียนฟังก์ชัน init() ให้ได้เป็นอย่างน้อย
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char id[13];
    int score;
} studentRecord;

void init(studentRecord list[], int size) {
    int student_id = 55100001;
    char student_str[13];
    int i;

    for (i = 0; i < size; i++) {
        sprintf(student_str, "%d", student_id);
        strcpy(list[i].id, student_str);
        list[i].score = 0;
        student_id++;
    }
}

void enterScore(studentRecord list[], int size) {
    char target[13];
    int student_score = 0;
    scanf("%s %d", target, &student_score);
    for (int j = 0; j < size; j++) {
        if (strstr(list[j].id, target)) {
            list[j].score += student_score;
            return;
        }
    }
}

void printRecords(studentRecord list[], int size) {
	int i;

	printf("   ID        Score\n");
	for (i = 0; i < size; i++) {
		printf("%s       %d\n", list[i].id, list[i].score);
	}
}

int main() {
	int enter;
	studentRecord list[3];

	init(list, 3);
        enterScore(list, 3);
	printRecords(list, 3);
	return 0;
}