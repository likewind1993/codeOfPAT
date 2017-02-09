#include <cstdio>
#define MAX 1000000
#define max(a, b) (a>b) ? a : b
#define min(a, b) (a<b) ? a : b
using namespace std;

int path[MAX];
int cost[MAX];
int total;
int pair_total;
int start[MAX];
int end[MAX];

int main()
{
	int sum = 0;
	scanf("%d", &total);
	for(int i = 1; i<=total; i++) {
		int temp;
		scanf("%d", &temp);
		sum += temp;
		cost[i] = sum;
		path[i] = temp;
	}
	scanf("%d", &pair_total);
	for(int i = 0; i<pair_total; i++) {
		scanf("%d", &start[i]);
		scanf("%d", &end[i]);
	}

	for(int i = 0; i<pair_total; i++) {
		int start_site = min(start[i], end[i]);
		int end_site = max(start[i], end[i]);
		if(start_site == 1)
			printf("%d", min(cost[end_site-1], sum-cost[end_site-1]));
		else {
		    int temp = cost[end_site-1] - cost[start_site -1];
		    printf("%d", min(temp, sum-temp));
        }
		if(i<pair_total-1)
			printf("\n");
	}

	return 0;
}

