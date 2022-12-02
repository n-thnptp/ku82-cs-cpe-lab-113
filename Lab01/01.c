#include <stdio.h>

int main() {
    int computer_time = 785;
    int days = computer_time / (24 * 60); // 24*60 = 1440 (1 day)
    int hours = (computer_time % (24 * 60)) / 60;
    int mins = ((computer_time % (24 * 60)) % 60);
    printf("It is %d days %d hours and %d minutes.", days, hours, mins);
    return 0;
}