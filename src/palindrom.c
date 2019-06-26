#include "palindrom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int quantity(char *name, int length){
	char c;
	FILE *fp;
	fp = fopen(name, "r");
	while ((c =fgetc(fp)) != EOF){
		length++;
	 } 
	fclose(fp);
	if(length == 0){
		return 0;
	}
	return length;
}

void check(char *name, char *array, int length){
	char c;
	int i = 0;
	FILE *fp;
	fp = fopen(name, "r");
	for(i=0;i<=length;i++){
	    c =fgetc(fp);
		array[i++] = c;
	 } 
	fclose(fp);
}

void registr(char *array, int length){
	int i;
	int j = length;
	for(i=0;i<length;i++){
		if (array[i] >= 'A' && array[i] <= 'Z'){
			array[i] = tolower(array[i]);
			j++;
		}
	}
}

int test(char *array, int length){
	int leftIndex = 0;
	int rightIndex = length;
	while(leftIndex < rightIndex){
		if(array[leftIndex++]!=array[rightIndex])
			return 1;
	}
	return 0;
}
	

