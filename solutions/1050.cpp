#include <cstdio>
#define MAX 10000
using namespace std;

char input[MAX];
char output[MAX];
char sub[MAX]; 

int main()
{
	gets(input);
	gets(sub);
	int count_input = 0, count_sub = 0;
	char * pointer = input;
	
	while(*(pointer++) != NULL)
		count_input++;
	pointer = sub;
	while(*(pointer++) != NULL)
		count_sub++;
	
	pointer = input;
	int temp = 0;
	while(*(pointer) != NULL)
	{
		char * p = sub;
		int i;
		for(i = 0; i<count_sub; i++)
			if(*pointer == sub[i])
				break;
		if(i == count_sub)
			output[temp++] = *pointer;
		pointer++;
	}
	
	printf("%s", output);
	return 0;
}
