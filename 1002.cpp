#include <stdio.h>
#include <stdlib.h>
typedef struct poly{
	int exp;
	float coeff;
	struct poly * next;
}poly;

poly * listCreate(int num)
{
	poly * head = (poly *)malloc(sizeof(poly));
	poly * p = head;
	poly * temp;
	if(num == 0)
	{
		head->next = NULL;
		return head;
	}
	for(int i = 0; i< num; i++)
	{
		int exp;
		float coeff;
		temp = (poly *)malloc (sizeof(poly));
		scanf("%d %f", &exp, &coeff);
		
		temp->exp = exp;
		temp->coeff = coeff;
		p->next = temp;
		p = p->next;
		temp->next = NULL;
	}
	
	return head;
}

void listDisplay(poly *head)
{
	int sub = 0;
	poly * p = head;
	while((p = p->next)!= NULL)
	{
		if(p->coeff == 0)
			continue;
		printf(" %d %.1f",p->exp, p->coeff);
	} 
}
int listLength(poly * head)
{
	poly * p = head;
	int count = 0;
	while((p = p->next)!= NULL)
	{
		if(p->coeff == 0)
			continue;
		count++;
	}

	return count;
}

poly * listAdd(poly * a, poly * b)
{
	poly * tmp_a = a->next, * tmp_b = b->next;
	poly * head = (poly *)malloc(sizeof(poly));
	poly * p;
	p = head; 
	while((tmp_a != NULL) && (tmp_b  != NULL))
	{
		if(tmp_a->exp > tmp_b->exp)
		{
			poly * temp = (poly *)malloc(sizeof(poly));
			temp->exp = tmp_a->exp;
			temp->coeff = tmp_a->coeff;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
			tmp_a = tmp_a->next;
		}else if(tmp_a->exp == tmp_b->exp)
		{
			poly * temp = (poly *)malloc(sizeof(poly));
			float add = tmp_a->coeff + tmp_b->coeff;
				temp->exp = tmp_a->exp;
				temp->coeff = add;
				temp->next = NULL;
		    	p->next = temp;
			    p = p->next;
				tmp_a = tmp_a->next;
				tmp_b = tmp_b->next;
		}
		else{	
			poly * temp = (poly *)malloc(sizeof(poly));		
			temp->exp = tmp_b->exp;
			temp->coeff = tmp_b->coeff;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
			tmp_b = tmp_b->next;
		}
	}
	while(tmp_a != NULL)
	{
		poly * temp = (poly *)malloc(sizeof(poly));		
		temp->exp = tmp_a->exp;
		temp->coeff = tmp_a->coeff;
		temp->next = NULL;
		p->next = temp;
		p = p->next;
		tmp_a = tmp_a->next;
	}
	while(tmp_b != NULL)
	{
		poly * temp = (poly *)malloc(sizeof(poly));		
		temp->exp = tmp_b->exp;
		temp->coeff = tmp_b->coeff;
		temp->next = NULL;
		p->next = temp;
		p = p->next;
		tmp_b = tmp_b->next;
	}
	
	return head;
}

int main()
{
	int num = 0;
	int sub = 0;
	poly * first, * second, * result;
	scanf("%d", &num);
	first = listCreate(num);

	scanf("%d", &num);
	second = listCreate(num);
	
	result = listAdd(first, second);
	if(listLength(result) == 0)
		printf("0");
	else
	{
		printf("%d", listLength(result));
		listDisplay(result);
	}
	return 0;
}

//2 1 1.5 2 -2
//2 2 2 0 0.4
