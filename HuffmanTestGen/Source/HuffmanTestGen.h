#ifndef HuffmanTestGen_h
#define HuffmanTestGen_h
#endif

#define NUMLINES 1000
#define CHAR_PER_LINE 100
#define STARTCHAR ' '
#define ENDCHAR '~'

#define UNBIASED 0 //ON

#if (!UNBIASED)

struct freqTable_st{
	char character;
	double frequency;
}freqTable[27];

void initHelper(struct freqTable_st* freqTable_p,char character, float freq);
void initFreqTable(void);

#endif