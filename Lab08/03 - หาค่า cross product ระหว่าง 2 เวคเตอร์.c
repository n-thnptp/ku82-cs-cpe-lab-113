/*
ถ้ากำหนดให้เวกเตอร์ vector_u = (u_x, u_y, u_z) และเวกเตอร์ vector_v = (v_x, v_y, v_z), ค่า cross product ระหว่างเวกเตอร์ vector_u และเวกเตอร์ vector_v,
ซึ่งสามารถเขียนอยู่ในรูปของ vector_u * vector_v, จะมีค่าเป็นเวกเตอร์ซึ่งมีค่าเท่ากับ:

vector_u * vector_v = (u_y*v_z - u_z*v_y, u_z*v_x - u_x*v_z, u_x*v_y - u_y*v_x)\]
จงเติมโปรแกรมข้างล่างให้สมบูรณ์เพื่อคำนวณหาค่า cross product ระหว่าง 2 เวกเตอร์ที่รับค่าเข้ามา

ตัวอย่างผลลัพธ์ที่ 1
    Enter u: 1 2 3
    Enter v: 2 3 4
    u x v = -1.0 2.0 -1.0
ตัวอย่างผลลัพธ์ที่ 2
    Enter u: 1.0 2.5 3.5
    Enter v: 0.0 0.0 1.0
    u x v = 2.5 -1.0 0.0
*/

#include <stdio.h>

struct vector {
    float vector_u[3];
    float vector_v[3];
};

int main() {
    struct vector vector;
    float result_x, result_y, result_z;

    // vector u: x, y, z
    printf("Enter u: ");
    scanf("%f %f %f", &vector.vector_u[0], &vector.vector_u[1], &vector.vector_u[2]);
    // vector v: x, y, z
    printf("Enter v: ");
    scanf("%f %f %f", &vector.vector_v[0], &vector.vector_v[1], &vector.vector_v[2]);

    result_x = (vector.vector_u[1] * vector.vector_v[2]) - (vector.vector_u[2] * vector.vector_v[1]);
    result_y = (vector.vector_u[2] * vector.vector_v[0]) - (vector.vector_u[0] * vector.vector_v[2]);
    result_z = (vector.vector_u[0] * vector.vector_v[1]) - (vector.vector_u[1] * vector.vector_v[0]);

    printf("u x v = %.1f %.1f %.1f", result_x, result_y, result_z);

    return 0;
}