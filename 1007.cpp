#include <stdio.h>
#define MAX 100000

int positive(int * input, int position, int total)
{
	int count = 0;
	while(position < total)
	{
		count += input[position++];
		if(count > 0)
			return 1;
	}
	return 0;
}

int scan(int * input, int total)
{
	int count = 0;
	for(int i = 0; i<total; i++)
	{
		if(input[i]<0)
			count++;
	}
	if(count == total)
		return 0;
	return 1;
} 

int main()
{
	int total, sum = 0;
	int begin = 0, count = 0;
	int flag = 0;
	int input[MAX];
	scanf("%d", &total);
	int i;
	for( i = 0; i<total; i++)
		scanf("%d", &input[i]);
	if(scan(input, total) == 1)
	{
		for(i = 0; i<total; i++)
		{
			int haspositive = positive(input, i, total);
			if(input[i] > 0)
			{
				if((flag == 0) && (haspositive == 1))
				{
					flag = 1;
					begin = i;
				}
				sum = sum + input[i];
				count++;	
			}
			
			if(input[i] < 0)
			{
				if(i == 0)
				{
					continue;
				}
				if(haspositive == 1)
				{
					sum = sum + input[i];
					count++;
				}
				else
				{
					continue;
				}
			}
			if(input[i] == 0)
			{
				if(flag == 1)
					count++;
				continue;
			}
		} 
		printf("%d %d %d", sum, begin, begin + count - 1);
	}else
	{
		printf("0 %d %d", input[0], input[total-1]);
	} 
	return 0;
}
