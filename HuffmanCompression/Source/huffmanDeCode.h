#ifndef huffmanDeCode_h
#define huffmanDeCode_h
#endif

extern struct codeTable_st codeTable[TABLESIZE];
extern int newlineArray[100000];

void huffmanDeCode(char* inPath, char* outPath, int totalBits);
