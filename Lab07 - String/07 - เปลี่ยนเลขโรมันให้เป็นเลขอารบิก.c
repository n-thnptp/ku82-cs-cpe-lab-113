/*
เปลี่ยนเลขโรมันให้เป็นเลขอารบิก
จงเขียนฟังก์ชันเพื่อเปลี่ยนเลขโรมันที่มีค่าอยู่ในช่วงเพียง 1 ถึง 9 (ซึ่งก็คือ I,II,III,IV,V,VI,VII,VIII,IX ตามลำดับ) ทั้งหมดที่ปรากฏในสตริงที่รับผ่านฟังก์ชันเข้ามา ให้กลายเป็นเลขอารบิก 1 หลัก แล้วบันทึกผลที่ได้ลงในตัวแปรอีกตัวที่ถูกส่งเข้ามาด้วยในฟังก์ชัน

ตัวอย่างผลลัพธ์
     Input: There are III eggs on the table.
    Output: There are 3 eggs on the table.
     Input: II + III = V
    Output: 2 + 3 = 5
*/

#include <stdio.h>
void roman2arabic(char input[], char output[]) {

    int convertToInt(char c) {
        switch(c) {
          case 'I':
              return 1;
          case 'V':
              return 5;
          case 'X':
              return 10;
          default:
              return 0;
        }
    };

    int i= 0, total = 0;
    int current, next, length;
    char *str = input;
    char buffer[80];

    while (*str != '\0') {
        // checks if current string is I, V, or X
        // then convert the roman number to integer and put it to total
        if (*str == 'I' || *str == 'V' || *str == 'X') {
            current = convertToInt(*str);
            next = convertToInt(*(str + 1));
            if (current < next) {
                total -= current;
            } else {
                total += current;
            }
            
        } else if (total != 0) {
            length = sprintf(buffer, "%d", total);
            for (int j = 0; j < length; j++) {
                output[i++] = buffer[j];
            }

            output[i++] = *str;
            total = 0;
        } else {
            output[i++] = *str;
        }
        str++;
    }

    if (total != 0) {
        length = sprintf(buffer, "%d", total);
        for (int j = 0; j < length; j++) {
            output[i++] = buffer[j];
        }
    }
    output[i] = '\0';           /* end */
}

int main() {
    char input[80], output[80];
    printf(" Input: ");
    gets(input); /* read a line of characters from the input to "input" variable */
    roman2arabic(input, output);
    printf("Output: %s\n", output);

    return 0;
}