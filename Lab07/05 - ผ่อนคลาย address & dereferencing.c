#include <stdio.h>

int main() {
    int i, j=12;
    int *pi, *pj=&j;
    *pj = j+3;
    i = *pj+7;
    pi = pj;
    *pi = i+j;

    printf("value inside of &i is       %p\n", &i);         // stores address of i
    printf("value inside of &j is       %p\n", &j);         // stores address of j
    printf("value inside of pj is       %p\n", pj);         // stores address of j
    printf("value inside of *pj is      %d\n", *pj);        // dereferences pj (grabs value inside of it)
    printf("value inside of i is        %d\n", i);
    printf("value inside of pi is       %p\n", pi);         // stores address of pj
    printf("value inside of *pi is      %d\n", *pi);
    printf("value inside of pi+2 is     %p\n", pi+2);       // supposed to be address + (4*2)
    printf("value inside of *pi+2 is    %d\n", *pi+2);      
    printf("value inside of *pi+*pj is  %d\n", *pi+*pj);
}