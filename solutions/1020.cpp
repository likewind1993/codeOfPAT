#include <map>
#include <queue>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

#define MAX 10000

using namespace std;
typedef int Data;
typedef struct BinTreeNode
{
	Data data;
	BinTreeNode * lchild;
	BinTreeNode * rchild;
}BinTreeNode;
typedef BinTreeNode * PBinTreeNode;
typedef BinTreeNode * PBinTree;

BinTreeNode * postIn(Data * in, int ni, int nj, Data * post, int pi, int pj, map<Data, int> Map)
{
	if(pi > pj)
		return NULL;
	BinTreeNode * head = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	
	head->data = post[pj];
	map<Data, int>::iterator iter = Map.find(post[pj]);
	int index = iter->second;
	
	head->lchild = postIn(in, ni, index - 1, post, pi, pi + index - ni - 1, Map);
	head->rchild = postIn(in, index + 1, nj, post, pi + index - ni, pj - 1, Map);
	
	return head;
}

BinTreeNode * postInToTree(Data * post, Data * in, int total)
{
	if(post == NULL || in == NULL)
		return NULL;
	map<Data, int> Map;
	for(int i = 0; i<total; i++)
		Map.insert(map<Data, int>::value_type(in[i], i));

	return postIn(in, 0, total - 1, post, 0, total - 1, Map);
}

void levelTravel(PBinTreeNode root)
{
	if(root == NULL)
		return;
	queue<PBinTreeNode> q;
	q.push(root); 
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		if(root->lchild != NULL)
			q.push(root->lchild);
		if(root->rchild != NULL)
			q.push(root->rchild);
		printf("%d", root->data);
		if(!q.empty())
			printf(" "); 
	}
	
}

int main()
{
	Data post[MAX], in[MAX];
	int total;
	cin>>total;
	getchar();
	for(int i = 0; i<total; i++)
		scanf("%d", &post[i]);
	getchar();
	for(int i = 0; i<total; i++)
		scanf("%d", &in[i]);

	PBinTree tree = postInToTree(post, in, total);
	if(tree != NULL)
		levelTravel(tree);
	
	
	return 0;
}
//GDBHEIFCA
//DGBAEHCFI
