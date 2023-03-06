/*
Word Count
    จงเขียนโปรแกรมในการนับจำนวนคำที่ได้รับมาจากผู้ใช้งาน โดยผู้ใช้งานจะป้อนคำเข้ามาในระบบเรื่อย ๆ
    โปรแกรมสามารถบันทึกข้อมูลจำนวนคำที่ไม่ซ้ำกันได้ไม่เกิน 20 คำ (array data) และแต่ละคำ (word) มีความยาวไม่เกิน 20 ตัวอักษร
    เมื่อผู้ใช้งานป้อนคำเข้าไปในระบบจนพอใจแล้วให้ หยุดโปรแกรมโดยการพิมพ์คำว่า exit
    โปรแกรมจะหยุดทำงานพร้อมกับพิมพ์คำ (word) และจำนวนคำ (count) ที่ได้รับเข้ามาในระบบ

ตัวอย่าง 1
    This
    Is
    BOOK
    Book
    Hello
    Hello
    Hello
    exit
    Output:
    This = 1
    Is = 1
    BOOK = 1
    Book = 1
    Hello = 3

ตัวอย่าง 2
    one
    one
    one
    exit
    Output:
    one = 3
*/

#include <stdio.h>
#include <string.h>

struct Word {
    char word[21];
    int count;
};

/* loop inside each index of word struct data[i], if the word inside data[i]
is the same as input, then move data index to it */
int main() {
    char input[21];
    int i, last_word = 0, find = 0;
    struct Word data[20] = {0};
    scanf("%20s", input);

    while (strcmp(input, "exit")) {
        if (i == 0) {
            strcpy(data[i].word, input);
            data[i].count += 1;
            i++;
            last_word++;
        } else {
            scanf("%20s", input);
            for (int j = 0; j < last_word; j++) {
                if (!strcmp(input, data[j].word)) {
                    data[j].count += 1;
                    find = 1;
                    break;
                }
            }
            if (!find && strcmp(input, "exit")) {
                strcpy(data[i].word, input);
                data[i].count += 1;
                last_word++;
                i++;
            }
            find = 0;
        }
    }

    printf("Output:\n");
    for (i = 0; i < last_word; i++) {
        printf("%s = %d\n", data[i].word, data[i].count);
    }

}