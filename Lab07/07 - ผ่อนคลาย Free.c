#include <stdio.h>

int main() {
    float **ptr;
    int i,m,n;
    ptr=(float**)malloc(m*sizeof(float*));
    for(i=0;i<m;i++)
        ptr[i]=(float*)malloc(n*sizeof(float));
    /* Do something with ptr */

    /*......Ans1......*/
    /*......Ans2......*/
    /*......Ans3......*/

    for(i = 0; i < m; i++)          // Ans1
        free(ptr[i]);               // Ans2
    free(ptr);                      // Ans3
}