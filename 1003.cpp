#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINT 65535
#define MAX 100

typedef struct List
{
	int num;
	int weight;
	struct List * next;
}List;
typedef struct Node
{
	int num;
	int teams;
	struct List * next;	
	
}Node;


void graphCreate(Node * list, int sites, int routes)
{
	int from, to, weight;
	List * p;
	for(int i = 0; i<routes; i++)
	{
		scanf("%d %d %d", &from, &to, &weight);
		if(list[from].next == NULL)
		{
			List * temp = (List *)malloc(sizeof(List));
			temp->num = to;
			temp->weight = weight;
			temp->next = NULL;
			list[from].next = temp;
		}
		else
		{
			p = list[from].next;
			while(p->next != NULL)
				p = p->next;
			List * temp = (List *)malloc(sizeof(List));
			temp->num = to;
			temp->weight = weight;
			temp->next = NULL;
			p->next = temp;
		}
		
		if(list[to].next == NULL)
		{
			List * temp = (List *)malloc(sizeof(List));
			temp->num = from;
			temp->weight = weight;
			temp->next = NULL;
			list[to].next = temp;
		}
		else
		{
			p = list[to].next;
			while(p->next != NULL)
				p = p->next;
			List * temp = (List *)malloc(sizeof(List));
			temp->num = from;
			temp->weight = weight;
			temp->next = NULL;
			p->next = temp;
		}
		
	}
}

int length(Node * list, int from, int to)
{
	List * p = (List *)malloc(sizeof(List));
	if(list[from].next == NULL)
		return MAXINT;
	p = list[from].next;
	while(p != NULL)
	{
		if(p->num == to)
			return p->weight;
		p = p->next; 
	}
	return MAXINT;
}

void remove(int * p, int position)
{
	p[position] = -1;
}
void add(int * p, int position)
{
	p[position] = -1;
}
int shortest(Node * list, int sites, int routes, int from, int to)
{
	//S is Remain, U is Begin
	int S[MAX];
	for(int i = 0; i<sites; i++)
		S[i] = 1;
	int U[MAX]; 
	memset(U, -1, sizeof(U));
	int dist[MAX];
	for(int i = 0; i<MAX; i++)
		dist[i] = MAXINT;
	S[from] = -1;
	U[from] = 1;
	
	
//	printf("\n");
//	for(int i = 0; i<sites; i++)
//	{
//		printf("%d ", U[i]);
//	}
	
	int temp_site = -1;
	int shortest = MAX;
	List * p = (List *)malloc(sizeof(List));
	p = list[from].next;
	
//	for(int i = 0; i<sites; i++)
//	{
//		if(i == from)
//			U[i] = 1;
//		else
//			S[i] = 1;
//	}
//	printf("\n");
//	for(int i = 0; i<sites; i++)
//	{
//		printf("%d ", U[i]);
//	}
//	printf("\n");
//	for(int i = 0; i<sites; i++)
//	{
//		printf("%d ", S[i]);
//	}
//	printf("\n");
//	while(p != NULL)
//	{	
//		printf("\nfrom %d to %d weight %d\n", from, p->num, p->weight);
//		p = p->next;
//	}
	for(int i = 0; i<sites; i++)
	{
		if(i == from)
			continue;
		int length_temp = length(list, from, i);
		if(length_temp != MAXINT)
		{
//			printf("\n%d %d\n", i, length_temp);

			dist[i] = length_temp;
			if(shortest > length_temp)
			{
				shortest = length_temp;
				temp_site = i;
			}
			
		}
	}
	printf("dist is \n");
	for(int i = 0; i<sites; i++)
		printf("%d ", dist[i]);
	
	printf("\n%d ", temp_site);
	
	U[temp_site] = 1;
	S[temp_site] = -1;
	
	int short_temp = shortest;
	
	for(int i = 0; i<sites; i++)
	{
		if(S[i] == -1)
			continue;
		int length_temp = length(list, temp_site, i);
		if(length_temp != MAXINT)
		{
//			printf("\n%d %d\n", i, length_temp);
			short_temp = shortest + length_temp;
			if(short_temp < dist[i])
			{
				dist[i] = short_temp;
				temp_site = i;
			}
		}
	}
	
	printf("dist is \n");
	for(int i = 0; i<sites; i++)
		printf("%d ", dist[i]);
	
	printf("\n%d ", temp_site);

	
	return 0;
	
}

int main()
{
	Node list[MAX];
	
	int sites, routes;
	int from, to;
	scanf("%d %d %d %d", &sites, &routes, &from, &to);
	for(int i = 0; i<sites; i++)
	{
		int team = 0;
		scanf("%d", &team);
		list[i].teams = team;
		list[i].next = NULL; 
	}
	graphCreate(list, sites, routes);
	shortest(list, sites, routes, from, to);
	
	return 0;
}
