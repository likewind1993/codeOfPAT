#include <cstdio>
#define MAX 999999
int arr[MAX];
int flag[MAX] = {0};
int total;
int main()
{
	scanf("%d", &total);
	for(int i = 0; i<total; i++) {
		scanf("%d", &arr[i]);
		flag[arr[i]]++;
	}
	for(int i = 0; i<total; i++) {
		if(flag[arr[i]] == 1) {
			printf("%d", arr[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}
