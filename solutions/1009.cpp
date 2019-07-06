#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct Item
{
	int exp;
	float poly;
	struct Item * next;
}Item;

Item * listCreate(int total)
{
	Item * head = (Item *)malloc(sizeof(Item));
	head->next = NULL;
	Item * p = head;
	if(total == 0)
		return head;
	for(int i = 0; i<total; i++)
	{
		Item * temp = (Item *)malloc(sizeof(Item));
		scanf("%d", &temp->exp);
		scanf("%f", &temp->poly);
		temp->next = NULL;
		
		p->next = temp;
		p = p->next;
	}
	
	return head;
}

int length(Item * input)
{
	Item * p = input;
	int count = 0;
	while((p = p->next) != NULL)
	{
		if(p->poly == 0)
			continue;
		count++;
	}
	return count;
}
void insert(Item * output, Item item)
{
	Item * p = output->next;
	if(p == NULL)
	{
		Item * temp = (Item *)malloc (sizeof(Item));
		temp->exp = item.exp;
		temp->poly = item.poly;
		temp->next = NULL;
		output->next = temp;
		return;
	}
	while(p->next != NULL)
	{
		if(p->exp == item.exp)
		{
			p->poly = p->poly + item.poly;
			return;
		}
		if((p->next)->exp == item.exp)
		{
			(p->next)->poly = (p->next)->poly + item.poly;
			return ;
		}
			
		if((p->exp)> item.exp && (((p->next)->exp)< item.exp))
			break;
		p = p->next;
	}
	if(p->next == NULL)
	{
		Item * temp = (Item *)malloc(sizeof(Item));
		temp->exp = item.exp;
		temp->poly = item.poly;
		temp->next = NULL;
		
		p->next = temp;
	}else
	{
		Item * q = p->next;
		Item * temp = (Item *)malloc(sizeof(Item));
		temp->exp = item.exp;
		temp->poly = item.poly;
		temp->next = q;
		p->next = temp;
	}
	
}

Item * product(Item * first, Item * second)
{
	int exp = 0;
	float poly = 0;
	Item * p = first;
	Item * output = listCreate(0); 
	while((p = p->next) != NULL)
	{
		Item * q = second;
		while((q = q->next) != NULL)
		{
			Item item;
			item.exp = p->exp + q->exp;
			item.poly = p->poly * q->poly;
			insert(output, item);
		}
	}
	return output;
}
void display(Item * output)
{
	
	printf("%d", length(output));
	Item * p = output;
	while((p = p->next) != NULL)
	{
		if(p->poly == 0)
			continue;
		printf(" %d %.1f", p->exp, p->poly);
	}
		
}
int main()
{
	int total;
	scanf("%d", &total);
	Item * first, * second, * output;
	first = listCreate(total);
	scanf("%d", &total);
	second = listCreate(total);
//	display(first);
	output = product(first, second);
	display(output);
	
	return 0;
		 
} 
