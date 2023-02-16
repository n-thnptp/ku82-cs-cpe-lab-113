#include <stdio.h>

/*
    loop through the input, if found either I, V, X (caps) then
    change the flag for slicing to 1, if the next character is not I, V, or X then change the flag back to 0
    convert the sliced string (romanian number) then put it to output[]
*/
void roman2arabic(char input[], char output[]) {
    int i = 0, j, romanFlag = 0, count, addIndex;
    int converted = 0;
    char sliceStr[5];

    while (input[i]) {
        // printf("%c", input[i]);
        if (input[i] == 'I' || input[i] == 'V' || input[i] == 'X') {
            // printf(" (flag raised)");
            romanFlag = 1;
        }
        // printf("\n");
        if (romanFlag == 1) {
            addIndex = 0;
            count = 0;
            
            for (int j = i; ;j++) {
                if (input[j+1] == 'I' || input[j+1] == 'V' || input[j+1] == 'X') {
                    count++;
                } else {
                    if (count == 0) {
                        sliceStr[addIndex] = input[i];
                        sliceStr[addIndex+1] = '\0';
                        break;
                    } else {
                        for (addIndex = 0; addIndex <= count; ++addIndex) {
                            sliceStr[addIndex] = input[i+addIndex];
                        }
                    }
                    sliceStr[addIndex] = '\0';
                    romanFlag = 0;
                    break;
                }
            }

            j = 0;
            while (sliceStr[j]) {
                switch (sliceStr[j]) {
                    case 'I':
                        converted += 1;
                        break;
                    case 'V':
                        converted += 5;
                        break;
                    case 'X':
                        converted += 10;
                        break;
                }
                j++;
            }

        }
        i++;
    }
    // printf("sliced = %s\n", sliceStr);
    printf("%s\n%d\n", sliceStr, converted);
}

int main() {
    char input[80], output[80];
    printf(" Input: ");
    gets(input); /* read a line of characters from the input to "input" variable */
    roman2arabic(input, output);
    printf("Output: %s\n", output);

    return 0;
}