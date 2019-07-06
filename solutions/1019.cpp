#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void display(int * input, int total)
{
	for(int j = total-1; j>=0; j--)
	{
		printf("%d",input[j]);
		if(j>0)
			printf(" ");
	}
}

int paLind(int * input, int total)
{
	for(int i = 0; i<total/2; i++)
	{
		if(input[i] != input[total-i-1])
			return 0;
	}
	return 1;
}

void generNums(int input, int radix)
{

	int * output = new int [MAX];
	int count = 0;
	if(input == 0)
	{
		output[0] = 0;
		count++;
	}
	else
	{
		while(input != 0)
		{
			output[count++] = input % radix;
			input = input / radix; 
		}
	}
	int flag = paLind(output, count); 
	if(flag == 1)
		printf("Yes\n");
	else
		printf("No\n");
	
	display(output, count);
}

int main()
{
	int input, radix;
	scanf("%d %d", &input, &radix);
	generNums(input, radix);
	return 0;
}
