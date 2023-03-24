/*
ถ้ากำหนดให้ C เป็นจำนวนเชิงซ้อนแล้ว C สามารถถูกเขียนให้อยู่ในรูปของ \(C = a + bi\) โดยที่ \(i^2 = -1\) และหากกำหนดให้ \(D = c + di\) แล้ว

ผลบวกระหว่าง \(C\) และ \(D\) จะมีค่าเท่ากับ \((a+c) + (b+d)i\)
ผลคูณระหว่าง \(C\) และ \(D\) จะมีค่าเท่ากับ \((ac-bd) + (ad+bc)i\)
จงเติมโปรแกรมข้างล่างให้สมบูรณ์เพื่อคำนวณหาค่าผลบวก (add) และผลคูณ (multiply) ของค่าจำนวนเชิงซ้อน 2 จำนวนที่รับค่าเข้ามา

ตัวอย่างผลลัพธ์ที่ 1 (Input: C = 1.0 + 2.0i และ D = 2 + 3i)
    Enter C: 1.0 2.0 
    Enter D: 2 3 
    C + D = 3.0 + 5.0i
    C x D = -4.0 + 7.0i
ตัวอย่างผลลัพธ์ที่ 2 (Input: C = 2i และ D = 3i)
    Enter C: 0 2 
    Enter D: 0 3 
    C + D = 5.0i
    C x D = -6.0
ตัวอย่างผลลัพธ์ที่ 3 (Input: C = 1 + 2i และ D = -3i)
    Enter C: 1 2 
    Enter D: 0 -3 
    C + D = 1.0 - 1.0i
    C x D = 6.0 - 3.0i
*/

#include <stdio.h>

struct complex {
    float r, i;
};

struct complex add_complex(struct complex x, struct complex y) {
    return (struct complex){x.r + y.r, x.i + y.i};
}

struct complex multiply_complex(struct complex x, struct complex y) {
    return (struct complex){(x.r * y.r) - (x.i * y.i), (x.r * y.i) + (x.i * y.r)};
}

void print_complex(char *prompt, struct complex x) {
        printf("%s", prompt);
    if (!x.r && !x.i)
    {
        printf("%.1f", 0.0f);
    }
    else if (x.r)
    {
        printf("%.1f", x.r);
        if (x.i > 0)
        {
            printf(" + ");
            printf("%.1fi", x.i);
        }
        else if (x.i < 0)
        {
            printf(" - ");
            printf("%.1fi", -x.i);
        }
    }
    else if (x.i)
    {
        printf("%.1fi", x.i);
    }

    putchar('\n');
}

int main() {
    struct complex C, D, E, F;

    printf("Enter C: ");
    scanf("%f %f", &C.r, &C.i);
    printf("Enter D: ");
    scanf("%f %f", &D.r, &D.i);

    E = add_complex(C, D);
    F = multiply_complex(C, D);

    print_complex("C + D = ", E);
    print_complex("C x D = ", F);

    return 0;
}