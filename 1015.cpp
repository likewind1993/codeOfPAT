#include <stdio.h>
#define MAX 10000
#define MAX_ 100000

int isPrime(int input)
{
	if(input == 2)
		return 1;
	for(int i = 2; i<=input / 2; i++)
	 	if(input % i == 0)
	 		return 0;
	return 1;
}

int power(int base, int exp)
{
	if(exp == 0)
		return 1;
	int result = 1;
	for(int i = 0; i<exp; i++)
		result = result * base;
	return result;
}

int decToRadix(int input, int radix)
{
	if(input == 1)
	{
		printf("No");
		return 0;
	}
	
	int input_origin = input;
	int * result = new int [MAX_];
	int count = 0;
	while(input != 0)
	{
		result[count++] = input % radix;
		input = input / radix;
	}
	
	int reverse_num = 0;
	for(int i = 0; i<count; i++)
		reverse_num = reverse_num + result[count - i -1] * power(radix,i); 
	if(reverse_num == 1)
	{
		printf("No");
		return 0;
	} 
	if((isPrime(reverse_num) == 1) && (isPrime(input_origin) == 1)) 
		printf("Yes");
	else
		printf("No");
	return 0;
	
}


int main()
{
	int input[MAX];
	int radix[MAX];
	int count = 0;
	
	scanf("%d", &input[count]);
	while(input[count] > 0)
	{
		scanf("%d", &radix[count]);
		count++;
		scanf("%d", &input[count]);
	}
	
	
	
	for(int i = 0; i<count; i++)
	{
		decToRadix(input[i], radix[i]);
		if(i<count-1)
			printf("\n");
	} 
		
	
	return 0;
}

//usage: 2 2
