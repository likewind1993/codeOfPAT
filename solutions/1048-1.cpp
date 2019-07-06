#include <cstdio>
#define MAX 501
using namespace std;

int main()
{
    int coin[MAX] = {0};
    int total, target;
    scanf("%d %d", &total, &target);
    for(int i = 0; i<total; i++)
    {
        int temp;
        scanf("%d", &temp);
        coin[temp]++;
    }
    int i = 0, j = 500;
    while(i<j)
    {
        while( !coin[i] )
            i++;
        while( !coin[j] )
            j--;
        if(i + j > target) {
            j--;
            continue;
        } else if (i + j < target) {
            i++;
            continue;
        } else if (i + j == target) {
            printf("%d %d", i, j);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}

