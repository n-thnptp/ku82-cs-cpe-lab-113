#include <stdio.h>

/*
    loop through the input, if found either I, V, X (caps) then
    change the flag for slicing to 1, if the next character is not I, V, or X then change the flag back to 0
    convert the sliced string (romanian number) then put it to output[]
*/
void roman2arabic(char input[], char output[]) {
    int i = 0, j, romanFlag = 0, count, addIndex, start;
    int convertedNum = 0, isInFront = 0;
    char sliceStr[5];

    while (input[i]) {
        if (input[i] == 'I' || input[i] == 'V' || input[i] == 'X') {
            romanFlag = 1;
        } else {
            output[i] = input[i];
        }

        if (romanFlag == 1) {
            addIndex = 0;
            count = 0;
            
            // count roman numeric length
            j = i;
            while (input[j]) {
                if (input[j] == 'I' || input[j] == 'V' || input[j] == 'X') {
                    count++;
                } else if (input[j+1] != 'I' || input[j+1] != 'V' || input[j+1] != 'X') {
                    break;
                }
                j++;
            }

            // string slicing
            addIndex = 0;
            for (start = i; start <= i+count-1; start++) {
                sliceStr[addIndex] = input[start];
                addIndex++;
            }
            sliceStr[addIndex] = '\0';

            // convert sliced string to arabic number (fix this)
            if (sliceStr == "I") {
                convertedNum = 1;
            } else if (sliceStr == "II") {
                convertedNum = 2;
            } else if (sliceStr == "III") {
                convertedNum = 3;
            } else if (sliceStr == "IV") {
                convertedNum = 4;
            } else if (sliceStr == "V") {
                convertedNum = 5;
            } else if (sliceStr == "VI") {
                convertedNum = 6;
            } else if (sliceStr == "VII") {
                convertedNum = 7;
            } else if (sliceStr == "VIII") {
                convertedNum = 8;
            } else if (sliceStr == "IX") {
                convertedNum = 9;
            }

            // send it to output? declare new output index?
        }
        i++;
    }
}

int main() {
    char input[80], output[80];
    printf(" Input: ");
    gets(input); /* read a line of characters from the input to "input" variable */
    roman2arabic(input, output);
    printf("Output: %s\n", output);

    return 0;
}