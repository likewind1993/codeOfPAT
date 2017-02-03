#include <stdio.h>
#include <stdlib.h>
#define ID 6
#define MAX 2000
typedef struct Stu
{
	char id [ID];
	int c_score;
	int m_score;
	int e_score;
	int avg;
	Stu * next;
}Stu;

Stu * Stuinput(int count)
{
	Stu * head = (Stu *)malloc(sizeof(Stu));
	Stu * p;
	head->next = NULL;
	p = head;
	for(int i = 0; i<count; i++)
	{
		Stu * temp = (Stu * )malloc(sizeof(Stu));
		scanf("%s", &temp->id);
		scanf("%d", &temp->c_score);
		scanf("%d", &temp->m_score);
		scanf("%d", &temp->e_score);
		temp->avg = (temp->c_score + temp->m_score + temp->e_score) / 3;
		
		temp->next = NULL;
		
		p->next = temp;
		p = p->next;
	}
	
	return head;
}

int main()
{
	int total, check_num;
	int avg[3];
	scanf("%d %d", &total, &check_num);
	
	Stu * stus = Stuinput(total);
	
	
	
	return 0;
}
