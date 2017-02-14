#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vec;
int main()
{
    int nums;
    cin>>nums; 
    for(int i = 0; i<nums; i++)
    {
        string name, pass;
        cin>>name>>pass;
        bool flag = false;
        for(int j = 0; j<pass.length(); j++)
        {
            switch(pass[j]){
                case '1': 
                    pass[j] = '@';
                    flag = true;
                    break;
                case 'l':
                    pass[j] = 'L';
                    flag = true;
                    break;
                case 'O':
                    pass[j] = 'o';
                    flag = true;
                    break;
                case '0':
                    pass[j] = '%';
                    flag = true;
                    break;
            }
        }
        if(flag)
            vec.push_back(name + " " + pass);
    } 
    if(!vec.empty())
    {
        cout<<vec.size()<<endl;
        for(int i = 0; i<vec.size(); i++)
            cout<<vec[i]<<endl;
    }
        
    else
    {
        if(nums == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", nums);
    }
    return 0;
} 
