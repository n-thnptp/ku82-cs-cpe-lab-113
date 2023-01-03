/*
Your job is to write a program to draw a triangle.

The program receives a number n as a height of triangle.

Then the program print a triangle with the height = n and base = (2n-1) using *, with the base on the left of the screen, as in the examples.

Sample output 1
    2
    *
    **
    *
Sample output 2
    9
    *
    **
    ***
    ****
    *****
    ******
    *******
    ********
    *********
    ********
    *******
    ******
    *****
    ****
    ***
    **
    *
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char n_str[5];
    int n, count, rev = 3;

    fgets(n_str, 5, stdin);
    n = atoi(n_str);
    count = n - (n-1);

    for (int i=0; i < (2 * n) - 1; ++i) {
        if (count <= n) {
            for (int j=0; j < count; ++j) {
                printf("*");
            }
            count += 1;
        } else {
            for (int k=0; k <= count-rev; ++k) {
                printf("*");
            }
            rev += 1;
        }
        printf("\n");
    }
}