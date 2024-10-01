//Author: Michael Barchett
//Reviewer: Jacob Rechter
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {
    printf("Please enter a string to reverse.\nNote that spaces are not valid characters in the string.\n>> ");
    char* str = malloc(8 * sizeof(int));
    scanf("%s", str);
    int i = 0;
    int j = (int) strlen(str) - 1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    printf(str);
    free(str);
    return 0;
}
