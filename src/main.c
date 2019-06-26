#include "palindrom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{	
	int length = 0;
	int palindrom = 0;
	if(argc<2){ // Проверка на вход аргумента 
		printf("Usage: ./palindrom <filename>\n");
		return 1;
	}
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(fp == NULL){ // Проверка отсутствия файла
		printf("Error, file not found\n"); 
		return 1;
	} 
	fclose(fp);
	length = quantity(argv[1], length);
	if(length == 0){
			printf("Error, file is empty");
			return 1;
		} 
	char array[length];
	check(argv[1], array, length);
	printf("---------------------------------------------------------\n");
    printf("| Hello, this is a palindrome text verification program |\n");
    printf("---------------------------------------------------------\n");
    printf("\n");
    printf("In the file that you connected is the text: %s\n\n", array);
	registr(array, length); // Приводим буквы к нижнему регистру
	palindrom = test(array,length); // Проверка текста на палиндром
	if(palindrom == 0)
		printf("It is palindrom");
	else 
		printf("It is not palindrom");
	return 0;
}