#include <cstdio>
#include <algorithm>
#define MAX 100000
using namespace std;

int main()
{
    int coins, target;
    int coin[MAX];
    scanf("%d %d", &coins, &target);
    for(int i = 0; i<coins; i++) {
        int temp;
        scanf("%d", &temp);
        coin[i] = temp;
    }
    sort(coin, coin+coins);
    int i = 0, j = coins-1;
    while(i<j)
    {
        if(coin[i]+coin[j] > target) {
            j--;
            continue;
        } else if (coin[i] + coin[j] < target) {
            i++;
            continue;
        } else if(coin[i] + coin[j] == target) {
            printf("%d %d", coin[i], coin[j]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
