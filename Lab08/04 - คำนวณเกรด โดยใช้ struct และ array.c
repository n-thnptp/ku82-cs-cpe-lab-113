/*
คำนวณเกรดโดยเก็บข้อมูลใน struct
จงเขียนโปรแกรมคำนวณเกรด โดยให้นิยาม struct ที่ใช้เก็บคะแนนสอบของนิสิต และสร้าง array ของ struct นี้ขึ้นมาโดยมีขนาด 5 elements รับข้อมูลเข้าจากผู้ใช้
โดยจะมีข้อมูล ID ของนิสิต คะแนนสอบมิดเทอมและไฟนอล จากนั้นให้เรียกฟังก์ชัน calculateGrade ซึ่งจะคำนวณเกรดให้โดยมีหลักการดังนี้
    * ถ้าคะแนนเท่ากับ 80 คะแนนหรือมากกว่า นิสิตจะได้เกรด A
    * ถ้าคะแนนเท่ากับ 70 ถึง 79 คะแนนจะได้เกรด B
    * ถ้าคะแนนเท่ากับ 60 ถึง 69 คะแนนจะได้เกรด C
    * ถ้าคะแนนเท่ากับ 50 ถึง 59 คะแนนจะได้เกรด D
    * ถ้าคะแนนต่ำกว่านั้นจะได้เกรด F
    * จากนั้นให้พิมพ์ ID และเกรดของนิสิตทีละคนเรียงตามลำดับข้อมูลที่นำเข้า

ตัวอย่างผลลัพธ์ที่ 1
    Enter Student ID: 5610456784
    Enter Student Midterm: 26
    Enter Student Final: 37
    Enter Student ID: 5610469821
    Enter Student Midterm: 40
    Enter Student Final: 37
    Enter Student ID: 5610457893
    Enter Student Midterm: 10
    Enter Student Final: 6
    Enter Student ID: 5610475947
    Enter Student Midterm: 26
    Enter Student Final: 35
    Enter Student ID: 5610438273
    Enter Student Midterm: 30
    Enter Student Final: 25
    Student ID 5610456784 receives grade C.
    Student ID 5610469821 receives grade B.
    Student ID 5610457893 receives grade F.
    Student ID 5610475947 receives grade C.
    Student ID 5610438273 receives grade D.
*/

#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 5

struct StudentGrades {
    char student_id[11];
    int score;
};

char calculateGrade(int score) {
    char grade;

    if (score >= 80) {
        grade = 'A';
    } else if (score >= 70 && score <= 79) {
        grade = 'B';
    } else if (score >= 60 && score <= 69) {
        grade = 'C';
    } else if (score >= 50 && score <= 59) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    return grade;
}

int main() {
    struct StudentGrades student_arr[ARRAY_SIZE];
    char student_id[11];
    int mid_score, final_score;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter Student ID: ");
        scanf("%s", student_id);
        printf("Enter Student Midterm: ");
        scanf("%d", &mid_score);
        printf("Enter Student Final: ");
        scanf("%d", &final_score);

        strcpy(student_arr[i].student_id, student_id);
        student_arr[i].score = mid_score + final_score;
    }

    for (int j = 0; j < ARRAY_SIZE; j++) {
        printf("Student ID %s receives grade %c.\n", student_arr[j].student_id, calculateGrade(student_arr[j].score));
    }
}