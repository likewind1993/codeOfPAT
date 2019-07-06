#include <map>
#include <iostream>
#define MAX 1000
using namespace std;
int n, target;
int graph[MAX][MAX];
int weight[MAX];
bool visit[MAX];
map<string,int>strtoi;
map<int, string>itostr;
map<string, int>ans;
int id = 1;
int strtoifunc(string s1)
{
    if(strtoi[s1] == 0)
    {
        strtoi[s1] = id;
        itostr[id] = s1;
        return id++;
    }
    return strtoi[s1];
}

void dsf(int begin, int & head, int & nums, int &total_w)
{
    visit[begin] = true;
    nums++;
    if(weight[begin] > weight[head])
        head = begin;
    for(int i = 1; i<id; i++)
    {
        if(graph[begin][i] > 0)
        {
            total_w += graph[begin][i];
            graph[begin][i] = graph[i][begin] = 0;
            if(visit[i] == false)
                dsf(i, head, nums, total_w);
        }
    }
}

void dsfTravel()
{
    for(int i = 1; i<id; i++)
    {
        if(visit[i] == false)
        {
            int head = i, nums = 0, total_w = 0;
            dsf(i, head, nums, total_w);
            //cout<<total_w<<endl;
            if(nums > 2 && total_w > target)
                ans[itostr[head]] = nums;
        }
    }
}

int main()
{
    cin>>n>>target;
    string s1, s2;
    int w;
    while(n--)
    {
        cin>>s1>>s2>>w;        
        int id1 = strtoifunc(s1);
        int id2 = strtoifunc(s2);
        graph[id1][id2] += w;
        graph[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    }
    dsfTravel();
    cout<<ans.size()<<endl;
    
    for(map<string, int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout<<it->first<<" "<<it->second<<endl; 
    
    return 0;
}
