// ตรวจสอบความถูกต้องของโปรแกรม ถ้าถูกต้องให้คัดลอกโปรแกรมใส่ด้านล่าง แต่ถ้าผิดให้แก้ไขให้ถูกต้อง

// #include <studio.h>                          <<< stdio.h
// #include <stolib.h>                          <<< stdlib.h
// int main()
// {
//     char hour_str[3], min_str[3];            <<< this line (allocated memory space too short)
//     int hour, min;

//     printf("Enter hour: "):
//     fget(hour_str, 3, stdin);

//     printf("Enter minute: "):
//     get(minstr);                             <<< this line (function fgets not get)

//     hour = atoi(hour_str);
//     minute = atoi(minstr);                   <<< this line (variable)

//     printf("Time is %d:%d, hour, minute");   <<< this line (format)
//     return 0;
// }

// -- Sample output 1 --        -- Sample output 2 --
// Enter hour: 9                Enter hour: 10
// Enter minute: 18             Enter minute: 7
// Time is 09:18                Time is 10:07

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char hour_str[4], min_str[4];
    int hour, min;

    printf("Enter hour: ");
    fgets(hour_str, 4, stdin);

    printf("Enter minute: ");
    fgets(min_str, 4, stdin);

    hour = atoi(hour_str);
    min = atoi(min_str);

    printf("Time is %02d:%02d", hour, min);
    return 0;
}