#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Grade {
	string name;
	string gender;
	string ID;
	int grade;
} grade;
vector<grade>grade_male;
vector<grade>grade_female;
bool flag_f = false, flag_m = false;
int grade_f = 0, grade_m = 0;

bool cmp_bigger(grade a, grade b)
{
    return a.grade>b.grade;
}
bool cmp_smaller(grade a, grade b)
{
    return a.grade<b.grade;
}

int main()
{
	int total;
	cin>>total;
	while(total--) {
		grade temp;
		cin>>temp.name>>temp.gender>>temp.ID>>temp.grade;
		if(temp.gender == "F")
			grade_female.push_back(temp);
		else if(temp.gender == "M")
			grade_male.push_back(temp);
	}
	sort(grade_female.begin(), grade_female.end(), cmp_bigger);
	sort(grade_male.begin(), grade_male.end(), cmp_smaller);
	if(!grade_female.empty()) {
		cout<<grade_female[0].name<<" "<<grade_female[0].ID<<endl;
		grade_f = grade_female[0].grade;
	}
	else {
		cout<<"Absent"<<endl;
		flag_f = true;
	}
	if(!grade_male.empty()) {
		cout<<grade_male[0].name<<" "<<grade_male[0].ID<<endl;
		grade_m = grade_male[0].grade;
	}
	else {
		cout<<"Absent"<<endl;
		flag_m = true;
	}
	if(flag_f || flag_m) {
		cout<<"NA";
		return 0;
	}
    
    cout<<grade_f-grade_m;

	return 0;
}
