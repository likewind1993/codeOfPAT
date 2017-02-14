#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 5
using namespace std;
vector<int> list[26*26*26*10];
int getID(char * name)
{
    int id = 0; 
    for(int i = 0; i<3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}

int main()
{
    int search_nums = 0, course_nums = 0;
    char stu_name[MAX];
    scanf("%d %d", &search_nums, &course_nums);
    for(int i = 0; i<course_nums; i++)
    {
        
        int course_id = 0, stu_nums = 0;
        scanf("%d %d", &course_id, &stu_nums);
        while(stu_nums--)
        {
            scanf("%s", &stu_name);
            int stu_id = getID(stu_name);
            list[stu_id].push_back(course_id);
        }    
    }
    for(int i = 0; i<search_nums; i++)
    {
        scanf("%s", &stu_name);
        int id = getID(stu_name);
        printf("%s %ld",stu_name,list[id].size());
        sort(list[id].begin(), list[id].end());
        for(int j = 0; j<list[id].size(); j++)
            printf(" %d", list[id][j]);
        printf("\n"); 
    }
    return 0;
} 
