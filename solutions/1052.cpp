#include <vector>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;
typedef struct Node {
	int addr;
	int key;
	int next;
	bool operator < (const Node &m)const {
		return key < m.key;
	}
} Node;

int total;
int count = 0;
int begin_addr;
vector<Node> nodes;
Node list[MAX];
int main()
{
	scanf("%d %d", &total, &begin_addr);
	for(int i = 0; i<total; i++) {
		int temp_addr;
		scanf("%d", &temp_addr);
		scanf("%d %d", &list[temp_addr].key, &list[temp_addr].next);
		list[temp_addr].addr = temp_addr;
	}
	if(begin_addr == -1)
	{
		printf("0 -1");
		return 0;
	}
	int count = 0;
	while(list[begin_addr].next != -1)
	{
		count++;
		nodes.push_back(list[begin_addr]);
		begin_addr = list[begin_addr].next;
	}
	nodes.push_back(list[begin_addr]);
	
	sort(nodes.begin(), nodes.end());

	vector<Node>::iterator iter = nodes.begin();
	
	
	printf("%d %05d\n", nodes.size(), (*iter).addr);
	for(iter = nodes.begin(); iter != nodes.end(); iter++) {
		if((iter+1) != nodes.end())
			printf("%05d %d %05d\n", (*iter).addr, (*iter).key, (*(iter+1)).addr);
		else
			printf("%05d %d -1\n", (*iter).addr, (*iter).key);
	}

	return 0;
}

