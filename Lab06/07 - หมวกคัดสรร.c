/*
ณ โรงเรียนสอนเวทมนตร์ศาสตร์แห่งหนึ่ง นักเรียนที่ได้รับเลือกเพื่อเข้าเรียนในชั้นปีที่ 1 ของโรงเรียน จะต้องถูกคัดเลือกเข้าไปอยู่ประจำบ้านต่าง ๆ ด้วยหมวกคัดสรร
โดยจะต้องคัดเลือกทีละคน จากรายชื่อที่อยู่ในมือของศาสตราจารย์ท่านหนึ่ง
นักเรียน num คนที่ได้รับคัดเลือกให้เข้าเรียน จะมีหมายเลขประจำตัวตั้งแต่ 1 ถึง num แต่การเรียกชื่อจะขึ้นอยู่กับดุลยพินิจของศาสตราจารย์

จงเขียนโปรแกรมเพื่อแสดงคนที่เหลืออยู่ในแถวตามลำดับ โดยเริ่มต้น บรรทัดที่ 1 จะรับจำนวนเต็มบวก num (num <= 100) ซึ่งเป็นจำนวนนักเรียนทั้งหมด
จากนั้น บรรทัดที่ 2 จะรับจำนวนเต็มบวก count (count <= num) ซึ่งเป็นจำนวนนักเรียนที่จะถูกคัดเลือกด้วยหมวกคัดสรร
และ บรรทัดที่ 3 จะรับจำนวนเต็มบวก count จำนวน คั่นด้วย space ซึ่งเป็นหมายเลขประจำตัวนักเรียนที่ถูกคัดเลือกด้วยหมวกคัดสรร

เขียนฟังก์ชัน removeTarget(int *array, int size, int target) เพื่อลบ target ออกจาก array ที่ส่งเข้ามา และต่อท้าย array ด้วย 0

ตัวอย่างโปรแกรม 1
    10
    2
    1 10
    2 3 4 5 6 7 8 9 0 0 
ตัวอย่างโปรแกรม 2
    14
    4
    9 10 13 14
    1 2 3 4 5 6 7 8 11 12 0 0 0 0 
*/

#include <stdio.h>

void removeTarget(int *array, int size, int target);

int main() {
    int num, count, target, i;

    scanf("%d", &num);
    scanf("%d", &count);

    int numbers[num];
    int *numbersPtr = &numbers[0];

    // initialize array numbers from 1 to num by numbersPtr
    for (i = 1; i <= num; numbersPtr++, i++) {
        *numbersPtr = i;
    }

    // loop through count
    for (i = 0; i < count; i++) {
        scanf("%d", &target);
		removeTarget(&numbers[0], num, target);
    }

    numbersPtr = &numbers[0];

    // print elements in numbers using numberPtr
    for (i = 0; i < num; numbersPtr++, i++) {
        printf("%d ", *numbersPtr);
    }
    puts("");
	return 0;
}

void removeTarget(int *array, int size, int target)
{
    for (int i = 0; i < size; i++) {
        if (*(array + i) == target) {
            for (; i < size; i++) {
                *(array + i) = *(array + (i+1));
            }
            *(array + (size - 1)) = 0;
            break;
        }
    }
}