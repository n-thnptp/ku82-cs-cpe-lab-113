// ASCII Table
// digits = 48 - 57
// upper = 65 - 90
// lower = 97 - 122

#include <stdio.h>

int main() {
    char c;
    c = getchar();

    if (c >= 48 && c <= 57) {
        printf("Output: digit");
    } else if (c >= 65 && c <= 90) {
        printf("Output: upper case");
    } else if (c >= 97 && c <= 122) {
        printf("Output: lower case");
    } else {
        printf("Output: other");
    }

    return 0;
}