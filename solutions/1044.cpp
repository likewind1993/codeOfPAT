#include <cstdio>
#include <vector>
#define INF 0x7fffffff
#define MAX 10000000
using namespace std;

int arr[MAX];
int des[MAX];
vector<int> output;
//arr represent sums
int total = 0, target = 0;
int mini = INF;

int binsearch(int curr, int right)
{
    int left = curr+1;
    int mid = 0;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(arr[mid] - arr[curr] >= target)
            right = mid;
        else    
            left = mid + 1;
    }
    des[curr] = right;
    return arr[right] - arr[curr];
}

int main()
{
    scanf("%d %d", &total, &target);
    arr[0] = 0;
    for(int i = 1; i<=total; ++i) {
        int temp = 0;
        scanf("%d", &temp);
        arr[i] = arr[i-1] + temp;
    }
    
    for(int i = 0; i<total; i++) {
        int res = binsearch(i, total);
        if(res >= target) {
            if(res == mini)
            {
                output.push_back(i);
            } else if(res < mini){
                mini = res;
                output.clear();
                output.push_back(i);
            }
        } else {
            break;
        }
    }

    
    for(int i = 0; i<output.size(); i++)
    {
        printf("%d-%d\n", output[i]+1, des[output[i]]);
    }
    return 0;
}
