#include <stdio.h>
#define MAX 10000 

typedef struct Content
{
	int begin;
	int count;
}Content;

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

void input(int * arr, int count)
{
	for(int i = 0; i<count; i++)
		scanf("%d", &arr[i]);
	
}

int maxSubSequence(int * input, int count)
{
	int thisSum = 0, maxSum = 0;
	for(int i = 0; i<count; i++)
	{
		thisSum += input[i];
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		else 
		{
			if(thisSum < 0)
				thisSum = 0; 
		}
			
	}
	return maxSum;
}

Content getcount(int * arr, int max, int total)
{
	int count = 0;
	int begin = 0;
	Content content;
	int sum;
	for(int i = 0; i<total; i++)
	{
		count = sum = 0;
		if(arr[i] < 0)
			continue;
		for(int j = i; j<total; j++)
		{
			sum += arr[j];
			count++;
			if(sum == max)
			{
				content.begin = i;
				content.count = count;
				return content;
			}
				
		}
	}
	content.begin = begin;
	content.count = count;
	return content;
}

int main()
{
	int total;
	int arr[MAX];
	Content content;
	scanf("%d", &total);	
	input(arr, total);
	if(scan(arr, total) == 1)
	{
		int maxSum = maxSubSequence(arr,total);
		int count = getcount(arr, maxSum, total).count - 1;
		int begin = getcount(arr, maxSum, total).begin;
		int end = count + begin;
		printf("%d %d %d", maxSum, arr[begin], arr[end]);
	}
	else
	{
		printf("0 %d %d", arr[0], arr[total-1]);
	}
	return 0;
}
