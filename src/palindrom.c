#include "palindrom.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char* name, char* array, int length)
{
    char c;
    int i = 0;
    FILE* fp;
    fp = fopen(name, "r");
    while ((c = fgetc(fp)) != EOF) {
        array[i++] = c;
        length++;
    }
    fclose(fp);
    if (length == 0) {
        return 0;
    }
    return length;
}

void registr(char* array, int length)
{
    int i;
    int j = length;
    for (i = 0; i < length; i++) {
        if (array[i] >= 'A' && array[i] <= 'Z') {
            array[i] = tolower(array[i]);
            j++;
        }
    }
}

int test(char* array, int length)
{
    int leftIndex = 0;
    int rightIndex = length - 1;
    while (leftIndex < rightIndex) {
        if (array[leftIndex++] != array[rightIndex--])
            return 1;
    }
    return 0;
}