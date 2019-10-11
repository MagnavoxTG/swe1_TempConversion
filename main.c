#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    float temp = 0;
    char tempreadout[255] = "";
    int x = 0;

    // While loop is created to catch any invalid inputs
    while (x != 1) {
        // printf shows a message asking you to enter the the temperature with a C or F
        printf("\nPlease enter the temperature you want to convert with a C or F without any spaces (f.e. 25.69C): ");
        //scanf writes the input into a string (char array)
        scanf("%s", tempreadout);
        // strspan checks how many of the specified character are inside the string and gives an integer
        // strlen checks how long the string (char array) is and gives an integer
        // if they are the same then there are only allowed characters in the string
        if (strspn(tempreadout, "0123456789.CF") == strlen(tempreadout)) {
            // it is checked if the last character of the string is a C (the -1 is because arrays start at 0)
            if (tempreadout[strlen(tempreadout)-1] == 'C') {
                // the string gets cast into a float
                temp = (float)atof(tempreadout);
                // the number gets converted from C to F
                temp = temp * 1.8 + 32;
                // the new value in F gets shown to the user
                printf("Your input %.2f F", temp);
            // if its not a C it must be an F
            } else {
                // string gets cast into a float
                temp = (float)atof(tempreadout);
                // the number gets converted from F to C
                temp = (temp-32) / 1.8;
                // the new value in C gets shwon to the user
                printf("Your input in %.2f C", temp);
            }
            // x is set to 1 to break the while loop
            x = 1;
        } else {
            // error message is displayed
            printf("\nInvalid input!\n");
        }
    }
};