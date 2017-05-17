#include "Types.h"
#include "input_huffman.h"
#include "huffmanTreeGenerate.h"

node* root = NULL;
int sortAscend(struct elements_st* List,int startIndex,int length){

	int i,j = 0;
	int endIndex = startIndex + length;
	struct elements_st temp;

	for(i =startIndex; i< endIndex-1; i++){
		for(j = i+1; j<endIndex; j++){
			if(List[i].table.frequency > List[j].table.frequency)
			{
				temp = List[i];
				List[i] = List[j];
				List[j] = temp;
			}
		}
	}
	return 0;
}

int createNode(struct elements_st* List,int startIndex,int length){

	int i=0;
	int endIndex = startIndex +length;

	List[endIndex].address = (node*)malloc(sizeof(node));
	List[endIndex].address->table.frequency = List[startIndex].table.frequency+List[startIndex+1].table.frequency;
	List[endIndex].address->freq = List[startIndex].table.frequency+List[startIndex+1].table.frequency;
	List[endIndex].table.frequency = List[startIndex].table.frequency+List[startIndex+1].table.frequency;
	List[endIndex].address->left_child = List[startIndex].address;
	List[endIndex].address->right_child = List[startIndex+1].address;
	List[endIndex+1].table.frequency = '\0';
	List[endIndex+1].address = NULL;
	return length-1;
}

struct treeHandle_st huffmanTreeGenerate(char *infilePath){

	node* root_backup = NULL;
	int i,newElement = 0;
	int length = input_Array(infilePath);
	int memLength = 2*(length-1);

	struct elements_st memArray[2*TABLESIZE];
	struct treeHandle_st finalNode;

	//initialization
	for(i = 0; i< 2*TABLESIZE; i++)
	{
		memArray[i].table.frequency = symTable[i].frequency;
		memArray[i].table.alphabets = symTable[i].alphabets;
		memArray[i].address = (node*)malloc(sizeof(node));
		memArray[i].address->table.alphabets = memArray[i].table.alphabets;
		memArray[i].address->table.frequency = memArray[i].table.frequency;
		memArray[i].address->freq = memArray[i].table.frequency;
		memArray[i].address->left_child = NULL;
		memArray[i].address->right_child = NULL;
	}
	
	for(i=0; i < memLength; i+=2)
	{
		sortAscend(memArray,i,length);
		length = createNode(memArray,i,length);
	}
	finalNode.treeNode = memArray[memLength];
	finalNode.length = memLength;
	return finalNode;
}
