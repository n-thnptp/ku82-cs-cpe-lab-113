#include <stdio.h>
#include <stdlib.h>

int main() {
    char sal_str[12];
    float total = 0;

    fgets(sal_str, 12, stdin);

    float sal = atof(sal_str);

    if (sal < 0) {
        printf("Error: Salary must be greater or equal to 0");
    } else {
        if (sal <= 300000) {
            total += (sal * 5) / 100;
        } else {
            total += ((300000 * 5) / 100) + (((sal - 300000) * 10) / 100);
        }
        printf("%.2f", total);
    }
    
    return 0;
}