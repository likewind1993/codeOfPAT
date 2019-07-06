#include <cstdio>
#include <stack>
#include <vector>
#define MAX 10000

using namespace std;
int capacity;
int seque;
int line_nums;
vector<vector<int> > input;

int scan(vector<int> temp)
{
	vector<int>::iterator iter = temp.begin();
	stack<int> stac;
	for(int i = 1; i<=seque; i++) {
		stac.push(i);
		if(stac.size() > capacity)
			return 0;
		if(stac.top() != *iter)
			continue;
		else  {
			while(stac.top() == *iter) {
				stac.pop();
				iter++;
				if(stac.empty())
					break;
			}
		}
	}
	if(stac.size()>0)
		return 0;
	return 1;
}

int main()
{
	scanf("%d %d %d", &capacity, &seque, &line_nums);
	int cur_capa = 0;
	for(int i = 0; i<line_nums; i++) {
		vector<int> vect_tmp;
		for(int j = 0; j<seque; j++) {
			int temp;
			scanf("%d", &temp);
			vect_tmp.push_back(temp);
		}
		input.push_back(vect_tmp);
	}

	vector<vector<int> >::iterator iter;
	for(iter = input.begin(); iter != input.end(); iter++) {
		if(scan(*iter) == 1)
			printf("YES");
		else
			printf("NO");
		if((iter+1) != input.end())
			printf("\n");
	}

	return 0;
}
