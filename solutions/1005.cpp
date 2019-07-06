#include <stdio.h>
#define MAX 100
void digitTochar(int input, char * chars)
{
	int i = 0, count = 0, total = 0;
	char temp[MAX];
	while(input != 0)
	{
		temp[i++] = input % 10 + '0';
		input = input / 10;
		total++;
	}
	
	while(i>=0)
		chars[count++] = temp[--i];
	chars[total] = '\0';
	
}
void Input(char * chars)
{
	int i = 0;
	char ch; 
	while((ch = getchar()) != '\n')
		chars[i++] = ch;
	chars[i] = '\0';
}

int Getsum(char * chars)
{
	int sum = 0;
	int i = 0;
	while(chars[i] != '\0')
	{
		sum += chars[i] - '0';	
		i++;
	}
	
	return sum;
}
void Display(char * chars)
{
	char * p = chars;
	while(*p != '\0')
	{
		switch (*p)
		{
			case '0':
				printf("zero");
				break;
			case '1':
				printf("one");
				break;
			case '2':
				printf("two");
				break;
			case '3':
				printf("three");
				break;
			case '4':
				printf("four");
				break;
			case '5':
				printf("five");
				break;
			case '6':
				printf("six");
				break;
			case '7':
				printf("seven");
				break;
			case '8':
				printf("eight");
				break;
			case '9':
				printf("nine");
				break;
		}
		if(*(p+1) != '\0')
			printf(" ");
		p++;
	}
}

int main()
{
	int input = 0;
	int sum = 0;
	char chars[MAX];
	
	Input(chars);
	sum = Getsum(chars);
	if(sum == 0)
	{
		printf("zero");
		return 0;
	}
	digitTochar(sum, chars);
	Display(chars);
	
	return 0;
}
