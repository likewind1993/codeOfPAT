#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define MAX 100
#define NUM 100
typedef struct Person
{
	char ID_number[NUM];
	char Sign_in_time[NUM];
	char Sign_out_time[NUM];
	struct Person * next;
}Person;

Person * listCreate(int num)
{
	Person * head, * p, * temp;
	head = (Person *)malloc(sizeof(Person));
	p = head;
	for( int i = 0; i<num; i++)
	{
		temp = (Person *)malloc(sizeof(Person));
		char tem[NUM];
		scanf("%s", tem);
		strcpy(temp->ID_number, tem);
		
		scanf("%s", tem);
		strcpy(temp->Sign_in_time, tem);
		
		scanf("%s", tem);
		strcpy(temp->Sign_out_time, tem);
		
		temp->next = NULL;
		
		p->next = temp;
		p = p->next;
	} 
	return head;
}

int bigger(char * input1, char * input2)
{
	for(int i = 0; i<8; i++)
	{
		if(input1[i] == ':')
			continue;
		if(input1[i] > input2[i])
			return 1;
		if(input1[i] < input2[i])
			return 0;
	}
}
void str_cpy(char * dest, char * src)
{
	int i;
	for(i = 0; i<8; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}


void findunlock(Person * head)
{
	char sign_in [NUM];
	char name[NUM];
	Person * init = head->next;
	str_cpy(sign_in, init->Sign_in_time);
	strcpy(name, init->ID_number);
	Person * p = head;
	while((p = p->next) != NULL)
	{
		if(bigger(sign_in, p->Sign_in_time) == 1)
		{
			str_cpy(sign_in, p->Sign_in_time);
			strcpy(name, p->ID_number);
		}
			
	}
	printf("%s ", name);
} 

void findlock(Person * head)
{
	char sign_in [NUM];
	char name[NUM];
	Person * init = head->next;
	str_cpy(sign_in, init->Sign_out_time);
	strcpy(name, init->ID_number);
	Person * p = head;
	while((p = p->next) != NULL)
	{
		if(bigger(sign_in, p->Sign_out_time) == 0)
		{
			str_cpy(sign_in, p->Sign_out_time);
			strcpy(name, p->ID_number);
		}
			
	}
	
	printf("%s", name);

}

int main()
{
	int total = 0;
	scanf("%d", &total);
	
	Person * person;
	person = listCreate(total);
	
	findunlock(person);
	findlock(person);
	
	return 0;
}
