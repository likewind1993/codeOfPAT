#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef struct STU{
    char ID[10];
}stu;

map<int, vector<stu> > Map;
int stu_nums, course_nums;

bool compare(stu a, stu b)
{
    return strcmp(a.ID, b.ID)<0;
}

int main()
{
    scanf("%d %d", &stu_nums, &course_nums);
    for(int i = 0; i<stu_nums; i++) {
        stu stu_temp;
        int k;
        scanf("%s %d", &stu_temp.ID, &k);
        while(k--) {
            int courseID;
            scanf("%d", &courseID);
            Map[courseID].push_back(stu_temp); 
        }
    }
    
    for(int i = 1; i<=course_nums; i++)
    {
        
        printf("%d ", i);
        printf("%d\n", Map[i].size());
        if(Map[i].size() == 0)
            continue;
        vector<stu>::iterator iter = Map[i].begin();
        sort(Map[i].begin(), Map[i].end(), compare);
        for(; iter != Map[i].end(); iter++) {
            printf("%s\n", (*iter).ID); 
        }
    }
    return 0;
} 
