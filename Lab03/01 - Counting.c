// Write a program that get an integer n and print the number from n down to 0 if n >= 0

#include <stdio.h>
#include <stdlib.h>

int main() {
    char n_str[5];
    int n, i;

    fgets(n_str, 5, stdin);
    n = atoi(n_str);

    for (i = n; i >= 0; --i) {
        printf("%d\n", i);
    }
}