#include<conio.h>
#include "Types.h"
#include "input_huffman.h"
#include "huffmanEnCode.h"
#include "outToFile.h"
#include "huffmanDeCode.h"

int main(){

	int totalBits = 0;
	char outFile[255] = "C:\\Users\\Rohit\\Desktop\\Coding\\C\\HuffmanCompression\\huffman-compression\\HuffmanCompression\\Test\\out_file.txt";
	char outPath[255] = "C:\\Users\\Rohit\\Desktop\\Coding\\C\\HuffmanCompression\\huffman-compression\\HuffmanCompression\\Test\\"; 
	char inPath[255] = "C:\\Users\\Rohit\\Desktop\\Coding\\C\\HuffmanCompression\\huffman-compression\\HuffmanCompression\\Test\\in.txt";
	// char outPath[255] = ""; 
	// char inPath[255] = "";

	printf("Input file path : ");
	// gets(inPath);
	huffmanEnCode(inPath);
	printf("Encoding...\n");
	// // printf("output file path : ");
	// gets(outPath);
	printf("compressed file generating...\n");
	totalBits = outToFile(inPath,outPath);
	printf("decoding....\n");
	huffmanDeCode(outPath,outFile,totalBits);
	printf("\ncomplete!");
	// getch();
	return 0;
}

// int main(){
	// printf("asdf");
	// return 0;
// }
