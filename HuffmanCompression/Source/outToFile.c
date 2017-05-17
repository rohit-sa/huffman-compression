#include<string.h>
#include "Types.h"
#include "outToFile.h"
#include "input_huffman.h"
#include "huffmanEnCode.h"

struct codeTable_st codeTable[TABLESIZE];

int outToFile(char *infilePath, char *outfilePath){

	int in_character,i,j;
	uint buffer = 0,totalBits = 0, countBits = 0;
	FILE *in_file_p,*out_file_p;

	if(outfilePath[strlen(outfilePath)-1] != '\\')
	{
		errorHandling();
	}
	outfilePath = strcat(outfilePath,"out.bin");
	in_file_p = fopen(infilePath,"r+");
	out_file_p = fopen(outfilePath,"wb");
	/*file already exists-> del old and repalce with new*/
	if(!out_file_p)
	{
		remove(outfilePath);
		out_file_p = fopen(outfilePath,"wb");
	}
	in_character = getc(in_file_p);
	//initialization

	while (in_character != EOF)
	{
    /* To display the contents of the file on the screen */

		for(i= 0; i < TABLESIZE; i++){
			if(codeTable[i].alphabet == in_character)
			{
				for(j =0; j< codeTable[i].length; j++)
				{

					if(countBits > 31)
					{

						fseek(out_file_p,0,SEEK_CUR);
						fwrite(&buffer,sizeof(uint),1,out_file_p);

						buffer = 0;
						countBits = 0;
					}

					buffer = buffer << 1;
					buffer = (buffer | codeTable[i].codeArray[j]);
					countBits++;
					totalBits++;
				}
				break;
			}
		}
		
		in_character = getc(in_file_p);
	}

	fseek(out_file_p,0,SEEK_CUR);
	fwrite(&buffer,sizeof(uint),1,out_file_p);

	fclose(in_file_p);
	fclose(out_file_p);
	return totalBits;
}
