/* 
Write a program to find out how many days a kid can collect money up to specific amount.

First, the program asks the kid the goal amount of money he aims to collect. From that, everyday, the program asks the kid to enter leftover money from his stipend and reports (1) the total amount on that day, (2) remaining money to collect. When the goal money is reached, the program will report how many it takes to collect money.

Assume the kid always enters positive amount of money.

Output :
    Enter your goal amount: 100.00
    Enter money collected today: 20.00
    Total money collected up to day 1 is 20.00. You need 80.00 more.
    Enter money collected today: 10.00
    Total money collected up to day 2 is 30.00. You need 70.00 more.
    Enter money collected today: 15.00
    Total money collected up to day 3 is 45.00. You need 55.00 more.
    Enter money collected today: 30.00
    Total money collected up to day 4 is 75.00. You need 25.00 more.
    Enter money collected today: 25.00
    Congratulations! You take 5 days to reach your goal.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char goal_str[15], collected_str[15];
    float goal = 0, collected = 0, needed = 0;
    int i = 1;

    printf("Enter your goal amount: ");
    fgets(goal_str, 15, stdin);
    goal = atof(goal_str);

    for (i; collected < goal; ++i) {
        printf("Enter money collected today: ");
        fgets(collected_str, 15, stdin);
        collected += atof(collected_str);

        if (collected < goal) {
            printf("Total money collected up to day %d is %.2f. You need %.2f more.\n", i, collected, goal - collected);
        } else {
            break;
        }
    }

    if (i == 1) {
        printf("Congratulations! You take %d day to reach your goal.", i);
    } else {
        printf("Congratulations! You take %d days to reach your goal.", i);
    }
}