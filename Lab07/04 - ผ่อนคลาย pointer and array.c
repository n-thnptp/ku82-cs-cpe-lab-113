#include <stdio.h>

int main() {
    int a[10] = {0, 1}, *ptr;
    int k;
    ptr = a + 2;
    for (k = 2; k < 10; k++)
        a[k] = a[k - 1] + a[k - 2];

    for (int i = 0; i < 10; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    /*
    var = 3000;
    ptr = &var;     // take the address of var
    val = *ptr;     // take the value available at ptr
    */
    
    printf("size of int a[10] is %zu\n", sizeof(a));
    printf("address of int a[0] is %p\n\n", a);
    
    printf("value inside of *ptr is         %d\n", *ptr);
    printf("value inside of *(ptr+1) is     %d\n", *(ptr+1));
    printf("value inside of ptr is          %p\n", ptr);        // ptr+2 is not actually +2 but +8 (4*2) in bytes
    printf("value inside of ptr[3] is       %d\n", ptr[3]);
    printf("value inside of ptr[-1] is      %d\n", ptr[-1]);
    printf("value inside of &a[4] is        %p\n", &a[4]);      // + 10 address from a[0]
    printf("value inside of *(ptr+2) is     %d\n", *(ptr+2));
    printf("value inside of ptr+3 is        %p\n", ptr+3);      // FFE8 + (3*2) = FFF4
    printf("value inside of &ptr[3] is      %p\n", &ptr[3]);
    printf("value inside of ptr[5] is       %d\n", ptr[5]);
}