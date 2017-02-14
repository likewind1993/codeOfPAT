#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string str[10000];
bool compare(string a, string b)
{
    return (a+b)<(b+a);
}
int main()
{
    int nums; 
    string result;
    cin>>nums;
    for(int i = 0; i<nums; i++)
        cin>>str[i];
    sort(str, str+nums, compare);  
    for(int i = 0; i<nums; i++)
        result += str[i];
    while(result.length() != 0 && result[0] == '0')
        result.erase(result.begin());
    if(result.length() != 0)  
        cout<<result;
    else
        cout<<0;
    return 0;
}   
