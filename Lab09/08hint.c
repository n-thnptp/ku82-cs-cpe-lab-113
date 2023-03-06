#include <stdio.h>
#include <string.h>

int main() {
    FILE *filestream = fopen("filename.txt", "r");              /* "r" for read (must be double quote) */

    int stockType = 0;
    fscanf(filestream, "%d", &stockType);                       /* file scanf(from, format, variable to store) */

    char buffer[100];                                           /* for each line inside a file */
    fgets(buffer, sizeof(buffer), filestream);                  /* fgets(store, size, read from); use loop to grab each line in a file */

    char *token;
    token = strtok(buffer, ",");
    token = strtok(NULL, ",");                                  /* moves to the next delimiter */
    token = strtok(NULL, ",");                                  /* moves to the next delimiter */

    fclose(filestream);                                         /* ALWAYS close the file after done*/
}