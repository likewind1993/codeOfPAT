#include <stdio.h>
#define MAX 100

int main()
{
	int total;
	int input[MAX];
	scanf("%d", &total);
	for(int i = 0; i<total; i++)
		scanf("%d", &input[i]);
	
	int position = 0, sum = 0;
	for(int i = 0; i<total; i++)
	{
		if(input[i] > position)
		{
			sum = sum + (input[i] - position) * 6;
			position = input[i];
			sum = sum + 5;
		}else if(input[i] < position)
		{
			sum = sum + (position - input[i]) * 4;
			position = input[i];
			sum = sum + 5;
		}else if(input[i] == position)
			sum = sum + 5;
	}
	
	printf("%d", sum);
	
	return 0;
}
