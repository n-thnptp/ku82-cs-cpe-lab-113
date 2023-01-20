/*
เขียนโปรแกรมภาษาซี เพื่อคำนวณ GPA ในภาคการศึกษาหนึ่ง ของนิสิตหนึ่งคน โดยกำหนดให้ รับจำนวนวิชาที่เรียนทั้งหมดในภาคการศึกษาก่อน (จำนวนวิชาอย่างน้อย 1 วิชา) แล้วจึงรับ จำนวนหน่วยกิต และเกรด (เกรดที่โปรแกรมยอมรับ คือ A,a,B,b,C,c,D,d,F และ f เท่านั้น) ของแต่ละวิชา ในรูปแบบ credit,grade ให้ครบตามจำนวนวิชา แสดงผลดังรูปแบบในตัวอย่าง

ให้น้ำหนักของเกรด A, B, C, D, F เป็น 4, 3, 2, 1, 0 ตามลำดับ

ตัวอย่างที่ 1
    Enter number of subject(s): 1
    Enter credit,grade for subject #1: 4,b
    GPA = 3.00
ตัวอย่างที่ 2
    Enter number of subject(s): 8
    Enter credit,grade for subject #1: 3,b
    Enter credit,grade for subject #2: 3,b
    Enter credit,grade for subject #3: 4,a
    Enter credit,grade for subject #4: 3,a
    Enter credit,grade for subject #5: 3,b
    Enter credit,grade for subject #6: 3,A
    Enter credit,grade for subject #7: 1,A
    Enter credit,grade for subject #8: 1,a
    GPA = 3.57
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_subjects, creds, total_creds = 0;
    float GPA;
    char grade;

    printf("Enter number of subject(s): ");
    scanf("%d", &n_subjects);

    for (int i=1; i <= n_subjects; ++i) {
        printf("Enter credit,grade for subject #%d: ", i);
        scanf("\n%d,%c", &creds, &grade);
        total_creds += creds;

        switch (grade) {
            case 'A':
            case 'a':
                GPA += 4*creds;
                break;
            case 'B':
            case 'b':
                GPA += 3*creds;
                break;
            case 'C':
            case 'c':
                GPA += 2*creds;
                break;
            case 'D':
            case 'd':
                GPA += 1*creds;
                break;
            case 'F':
            case 'f':
                GPA += 0*creds;
                break;
        }
    }

    printf("GPA = %.2f", GPA/total_creds);
}