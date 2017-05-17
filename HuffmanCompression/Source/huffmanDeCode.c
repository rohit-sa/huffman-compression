#include "Types.h"
#include "outToFile.h"
#include "input_huffman.h"
#include "huffmanDeCode.h"

int queue[30];
int endPtr_p = 0;
FILE *out_file_p;
char outPath[255] = "C:\\Users\\Rohit\\Desktop\\Coding\\C\\HuffmanCompression\\huffman-compression\\HuffmanCompression\\Test\\out.txt";

void pushQueue(int value){

	int i = 0;

	if(endPtr_p >= 0)
	{
		queue[endPtr_p] = value;
		endPtr_p++;
	}
}

void emptyQueue(int value, int bitsLeft){

	int i =0;

	for( i = 0; i < bitsLeft ; i++)
	{
		queue[i] = queue[value+i];
	}
	endPtr_p = endPtr_p - value;
}

int checkDictionary(int totalBits){

	static int countAlphabets =0, index = 0;
	int i =0, j=0, k = 0, l=0 ;
	int equalFlag = 0;
	int endPtr = 0;
	int bitsLeft = totalBits;

	while(bitsLeft)
	{
		if(bitsLeft < endPtr)
		{
			break;
		}
		for(i = 0; i < TABLESIZE; i++)
		{
			if(codeTable[i].length == endPtr)
			{
				for(j = 0, k=0; j < endPtr, k < codeTable[i].length ; j++,k++)
				{
					equalFlag = 0;
					if(codeTable[i].codeArray[k] != queue[j])
					{
						equalFlag = 0;
						break;
					}
					else
					{
						equalFlag = 1;
					}
				}
			}
			if(equalFlag == 1)
			{
				emptyQueue(endPtr,bitsLeft);
				fprintf(out_file_p,"%c",codeTable[i].alphabet);
				countAlphabets++;
				if(countAlphabets == newlineArray[index])
				{
					index++;
					fprintf(out_file_p,"\n");
				}
				return 0;
			}
		}
		if(equalFlag == 0)
		{
			endPtr++;
			i=-1;
		}
	}
	return totalBits;
}

void huffmanDeCode(char* inPath, char* outPath, int totalBits){

	uint input,k=0,mask=0;
	int i,j=0,l=0, passBits = 1,x = 0;
	FILE *in_file_p;

	/*initialization*/
	in_file_p = fopen(inPath,"rb");
	out_file_p = fopen(outPath,"w+");
	fread(&input,sizeof(uint),1,in_file_p);
	fseek(in_file_p,0,SEEK_CUR);
	if(totalBits < 33)
	{
		mask = 1 << (totalBits-1);
	}
	else
	{
		mask = 1 << 31;
	}


	for(i=1; i <=totalBits; i++,l++)
	{
		if( l >= 32){
			fread(&input,sizeof(uint),1,in_file_p);
			fseek(in_file_p,0,SEEK_CUR);
			l = 0;
			if((totalBits-i) < 33)
			{
				mask = 1 << (totalBits-i);
			}
			else
			{
				mask = 1 << 31;
			}
		}
		k = input & mask;
		if(k)
		{
			pushQueue(1);
		}
		else
		{
			pushQueue(0);
		}
		mask = mask >> 1;
		if( checkDictionary(passBits) != 0)
		{
			passBits++;
		}
		else
		{
			passBits = 1;
		}
	}
	fclose(in_file_p);
	fclose(out_file_p);
} 
