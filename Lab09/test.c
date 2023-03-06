// Another example program to demonstrate working
// of enum in C
#include<stdio.h>
 
enum year {
    Jan, Feb, Mar, Apr, May, Jun, Jul,
    Aug, Sep, Oct, Nov, Dec
};
 
int main()
{
    enum year month;
    month = Jan;
    printf("%d\n", month);
       
    return 0;
}