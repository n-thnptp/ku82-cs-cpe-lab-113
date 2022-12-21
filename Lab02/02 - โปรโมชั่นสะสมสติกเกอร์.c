// ห้างสรรพสินค้าแห่งหนึ่งจัดโปรโมชั่นแจกสติกเกอร์ให้ลูกค้าสะสมเพื่อใช้เป็นส่วนลดได้ โดยจำนวนสติกเกอร์ที่สะสมได้จะให้ส่วนลดที่แตกต่างกันไป ตามตารางต่อไปนี้

// สะสมครบ 1 ดวง	รับส่วนลด 10%
// สะสมครบ 2 ดวง	รับส่วนลด 15%
// สะสมครบ 3 ดวง	รับส่วนลด 20%
// สะสมครบ 6 ดวง	รับส่วนลด 30%
// สะสมครบ 9 ดวง	รับส่วนลด 40%
// พิจารณากรณีที่ลูกค้ามีสติกเกอร์ 5 ดวง ลูกค้าจะได้รับส่วนลดเพียง 20% เท่านั้น เนื่องจากสติกเกอร์ไม่เพียงพอที่จะได้ลด 30%

// จงเขียนโปรแกรมเพื่อรับจำนวนสติกเกอร์ที่ลูกค้าสะสมได้ (บรรทัดแรก) และราคาสินค้าที่ลูกค้าต้องการซื้อ (บรรทัดที่สอง) แล้วคำนวณส่วนลดที่ลูกค้าได้รับ (บรรทัดที่สาม)
// จำนวนเงินหลังหักส่วนลดที่ลูกค้าต้องชำระ (บรรทัดที่สี่) และ จำนวนสติกเกอร์คงเหลือ (บรรทัดที่ห้า)

// Expected output:
// 0                                        | 20                                       <<< input
// 1000.0                                   | 1000.0                                   <<< input
// You get 0 percents discount.             | You get 40 percents discount.
// Total amount due is 1000.00 Baht.        | Total amount due is 600.00 Baht.
// And you have 0 stickers left.            | And you have 11 stickers left.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char stamp_str[50], cost_str[50];
    int stamp;
    float cost;

    fgets(stamp_str, 50, stdin);
    fgets(cost_str, 50, stdin);

    stamp = atoi(stamp_str);
    cost = atof(cost_str);

    if (stamp == 1) {

        float total = cost - ((cost * 10) / 100);

        printf("You get 10 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 1);

    } else if (stamp == 2) {

        float total = cost - ((cost * 15) / 100);

        printf("You get 15 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 2);

    } else if ((stamp >= 3) && (stamp < 6)) {

        float total = cost - ((cost * 20) / 100);

        printf("You get 20 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 3);

    } else if ((stamp >= 6) && (stamp < 9)) {
        
        float total = cost - ((cost * 30) / 100);

        printf("You get 30 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 6);
        
    } else if (stamp >= 9) {

        float total = cost - ((cost * 40) / 100);

        printf("You get 40 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 9);
        
    } else {

        printf("You get 0 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", cost);
        printf("And you have 0 stickers left.");
    
    }

    return 0;
}