// 082024 CS310-001 Case Study 1 Exemplar
// Pink Otters


// The following program is a tool to convert any number from one numeric base to another
// Supported numeric bases include: Decimal, Hexadecimal, Binary, Octal
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

void hex_to_decimal(char* num) {
    int dec_num = 0;
    strrev(num);
    for (int i = 0; i < strlen(num); i++) {
        if (num[i] >= 48 && num[i] <= 57) {
            dec_num = dec_num + (num[i] - 48) * ((int) pow((double) 16, (double) i));
        } else if (num[i] >= 65 && num[i] <= 70) {
            dec_num = dec_num + (num[i] - 55) * ((int) pow((double) 16, (double) i));
        } else {
            printf("Error Processing Hexadecimal number");
        }
    }
    char* new_num = malloc(8 * sizeof(int));
    sprintf(new_num, "%d", dec_num); 
    for (int i = 0; i < strlen(new_num); i++) {
        num[i] = 0;
    }
    strcpy(num, new_num);
}

void decimal_to_binary(char* num) {
    int int_num = atoi(num);
    strrev(num);
    for (int i = 30; i >= 0; i--) {
        if (((int) pow((double) 2, (double) i)) <= int_num) {
            num[i] = 49;
            int_num = int_num - ((int) pow((double) 2, (double) i));
        } else {
            num[i] = 48;
        }
    }
    strrev(num);
    int index = 0;
    for (int i = 0; i < strlen(num); i++) {
        if (i < strlen(num) - 1) {
            if (num[i] == 49) {
                index = i;
                break;
            }
        } else {
            strcpy(num, "0");
        }
    }
    char* temp_str = malloc(16 * sizeof(char));
    strcpy(temp_str, num + index);
    for (int i = 0; i < strlen(num); i++) {
        num[i] = 0;
    }
    strcpy(num, temp_str);
    free(temp_str);
}

void binary_to_octal(char* num) {
    char* temp_str = malloc(8);
    char* hold_str = malloc(8 * sizeof(int));
    for (int i = 0; i < strlen(hold_str); i++) {
        hold_str[i] = 0;
    }
    strcpy(temp_str, "000");
    strrev(num);
    for (int i = strlen(num); i < 31; i++) {
        num[i] = 0;
    }
    int offset = strlen(num) % 3;
    int index = (strlen(num) - offset) / 3;
    for (int i = 0; i <= index; i++) {
        for (int j = 0; j <= 2; j++) {
            if (num[(i * 3) + j] != 0) {
                temp_str[j] = num[(i * 3) + j];
            } else {
                temp_str[j] = 48;
            }
        }
        strrev(temp_str);
        int temp_num = atoi(temp_str);
        switch (temp_num) {
            case 0:
                hold_str[i] = 48;
                break;
            case 1:
                hold_str[i] = 49;
                break;
            case 10:
                hold_str[i] = 50;
                break;
            case 11:
                hold_str[i] = 51;
                break;
            case 100:
                hold_str[i] = 52;
                break;
            case 101:
                hold_str[i] = 53;
                break;
            case 110:
                hold_str[i] = 54;
                break;
            case 111:
                hold_str[i] = 55;
                break;
            default:
                printf("Error in Processing from binary to Octal");
                free(temp_str);
                free(hold_str);
                return;
        }
        strcpy(temp_str, "000");
    }
    free(temp_str);
    strrev(hold_str);
    for (int i = 0; i < strlen(num); i++) {
        num[i] = 0;
    }
    while (hold_str[0] == 48) {
        for (int i = 0; i <= strlen(hold_str); i++) {
            hold_str[i] = hold_str[i + 1];
        }
    }
    strcpy(num, hold_str);
    return;
}

