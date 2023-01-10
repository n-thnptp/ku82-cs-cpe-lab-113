/*
ให้เขียนโปรแกรมจำลองการไต่ขั้นบันได โดยเริ่มแรก โปรแกรมจะถามจำนวนขั้นบันได (บรรทัดที 1)
จากนั้น ในแต่ละรอบ โปรแกรมจะแสดงตำแหน่งปัจจุบันของคนบนขั้นบันได และโปรแกรมจะถาม step command

step command สำหรับโปรแกรมนี้ คือ

    ถ้าเป็นจำนวนเต็มบวก x หมายถึง ให้ไต่บันไดขึ้นไป x ขั้น
    ถ้าเป็นจำนวนเต็มลบ -x หมายถึง ให้ไต่บันไดลงมา x ขั้น
    ถ้าเป็นจำนวนเต็มศูนย์ หมายถึง จบโปรแกรม
    เงื่อนไขเพิ่มเติมของโปรแกรมนี้ คือ

คน ประกอบด้วย 2 ส่วน คือ ส่วนหัว (O) และส่วนขา (^)
รอบที่หนึ่ง ขาของคนจะอยู่ที่ขั้นบันไดล่างสุด
ขาของคนจะไม่อยู่ต่ำกว่าบันไดขั้นล่างสุด และหัวของคนจะไม่อยู่สูงกว่าบันไดขั้นบนสุด

Output :
    Input number of stairs: 4
    ---- round 1 ----
    |---|
    |---|
    |-O-|
    |-∧-|
    Input step command: 2
    ---- round 2 ----
    |-O-|
    |-∧-|
    |---|
    |---|
    Input step command: -1
    ---- round 3 ----
    |---|
    |-O-|
    |-∧-|
    |---|
    Input step command: -2
    ---- round 4 ----
    |---|
    |---|
    |-O-|
    |-∧-|
    Input step command: -1
    ---- round 5 ----
    |---|
    |---|
    |-O-|
    |-∧-|
    Input step command: 0
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int stairs, steps, body, head;

    printf("Input number of stairs: ");
    scanf("%d", &stairs);
    head = stairs-2;
    body = head+1;

    char *ladders[stairs+1][6];

    for (int i=1 ;; ++i) {
        printf("---- round %d ----\n", i);
        // create an array
        for (int rows=0; rows < stairs; ++rows) {
            for (int col=0; col < 5; ++col)
                if (col == 0 || col == 4) {
                    ladders[rows][col] = "|";
                } else {
                    if (col == 2 && (rows == head || rows == body)) {
                        if (rows == head) {
                            ladders[rows][col] = "O";
                        } else if (rows == body) {
                            ladders[rows][col] = "^";
                        }
                    } else {
                        ladders[rows][col] = "-";
                    }
            }
        }
        printf("head = %d, body = %d\n", head, body);
        // displays current ladder
        for (int j=0; j < stairs; ++j) {
            for (int k=0; k < 5; ++k)
                printf("%s", ladders[j][k]);
            printf("\n");
        }
        // input steps
        printf("Input step command: ");
        scanf("%d", &steps);

        if (steps == 0) {
            return 0;
        } else {
            if (steps < 0) {
                if (head + (steps*(-1)) >= stairs-1) {
                    head = stairs-2;
                    body = head+1;
                } else {
                    head += steps*(-1);
                    body += steps*(-1);
                }
            } else {
                if (head - steps < 0) {
                    head = 0;
                    body = 1;
                } else {
                    head -= steps;
                    body -= steps;
                }
            }
        }
    }
}