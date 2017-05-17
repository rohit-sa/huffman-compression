#include "Types.h"
#include "input_huffman.h"
#include "huffmanEnCode.h"

int newlineArray[100000]={0};
struct symbolTable_st symTable[TABLESIZE];
int symArray[TABLESIZE]={0};

int sortDescend(void){

	int i,j=0;
	int length = 0;
	struct symbolTable_st temp;

	for(i =0; i< TABLESIZE-1; i++)
	{
		for(j = i+1; j< TABLESIZE; j++)
		{
			if(symTable[i].frequency < symTable[j].frequency)
			{
				temp = symTable[i];
				symTable[i] = symTable[j];
				symTable[j] = temp;
			}
		}
	}
	for(i = 0; symTable[i].frequency!= 0 ;i++){
		length++;
	}
	return length;
}

int input_Array(char *infilePath){

	int character,charCount=0,i,j=0;
	FILE *file_p;

    file_p = fopen(infilePath,"r");
	if (file_p)
	{
		printf("Reading file....\n");
		printf("Building code table...\n");
	
		character = getc(file_p);

		//initialization
		for(i=0; i<TABLESIZE; i++)
		{
			symTable[i].frequency = 0;
		}

		while (character != EOF)
		{
			if(character == 10)//newline
			{
				newlineArray[j++] = charCount;
				charCount--;
			}
			symTable[character-' '].alphabets = character;
			symTable[character-' '].frequency++;
			charCount++;
			character = fgetc(file_p);
		}	
 		fclose(file_p);
		return sortDescend();
	}
	else
	{
		errorHandling();
	}
}