void binary_to_hexadecimal(char* num) {
    char* temp_str = malloc(5);
    char* hold_str = malloc(8 * sizeof(int));
    strcpy(temp_str, "0000");
    strrev(num);
    for (int i = strlen(num); i < 31; i++) {
        num[i] = 0;
    }
    int offset = strlen(num) % 4;
    int index = (strlen(num) - offset) / 4;
    for (int i = 0; i <= index; i++) {
        for (int j = 0; j <= 3; j++) {
            if (num[(i * 4) + j] != 0) {
                temp_str[j] = num[(i * 4) + j];
            } else {
                temp_str[j] = 48;
            }
        }
        strrev(temp_str);
        int temp_num = atoi(temp_str);
        switch (temp_num) {
            case 0:
                hold_str[i] = 48;
                break;
            case 1:
                hold_str[i] = 49;
                break;
            case 10:
                hold_str[i] = 50;
                break;
            case 11:
                hold_str[i] = 51;
                break;
            case 100:
                hold_str[i] = 52;
                break;
            case 101:
                hold_str[i] = 53;
                break;
            case 110:
                hold_str[i] = 54;
                break;
            case 111:
                hold_str[i] = 55;
                break;
            case 1000:
                hold_str[i] = 56;
                break;
            case 1001:
                hold_str[i] = 57;
                break;
            case 1010:
                hold_str[i] = 65;
                break;
            case 1011:
                hold_str[i] = 66;
                break;
            case 1100:
                hold_str[i] = 67;
                break;
            case 1101:
                hold_str[i] = 68;
                break;
            case 1110:
                hold_str[i] = 69;
                break;
            case 1111:
                hold_str[i] = 70;
                break;
            default:
                printf("Error in Processing from binary to Hexadecimal");
                free(temp_str);
                free(hold_str);
                num[0] = 0;
                return;
        }
        strcpy(temp_str, "0000");
    }
    free(temp_str);
    strrev(hold_str);
    for (int i = 0; i < strlen(num); i++) {
        num[i] = 0;
    }
    while (hold_str[0] == 48) {
        for (int i = 0; i <= strlen(hold_str); i++) {
            hold_str[i] = hold_str[i + 1];
        }
    }
    strcpy(num, hold_str);
    free(hold_str);
    return;
}

