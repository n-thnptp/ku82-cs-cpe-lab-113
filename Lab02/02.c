#include <stdio.h>
#include <stdlib.h>

int main() {
    char stamp_str[50], cost_str[50];
    int stamp;
    float cost;

    fgets(stamp_str, 50, stdin);
    fgets(cost_str, 50, stdin);

    stamp = atoi(stamp_str);
    cost = atof(cost_str);

    if (stamp == 1) {

        float total = cost - ((cost * 10) / 100);

        printf("You get 10 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 1);

    } else if (stamp == 2) {

        float total = cost - ((cost * 15) / 100);

        printf("You get 15 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 2);

    } else if ((stamp >= 3) && (stamp < 6)) {

        float total = cost - ((cost * 20) / 100);

        printf("You get 20 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 3);

    } else if ((stamp >= 6) && (stamp < 9)) {
        
        float total = cost - ((cost * 30) / 100);

        printf("You get 30 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 6);
        
    } else if (stamp >= 9) {

        float total = cost - ((cost * 40) / 100);

        printf("You get 40 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", total);
        printf("And you have %d stickers left.", stamp - 9);
        
    } else {

        printf("You get 0 percents discount.\n");
        printf("Total amount due is %.2f Baht.\n", cost);
        printf("And you have 0 stickers left.");
    
    }

    return 0;
}