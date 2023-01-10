/*
Write the program that continuously asks for the operator (+, -, *, or /), and the operand (the next number), until the user enters a character other than the operator +, -, *, or /.
Each time the new number and the operator come in, the program computes and displays the present value by using the input operator, the last present value, and the newly-entered value. At the end, the program also displays the final value, as shown in a sample output below.

Sample Output 1
    Initial Value: 10.45

    Operator: +
    Input Value: 4
    Present Value is 14.4500

    Operator: -
    Input Value: 0.33
    Present Value is 14.1200

    Operator: *
    Input Value: 12.5
    Present Value is 176.5000

    Operator: /
    Input Value: 5.5
    Present Value is 32.0909

    Operator: @

    Finish Calculation. Final Value is 32.0909
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float ini_val, inp_val;
    char operand;

    printf("Initial Value: ");
    scanf("%f", &ini_val);
    printf("\n");

    for (int i = 0 ;; ++i) {
        printf("Operator: ");
        scanf("\n%c", &operand);

        switch (operand) {
            case '+':
                printf("Input Value: ");
                scanf("%f", &inp_val);
                ini_val += inp_val;
                printf("Present Value is %.4f\n", ini_val);
                break;
            case '-':
                printf("Input Value: ");
                scanf("%f", &inp_val);
                ini_val -= inp_val;
                printf("Present Value is %.4f\n", ini_val);
                break;
            case '*':
                printf("Input Value: ");
                scanf("%f", &inp_val);
                ini_val *= inp_val;
                printf("Present Value is %.4f\n", ini_val);
                break;
            case '/':
                printf("Input Value: ");
                scanf("%f", &inp_val);
                ini_val /= inp_val;
                printf("Present Value is %.4f\n", ini_val);
                break;
            default:
                printf("\n");
                printf("Finish Calculation. Final Value is %.4f", ini_val);
                return 0;
        }
        printf("\n");
    }
}