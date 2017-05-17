#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "HuffmanTestGen.h"

#if (!UNBIASED)
void initHelper(struct freqTable_st* freqTable_p,char character, float freq){
	freqTable_p->character = character;
	freqTable_p->frequency = freq;
};

void initFreqTable(void){
	
	initHelper(freqTable+0,'\\',0.0);
	initHelper(freqTable+1,'z',0.0074);
	initHelper(freqTable+2,'q',0.0095);
	initHelper(freqTable+3,'x',0.0150);
	initHelper(freqTable+4,'j',0.0153);
	initHelper(freqTable+5,'k',0.0772);
	initHelper(freqTable+6,'v',0.0978);
	initHelper(freqTable+7,'b',1.492);
	initHelper(freqTable+8,'p',1.929);
	initHelper(freqTable+9,'y',1.974);
	initHelper(freqTable+10,'g',2.015);
	initHelper(freqTable+11,'f',2.228);
	initHelper(freqTable+12,'w',2.361);
	initHelper(freqTable+13,'m',2.406);
	initHelper(freqTable+14,'u',2.758);
	initHelper(freqTable+15,'c',2.782);
	initHelper(freqTable+16,'l',4.025);
	initHelper(freqTable+17,'d',4.253);
	initHelper(freqTable+18,'r',5.987);
	initHelper(freqTable+19,'h',6.094);
	initHelper(freqTable+20,'s',6.327);
	initHelper(freqTable+21,'n',6.749);
	initHelper(freqTable+22,'i',6.966);
	initHelper(freqTable+23,'o',7.507);
	initHelper(freqTable+24,'a',8.167);
	initHelper(freqTable+25,'t',9.056);
	initHelper(freqTable+26,'e',12.702);
}
#endif
int main(){
	int i=0,j=0, len =0;
	char filePath[255];
	FILE *file_p;
#if(!UNBIASED)
	int k=0;
	float PrevSum=0,Sum=0,temp = 0;
#endif
	printf("Enter output file path: ");
	fflush(stdout);
	fgets(filePath,255,stdin); 
	len = strlen(filePath) - 1;
	if(filePath[len] == '\n'){
		filePath[len] = '\0';
	}
	printf("\nWriting to %s",filePath);
	srand(time(NULL));
	file_p = fopen(filePath,"w");
	printf("\n Generating in file...");
#if (UNBIASED)
	{
		for(i =0; i <NUMLINES; i++)
		{
			for(j =0; j < CHAR_PER_LINE; j++)
			{
				fprintf(file_p,"%c",(rand()%(ENDCHAR-STARTCHAR+1))+STARTCHAR);
			}
			fprintf(file_p,"\n");
		}
	}
#else 
	{
		initFreqTable();
		for(i =0; i <NUMLINES; i++)
		{
			for(j =0; j < CHAR_PER_LINE; j++)
			{
				temp = (float)rand()/RAND_MAX;
				Sum = 0;
				PrevSum =0;
				for(k =1; k < 27; k++)
				{
					PrevSum += ((float)(freqTable+k-1)->frequency/100);
					Sum += ((float)(freqTable+k)->frequency/100);
					if((temp < Sum) && (temp >= PrevSum))
					{
						fprintf(file_p,"%c",(freqTable+k)->character);
						break;
					}
				}
			}
			fprintf(file_p,"\n");
		}
	}
#endif
	fclose(file_p);
	return 0;
}
