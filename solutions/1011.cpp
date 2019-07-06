#include <stdio.h>
#include <math.h>
#define MAX 10

float choose(int i, float input[MAX][MAX])
{
	int position = 0; 
	float big = 0;
	big = input[i][position];
	for(int j = 1; j<3; j++)
	{
		if(big < input[i][j])
		{
			big = input[i][j];
			position = j;
		}
	}
	switch (position)
	{
		case 0:
			printf("W ");
			break;
		case 1:
			printf("T ");
			break;
		case 2:
			printf("L ");
			break;
	}
	return big;
}

int main()
{
	float input[MAX][MAX];
	
	for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
			scanf("%f", &input[i][j]);
	
	float first = choose(0, input);
	float second = choose(1, input);
	float third = choose(2, input);
	float result = (first * second * third * 0.65 - 1) * 2;
	if((int)(result*1000) % 10 >4)
		result = result + 0.01; 
	printf("%.2f",result);
	
	return 0;
}
