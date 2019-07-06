#include <stdio.h>
#define INF 0x7fffffff
#define MAX 10000

int max_amount;
int city_nums, road_nums;
int start, end;
int graph[MAX][MAX]={0};
int terms[MAX];
int visit[MAX];
int count;
int min_dist = INF;

void dfs(int start, int dist, int amount)
{
	if(start == end)
	{
		if(dist < min_dist)
		{
			count = 1;
			min_dist = dist;
			max_amount = amount;
			
		}else if(dist == min_dist)
		{
			count++;
			if(amount > max_amount)
				max_amount = amount;
		}
		return;	
	}
	for(int i = 0; i<city_nums; i++)
	{
		if(graph[start][i] != 0 && !visit[i])
		{
			visit[i] = 1;
			dfs(i, dist + graph[start][i], amount + terms[i]);
			visit[i] = 0;
		}
	}	
}


int main()
{

	scanf("%d %d %d %d", &city_nums, &road_nums, &start, &end);
	for(int i = 0; i<city_nums; i++)
		scanf("%d", &terms[i]);
	
	for(int i = 0; i<MAX; i++)
		visit[i] = 0;
	
	for(int i = 0; i<road_nums; i++)
	{
		int start_temp, end_temp, weight;
		scanf("%d %d %d", &start_temp, &end_temp, &weight);
		graph[start_temp][end_temp] = graph[end_temp][start_temp] = weight;
	}
	
	visit[start] = 1;
	dfs(start, 0, terms[start]);
	
	printf("%d %d", count, max_amount);
	
	return 0;
}
