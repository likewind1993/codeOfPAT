#include <cstdio>
#include <cstring>
#define MAX 10000

int dp[MAX][MAX];
char arr[MAX];
int main()
{
    gets(arr);
    int max = 1;
    int len = strlen(arr);
    for(int i = 0; i<len; i++)
    {
        dp[i][i] = 1;
        if(arr[i] == arr[i+1] && i<len-1)
        {
            dp[i][i+1] = 1;
            max = 2;
        }
    }
    for(int L = 3; L<=len; L++)
    {
        for(int i = 0; i + L - 1 <len; i++)
        {
            int j = i + L - 1;
            if(arr[i] == arr[j] && dp[i+1][j-1] == 1)
            {
                dp[i][j] = 1;
                max = L;    
            }    
        }        
    }
    printf("%d", max);
    return 0;
}
