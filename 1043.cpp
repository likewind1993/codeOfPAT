#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAX 10000
typedef struct Node {
	int data;
	struct Node * lchild;
	struct Node * rchild;
} node;
using namespace std;
int tree[MAX];
int flag = 0;
int total;
bool mirror = false;//mirror = true if it's mirror of bst, mirror = false
// if it's bst
int first = 0;
vector<int> temp;
vector<int> vect_sort;

void visit(node * temp)
{
	if(first == 0)
		printf("%d", temp->data);
	else
		printf(" %d", temp->data);
	first++;
}

bool judge()
{
	if(tree[1] >= tree[0])
		mirror = true;
	int head = tree[0];
	if(mirror) {
		int i;
		for (i = 1; i<total; i++) {
			if(tree[i] < head)
				break;
		}
		for(; i<total; i++)
			if(tree[i] >= head)
				return false;
	} else {
		int i;
		for (i = 1; i<total; i++) {
			if(tree[i] >= head)
				break;
		}
		for(; i<total; i++)
			if(tree[i] < head)
				return false;
	}
	return true;
}

node * createTree(int head, int end)
{
	if(head > end)
		return NULL;
	if(!mirror) {
		int count = head+1;
		while(tree[count] < tree[head] && count <= end)
			count++;
		node * root = (node*) malloc(sizeof(node));
		root->data = tree[head];
		root->lchild = createTree(head+1,count-1);
		root->rchild = createTree(count, end);
		return root;
	} else {
		int count = head+1;
		while(tree[count] >= tree[head] && count <= end)
			count++;
		node * root = (node*) malloc(sizeof(node));
		root->data = tree[head];
		root->lchild = createTree(head+1,count-1);
		root->rchild = createTree(count, end);
		return root;
	}

}
void display(vector<int> temp)
{
	vector<int>::iterator iter = temp.begin();
	while(iter != temp.end()) {
		printf("%d ", *iter);
		iter++;
	}
}
void postTravel (node * root)
{
	if(root == NULL)
		return;
	postTravel(root->lchild);
	postTravel(root->rchild);
	visit(root);
}
void inTravel (node * root)
{
	if(root == NULL)
		return;
	inTravel(root->lchild);
	vect_sort.push_back(root->data);
	inTravel(root->rchild);
}
bool com(int a, int b)
{
	return a>b;
}
int main()
{
	scanf("%d", &total);
	for(int i = 0; i<total; i++) {
		scanf("%d", &tree[i]);
		temp.push_back(tree[i]);
	}
	bool flag = judge();
	if(mirror)
		sort(temp.begin(), temp.end(), com);
	else
		sort(temp.begin(), temp.end());
	if(!flag) {
		printf("NO");
		return 0;
	} else {
		node * root = createTree(0, total-1);
		inTravel(root);
		if(vect_sort != temp) {
            printf("NO");
			return 0;
		}
		printf("YES\n");
		postTravel(root);
	}
	return 0;
}
