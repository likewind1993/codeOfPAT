#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 1000
using namespace std;
typedef struct Node {
	int ID;
	int weight;
	vector<int> child;
} Nodes;

Nodes nodes[MAX];
int pre[MAX] = {-1};
vector<int> leaf_nodes;
vector<int> leaf_value;
vector<vector<int> >output;
int visit[MAX] = {0};
int total;
int non_leaf;
int dest;

bool compare(int a, int b)
{
	return nodes[a].weight > nodes[b].weight;
}

stack<int> stac;

void print(int p)
{
	while(p != -1)
	{
		stac.push(p);
		p = pre[p];
	}
	printf("%d", nodes[stac.top()].weight);
	stac.pop();
	while(!stac.empty())
	{
		printf(" %d", nodes[stac.top()].weight );
		stac.pop();
	}
}

void dsf(int start, int amount)
{	
	if(nodes[start].child.empty()) {
		if(amount == dest) {
			print(start);
			printf("\n");
		}
		return ;
	}
	vector<int>::iterator iter;
	for(iter = nodes[start].child.begin(); iter!=nodes[start].child.end(); iter++) {
		if(!visit[*iter]) {
			visit[*iter] = 1;
			dsf(*iter, amount + nodes[*iter].weight);
			visit[*iter] = 0;
		}
	}
}

int main()
{
	scanf("%d %d %d", &total, &non_leaf, &dest);
	int leaf = total - non_leaf;
	for(int i = 0; i<total; i++)
		scanf("%d", &nodes[i].weight);
	for(int i = 0; i<non_leaf; i++) {
		int id, k;
		scanf("%d %d", &id, &k);
		while(k--) {
			int temp;
			scanf("%d", &temp);
			nodes[id].child.push_back(temp);
			pre[temp] = id;
		}
		sort(nodes[id].child.begin(), nodes[id].child.end(), compare);
	}

	visit[0] = 1;
	dsf(0, nodes[0].weight);
		
	return 0;
}
