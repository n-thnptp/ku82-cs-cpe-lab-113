/*
Calculate the value of π
from the infinite series :

    π = 4 - (4/3) + (4/5) - (4/7) + (4/9) - (4/11) + ... 

Write the program to input integer n where n > 0
and print the value of π approximated by n term of this series
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double result = 4, deno = 3, numer = 4;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i=0; i < n-1; ++i) {
        if (i % 2 == 0) {
            result -= numer / deno;
        } else {
            result += numer / deno;
        }
        deno += 2;
    }

    printf("%.10lf", result);
}