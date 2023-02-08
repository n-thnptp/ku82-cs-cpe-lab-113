#include <stdio.h>

int main() {

    int a=4, b=3, c, d, e;
    float f=2,g=5, h, i, j, k, test = 2.33;

    c = f/b*f;                 // c = 2/(4*2) 
    h = a++/(float)b;          // h = 4/3 
    j = (float)c/h--;          // j = 1/1.33 
    d = b*h/c;                 // d = (3*0.33) / 1
    i = d*f+h--;               // i = (1*2) + 0.33
    e = a*d++/i;               // e = (4*1) / 2.33
    k = (int)i*d/(float)a;     // k = (2*2) / 5.00

    /* 
    i++ / i-- = uses the value first then increment/decrement

    c = "1"
    h = "1.33"          (uses value "a" first then increments)
    j = "0.75"
    d = "1"             (real value is 3 * 0.33 / 1 = "0.99" because h-- on previous line)
    i = "2.33"
    e = "2"             (true value = "1.7167")
    k = "0.80"          (a++ and d++ on the previous line. a = 5, d = 2)
    */
   // printf("k = %d * %d / %.2f", (int)i, d,(float)a);
   
}
