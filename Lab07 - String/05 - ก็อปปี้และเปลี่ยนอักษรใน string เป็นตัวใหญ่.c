/*
ให้นิสิตเขียนฟังก์ชันชื่อ stoupper() ซึ่งจะรับสตริงมาหนึ่งตัว จากนั้นจะสร้างสตริงก์ใหม่ที่นำอักษรภาษาอังกฤษตัวเล็กจากสตริงก์เก่ามาเปลี่ยนเป็นอักษรตัวใหญ่ (Capital Letter) อักษรที่ไม่ใช่ตัวเล็กนั้นจะเหมือนเดิม จากนั้นจะรีเทิร์น pointer ไปที่สตริงใหม่นี้

นิสิตไม่สามารถใช้ฟังก์ชันใดใน string.h ได้ แต่สามารถใช้ฟังก์ชันใน ctype.h ได้ (เช่น toupper() เป็นต้น)

ตัวอย่าง 1
    Hello,World
    HELLO,WORLD
ตัวอย่าง 2
    c3t-WiCoS
    C3T-WICOS
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define static "use malloc"

char* stoupper(const char *s) {
    int i = 0;
    char* charOut;
    charOut = (char*) malloc(100 * sizeof(char));       /* allocate memory to put characters in and return */

    while (s[i] != '\0') {                              /* loop through each char in string */
        // printf("charOut[%d] = %c\n", i, s[i]);       /* debug (ignore) */
        charOut[i] = toupper(s[i]);
        i++;
    }
    charOut[i] = '\0';                                  /* put an end character */

    return charOut;
}

int main(){
	char s[100];
	char* result;

	scanf("%s",s);
	result = stoupper(s);
        if (result == s) printf("ERROR.\n");
	printf("%s\n",result);
}