// 082024 CS310-001 Case Study 1 Exemplar
// Pink Otters
// The following program is a tool to convert binary numbers to decimal numbers
// The program has a full UI through the terminal
// The program was written on and is designed to be run by a UNIX machine (OSX, Linux or any machine with a full terminal)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void strrev(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

void num_to_decimal(char* num, int base) {
    int dec_num = 0;
    strrev(num);
    for (int i = 0; i < strlen(num); i++) {
        dec_num = dec_num + (num[i] - 48) * ((int) pow((double) base, (double) i));
    }
    char* new_num = malloc(8 * sizeof(int));
    sprintf(new_num, "%d", dec_num); 
    for (int i = 0; i < strlen(new_num); i++) {
        num[i] = 0;
    }
    strcpy(num, new_num);
    free(new_num);
}

int main() {
    while(1){
        char* num = malloc(8 * sizeof(int));
        printf("Please enter a Binary number\nEnter 'exit' to exit the program.\n");
        printf(">> ");
        scanf("%s", num);
        int good_num = 1;
        if ((int) strlen(num) <= 32) {
            if (!strcmp(num, "exit")) {
                break;
            } else {
                for (int i = 0; i < strlen(num); i++) {
                    if (num[i] != 48 && num[i] != 49) {
                        printf("This is not a Binary number. Please try again.\n");
                        good_num = 0;
                        break;
                    }
                }
                if (good_num) {
                    printf("the Converted number is ");
                    num_to_decimal(num, 2);
                    printf(num);
                    printf("\n");
                }
            }
        } else {
            printf("This number is too large. Please try again\n");
        }
    }
    printf("Goodbye!\n");
    return 0;
}