int main() {
    while(1){
        int operation;
        printf("Please select from the following options for number conversion.\n");
        printf("Enter the number of your choice, then press enter.\n");
        printf("   1.) Convert a Binary number to Octal\n");
        printf("   2.) Convert a Binary number to Decimal\n");
        printf("   3.) Convert a Binary number to Hexadecimal\n");
        printf("   4.) Convert an Octal number to Binary\n");
        printf("   5.) Convert an Octal number to Decimal\n");
        printf("   6.) Convert an Octal number to Hexadecimal\n");
        printf("   7.) Convert a Decimal number to Binary\n");
        printf("   8.) Convert a Decimal number to Octal\n");
        printf("   9.) Convert a Decimal number to Hexadecimal\n");
        printf("   10.) Convert a Hexadecimal number to Binary\n");
        printf("   11.) Convert a Hexadecimal number to Octal\n");
        printf("   12.) Convert a Hexadecimal number to Decimal\n");
        printf("   13.) Exit the Converter\n");
        printf(">> ");
        scanf("%d", &operation);
        char* num = malloc(8 * sizeof(int));
        for (int i = 0; i < (8 * sizeof(int)); i++) {
            num[i] = 0;
        }
        if (operation > 0){
            if (operation < 4) {
                printf("Please enter a Binary number\n");
                printf(">> ");
                scanf("%s", num);
                int good_num = 1;
                for (int i = 0; i < strlen(num); i++) {
                    if (num[i] != 48 && num[i] != 49) {
                        printf("This is not a Binary number. Please try again.\n");
                        good_num = 0;
                        break;
                    }
                }
                if (good_num) {
                    switch(operation) {
                        case 1:
                            printf("The Converted number is ");
                            binary_to_octal(num);
                            printf(num);
                            printf("\n");
                            break;
                        case 2:
                            printf("the Converted number is ");
                            num_to_decimal(num, 2);
                            printf(num);
                            printf("\n");
                            break;
                        case 3:
                            printf("the Converted number is ");
                            binary_to_hexadecimal(num);
                            printf(num);
                            printf("\n");
                            break;
                        default:
                            printf("Error in Processing choice");
                    }
                }
            } else if (operation > 3 && operation < 7) {
                printf("Please enter an Octal number\n");
                printf(">> ");
                scanf("%s", num);
                int good_num = 1;
                for (int i = 0; i < strlen(num); i++) {
                    if (num[i] < 48 || num[i] > 55) {
                        printf("This is not an Octal number. Please try again.\n");
                        good_num = 0;
                        break;
                    }
                }
                if (good_num) {
                    switch(operation) {
                        case 4:
                            printf("the Converted number is ");
                            num_to_decimal(num, 8);
                            decimal_to_binary(num);
                            printf(num);
                            printf("\n");
                            break;
                        case 5:
                            printf("the Converted number is ");
                            num_to_decimal(num, 8);
                            printf(num);
                            printf("\n");
                            break;
                        case 6:
                            printf("the Converted number is ");
                            num_to_decimal(num, 8);
                            decimal_to_binary(num);
                            binary_to_hexadecimal(num);
                            printf(num);
                            printf("\n");
                            break;
                        default:
                            printf("Error in Processing choice");
                            break;
                    }
                }
            } else if (operation > 6 && operation < 10) {
                printf("Please enter a Decimal number\n");
                printf(">> ");
                scanf("%s", num);
                int good_num = 1;
                for (int i = 0; i < strlen(num); i++) {
                    if (num[i] < 48 || num[i] > 57) {
                        printf("This is not a Decimal number. Please try again.\n");
                        good_num = 0;
                        break;
                    }
                }
                if (good_num) {
                    switch(operation) {
                        case 7:
                            printf("the Converted number is ");
                            decimal_to_binary(num);
                            printf(num);
                            printf("\n");
                            break;
                        case 8:
                            printf("the Converted number is ");
                            decimal_to_binary(num);
                            binary_to_octal(num);
                            printf(num);
                            printf("\n");
                            break;
                        case 9:
                            printf("the Converted number is ");
                            decimal_to_binary(num);
                            binary_to_hexadecimal(num);
                            printf(num);
                            printf("\n");
                            break;
                        default:
                            printf("Error in Processing choice");
                            break;
                    }
                }
            }else if (operation > 9 && operation < 13) {
                char* num = malloc(8 * sizeof(int));
                printf("Please enter a Hexadecimal number\n");
                printf(">> ");
                scanf("%s", num);
                int good_num = 1;
                for (int i = 0; i < strlen(num); i++) {
                    if (!((num[i] >= 48 && num[i] <= 55) || !(num[i] >= 65 && num[i] <= 70))) {
                        printf("This is not a Hexadecimal number. Please try again.\n");
                        good_num = 0;
                        break;
                    }
                }
                if (good_num) {
                    switch(operation) {
                        case 10:
                            printf("The converted number is ");
                            hex_to_decimal(num);
                            decimal_to_binary(num);
                            printf(num);
                            printf("\n");
                            break;
                        case 11:
                            printf("The Converted number is ");
                            hex_to_decimal(num);
                            decimal_to_binary(num);
                            binary_to_octal(num);
                            printf(num);
                            printf("\n");
                            break;
                        case 12:
                            printf("The Converted number is ");
                            hex_to_decimal(num);
                            printf(num);
                            printf("\n");
                            break;
                        default:
                            printf("Error in Processing choice");
                            break;
                    }
                }
            } else if (operation == 13) {
                free(num);
                break;
            } else {
                printf("This is not a valid choice. Please try again\n");
            }
        } else {
                printf("This is not a valid choice. Please try again\n");
        }
    }
    printf("Goodbye!\n");
}
