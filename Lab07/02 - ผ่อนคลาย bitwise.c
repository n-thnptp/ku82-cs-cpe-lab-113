#include <stdio.h>

int main() {
    int a=5, b=2;

    /*
    1. a++%b>>2        Ans1 = 0 
    2. a|b+3           Ans2 = 5 
    3. (b<<1)*a        Ans3 = 20 
    4. a+(7&b)         Ans4 = 7
    5. --a*b%3<<2      Ans5 = 8 
    6. (a+5*b>>1)<<2   Ans6 = 28 
    */

   // >> = right shift ; << = left shift
   printf("%d", (a+5*b>>1)<<2);
}