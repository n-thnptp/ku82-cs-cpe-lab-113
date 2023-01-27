/*
อัซคาบัน เป็นสถานที่กักกันและลงโทษผู้ที่ถูกตัดสินว่ามีความผิดร้ายแรงในโลกเวทมนตร์ ในแต่ละวันจะต้องมีนักโทษจำนวนหนึ่งถูกประหารชีวิตด้วยจุมพิตของผู้คุมวิญญาณ โดยจะสุ่มเลือกนักโทษมา numPrisoners คน ตั้งแต่ 5 คนขึ้นไป แต่ไม่เกิน 100 คน และให้แต่ละคนมีหมายเลข 1 ถึง numPrisoners จากนั้นผู้คุมวิญญาณจะสุ่มเลข m ซึ่งมีค่าตั้งแต่ 2 ถึง 5

ในการประหารชีวิตนักโทษ นักโทษจะถูกจับให้เข้าแถวเป็นวงกลม เริ่มจากคนที่ได้รับหมายเลข 1 ไล่ไปจนถึง numPrisoners ` จากนั้นจะให้นับเลข 1, 2, ..., m ไปตามลำดับ หากใครนับเลขตรงกับเลข m จะถูกนำตัวไปประหารทันที

เขียนโปรแกรมเพื่อแสดงลำดับหมายเลขของนักโทษแห่งอัซคาบันที่ถูกนำไปประหารจากคนแรกไปหาคนสุดท้ายตามลำดับ
โดยโปรแกรมจะรับข้อมูลดังนี้
    บรรทัดที่ 1 รับจำนวนเต็มบวก numPrisoners
    บรรทัดที่ 2 รับจำนวนเต็มบวก m

ตัวอย่างโปรแกรม 1
    10
    3
    3 6 9 2 7 1 8 5 10 4
ตัวอย่างโปรแกรม 2
    10
    4
    4 8 2 7 3 10 9 1 6 5
*/

#include <stdio.h>

void removeKilled(int *array, int size, int killedPrisoner);

int main()
{
    int numPrisoners, m, i;

    scanf("%d", &numPrisoners);
    scanf("%d", &m);

    int prisoners[numPrisoners];
    int killed[numPrisoners];

    // generate array 1 to numPrisoners
    for (i = 0; i < numPrisoners; i++)
    {
        prisoners[i] = i + 1;
    }

    int *killerPtr = &prisoners[0];

    // printf("@@ &prisoners[0] %d\n", (int) &prisoners[0]);
    // printf("@@ &prisoners[%d] %d\n", numPrisoners - 1, (int) &prisoners[numPrisoners - 1]);

    // Select prisoner to be killed
    for (i = 0; i < numPrisoners; i++)
    {
        int k = numPrisoners - i;
        killerPtr += (m - 1);
        if (killerPtr >= prisoners + k)
        {
            killerPtr = &prisoners[(killerPtr - prisoners) % k];
        }

        // append number of prisoner who is killed to array `killed`
        killed[i] = *killerPtr;
        // remove number killed prisoner from array `prisoners`
        removeKilled(&prisoners[0], numPrisoners, *killerPtr);
    }

    for (i = 0; i < numPrisoners; i++)
    {
        printf("%d ", killed[i]);
    }
    return 0;
}

void removeKilled(int *array, int size, int killedPrisoner)
{
    int i = 0, j = 0, var;
    for (i = 0; i < size; i++)
    {
        if (array[i] == killedPrisoner)
        {
            array[i] = 0;
        }
    }

    for (i = 0; i < size; i++)
    {
        if (array[i] != 0)
        {
            var = array[i];
            array[i] = array[j];
            array[j] = var;
            j++;
        }
    }
}
