#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void changeto(int num, char * str)
{
	int flag = num;
	char temp[MAX];
	char result[MAX];
	int i = 0;
	if(num == 0)
	{
		temp[0] = '0';
		temp[1] = '\0';
//		printf("%s\n", temp);
		strcpy(str, temp);
		
		return;
	}
	if(num<0)
		num = -num;
	while(num)
	{
		temp[i] = num % 10 + '0';
		i++;
		num = num / 10;
	}
	if(flag < 0)
		temp[i++] = '-';
	int count = 0;
	while(i>=0)
		result[count++] = temp[--i];
//	result[count] = '\0';
//	printf("%s\n", result);
	strcpy(str, result);
}

void format(char * str, int num)
{
	char result[MAX];
	char tmp[MAX];
	changeto(num, result);
	if ( num >= 0)
	{
		int total, sign;
		char * p = result;
		int count = 0;
		while(*p != '\0')
			count++,p++;
		total = count;
		if(total % 3 == 0)
			sign = total / 3 - 1;
		else
			sign = total / 3;
		sign = total + sign;
		
		int i = 0;
		while(count >= 0)
			tmp[i++] = result[--count];
		i = 0;
		count = 0;
		while(i<total)
		{
			result[count++] = tmp[i++];
			if((i % 3 == 0) && count <sign)
				result[count++] = ',';
		}
		i = 0;
		while(count >= 0)
			tmp[i++] = result[--count];
		printf("%s", tmp);
	}
	else
	{
		int total;
		int sign;
	//	printf("%s\n", result);
		int count = 0;
		char * p = result;
		while(*p != '\0')
			count++, p++;
		total = count-1;
		for(int i = 0; count>=0; i++)
			tmp[i] = result[--count];
	//	printf("%s\n", tmp); 
		if((total) % 3 == 0)
			sign = (total) / 3 - 1;
		else
			sign = (total) / 3;
		sign = sign + total;
		
		int i = 0;
		count = 0;
		while(i<total)
		{
			result[count++] = tmp[i++];
			if((i % 3 == 0) && count <sign)
				result[count++] = ',';
		}
		result[count] = '-';
		for(i = 0; count >= 0; i++)
			tmp[i] = result[count--];
		tmp[i] = '\0';
				
		printf("%s", tmp);
		
	}
}

int main()
{
	int input_a, input_b;
	int result;
	
	scanf("%d %d", &input_a, &input_b);
	result = input_a + input_b;
	char str[MAX];
	format(str, result);
	return 0;
} 
