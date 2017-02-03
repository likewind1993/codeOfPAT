#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct FamiNode
{
	int level;
	char ID[2];
	FamiNode * next;
}FamiNode;

typedef FamiNode * FamiTree;

FamiTree listCreate(int total)
{
	FamiTree line [MAX];
	FamiTree * head = line;
	
	for(int i = 0; i<total; i++)
	{
		FamiTree temp = (FamiTree)malloc(sizeof(FamiNode));
		scanf("%s", &temp->ID);
		temp->level = i;
		int nums;
		scanf("%d", &nums)
		for(int j = 0; j<nums; j++)
		{
			
		}
	}
	
}

int main()
{
	int total, non_leafnode;
	scanf("%d %d", &total, &non_leafnode);
	FamiTree tree = listCreate(non_leafnode);
	
}
