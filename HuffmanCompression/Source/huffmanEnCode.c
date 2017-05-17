#include "Types.h"
#include "huffmanEnCode.h"
#include "huffmanTreeGenerate.h"

int startPosition=0;
int endPosition=0;
int nodesInCurrentLevel, nodesInNextLevel = 0;


void push(struct queueType_st* queue, node* curAddress, node* prevAddress, int levelVal, int bitValue){

	int i = 0;

	if(endPosition >= 0)
	{
		//temp checking delete
		queue[endPosition].address = curAddress;
		queue[endPosition].level = levelVal;
		queue[endPosition].address->codeArray[levelVal] = bitValue;
		for(i=0; i < levelVal; i++)
		{
			queue[endPosition].address->codeArray[i] = prevAddress->codeArray[i];
		}
		endPosition++;

	}
}

struct queueType_st pop(struct queueType_st* queue){
	struct queueType_st retValue = queue[startPosition];

	startPosition++;
	nodesInCurrentLevel--;
	return retValue;
}

void huffmanEnCode(char *infilePath){

	int i,j,k=0,levelCount = 0;
	struct queueType_st queue[10000];
	int codeNumber =0;
	struct treeHandle_st binTree;
	struct queueType_st tempHold;
	
	binTree = huffmanTreeGenerate(infilePath);

	//queue init
	tempHold.address = binTree.treeNode.address;
	tempHold.level = levelCount;
	push(queue,binTree.treeNode.address,NULL,tempHold.level,0);
	nodesInCurrentLevel =1;

	for( i =0; i<= binTree.length ; i++)
	{
		tempHold = pop(queue);
		if (tempHold.address->left_child == NULL && tempHold.address->right_child == NULL){
			
			codeTable[k].alphabet = tempHold.address->table.alphabets;
			for(j=0; j < levelCount; j++)
			{
				codeTable[k].codeArray[j] = tempHold.address->codeArray[j];
			}
			codeTable[k].length = levelCount;
			
			printf("%c :  ",codeTable[k].alphabet);
			for(j=0; j < codeTable[k].length; j++)
			{
				printf("%d",codeTable[k].codeArray[j]);
			}
			printf("\n");
			codeNumber = 0;
			k++;

		}
		if(tempHold.address->left_child != NULL && tempHold.address->right_child != NULL)
		{
			tempHold.level =levelCount;
			if(tempHold.address->left_child != NULL)
			{
				push(queue,tempHold.address->left_child,tempHold.address,tempHold.level,0);
			}
			if(tempHold.address->right_child != NULL)
			{
				push(queue,tempHold.address->right_child,tempHold.address,tempHold.level,1);
			}
			nodesInNextLevel +=2;
		}
		if(nodesInCurrentLevel == 0)
		{
			nodesInCurrentLevel = nodesInNextLevel;
			nodesInNextLevel =0;
			levelCount++;
		}
	}
}	
