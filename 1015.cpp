#include <stdio.h>
#define MAX 4000 
#define NUM 10

int isPrime(int input)
{
	if(input <= 2)
		return 1;
	for(int i = 2; i<input/2; i++)
	{
		if((input % i) == 0 )
			return 0;
	}
	return 0;
	
}

int main()
{
	int input[NUM]
}
