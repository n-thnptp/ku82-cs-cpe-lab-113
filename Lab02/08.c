#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //options
    char size_str[3], xpep_str[3], cheese_str[3], mush_str[3];
    int size, xpep, cheese, mush;
    
    //calculate
    float cost = 0;
    float ex_cost = 0;
    float price = 0;
    int base_cost = 2;
    int fixed_cost = 5;
    int diam = 0;

    printf("Welcome to my pizza shop!!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Enter pizza size (1=s, 2=m, or 3=l): ");
    fgets(size_str, 3, stdin);
    printf("Extra pepperoni? (1=yes, 0=no): ");
    fgets(xpep_str, 3, stdin);
    printf("Extra cheese? (1=yes, 0=no): ");
    fgets(cheese_str, 3, stdin);
    printf("Extra mushroom? (1=yes, 0=no): ");
    fgets(mush_str, 3, stdin);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    size = atoi(size_str);
    xpep = atoi(xpep_str);
    cheese = atoi(cheese_str);
    mush = atoi(mush_str);

    if (xpep == 1) {
        ex_cost += 0.5;
    }
    if (cheese == 1) {
        ex_cost += 0.25;
    }
    if (mush == 1) {
        ex_cost += 0.30;
    }

    //small size = 10 << diameter
    if (size == 1) {
        diam = 10;
    }

    //medium size = 16 << diameter
    if (size == 2) {
        diam = 16;
    }

    //large size = 20 << diameter
    if (size == 3) {
        diam = 20;
    }
    
    float area = (M_PI * pow(diam, 2)) / 4;
    cost = fixed_cost + (base_cost * area) + (ex_cost * area);
    price = 1.5 * cost;

    printf("Your order costs %.2f baht.\n", price);
    printf("Thank you.");

    return 0;
}