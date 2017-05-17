#ifndef Types_h
#define Types_h
#endif

#include<stdio.h>
#include<stdlib.h>
#include "errorHandling.h"
#include "cfg.h"

typedef unsigned int uint;

struct symbolTable_st{
	char alphabets;
	uint frequency;
};

typedef struct symbolTable_st charMap;

struct tree_st{
	uint freq;
	int codeArray[100];
	charMap table;
	struct tree* left_child;
	struct tree* right_child;
};

typedef struct tree_st node;

struct elements_st{
	charMap table;
	node* address;
};

struct treeHandle_st{
	struct elements_st treeNode;
	int length;
};

struct queueType_st{
	int level;
	node* address;
};

struct codeTable_st{
	char alphabet;
	int codeArray[100];
	int length;
};


extern struct codeTable_st codeTable[TABLESIZE];

