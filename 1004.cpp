#include <cstdio>
#include <map>
#include <vector>
#define MAX 1000
using namespace std;

int total_nums, non_leaf;
map<int, vector<int> >Map;
int record[MAX] = {0};


void dfs(int id, int level)
{
	if(Map[id].empty())
	{
		++record[level];
		return;
	}
	vector<int>::iterator iter;
	for(iter = Map[id].begin(); iter<Map[id].end(); iter++)
		dfs(*iter, level+1);	
}

int main()
{
	scanf("%d %d", &total_nums, &non_leaf);
	int leaf_nodes = total_nums - non_leaf;
	int id, k;
	for(int i = 0; i<non_leaf; i++)
	{
		scanf("%d %d", &id, &k);
		int sub_id;
		while(k--)
		{
			scanf("%d", &sub_id);	
			Map[id].push_back(sub_id);
		}
	}
	
	dfs(1, 0);
	int count = record[0];
	printf("%d", record[0]);
	for(int i = 1; count<leaf_nodes; i++)
	{
		printf(" %d", record[i]);
		count += record[i];
	}
	return 0;
}
