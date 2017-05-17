#include<conio.h>
#include<stdio.h>
#include "Types.h"
#include "input_huffman.h"
#include "huffmanEnCode.h"
#include "outToFile.h"
#include "huffmanDeCode.h"

void inputFromTerminal(char* message, char* inputString){
	// char inputString[255];
	int len = 0;
	printf("%s",message);
	fflush(stdout);
	fgets(inputString,255,stdin); 
	len = strlen(inputString) - 1;
	if(inputString[len] == '\n'){
		inputString[len] = '\0';
	}
	return inputString;
}

int main(){

	int totalBits = 0,len = 0;
	char outPath[255]; 
	char inPath[255];
	char outFile[255];

	// printf("Input file path : ");
	// fflush(stdout);
	// fgets(inPath,255,stdin); 
	inputFromTerminal("Input file path : ", inPath);
	huffmanEnCode(inPath);
	printf("Encoding...\n");
	
	// printf("Output compressed file path : ");
	// fflush(stdout);
	// fgets(outPath,255,stdin); 
	inputFromTerminal("Output compressed file path : ", outPath);
	printf("compressed file generating...\n");
	totalBits = outToFile(inPath,outPath);
	
	// printf("Output extract file path : ");
	// fflush(stdout);
	// fgets(outFile,255,stdin); 
	inputFromTerminal("Output extract file path : ", outFile);
	printf("decoding....\n");
	huffmanDeCode(outPath,outFile,totalBits);
	printf("\ncomplete!");
	return 0;
}


