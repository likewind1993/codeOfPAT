#include <stdio.h>
#define MAX 20

typedef char Digites[MAX] ;

long long product(long long radix, int index)
{
	if(index == 0)
		return 1;
	int temp = radix;
	for(int i = 1; i<index; i++)
		radix = radix * temp;
	return radix;
}

long long changeToTen(char * input, int count, int radix)
{
	long long sum = 0;
	int i = 0;
	while(--count >= 0)
	{
		int temp = input[count];
		if(temp > '9')
			temp = temp - 87;
		else
			temp = temp - 48;
		sum = sum + temp * product(radix, i);
		i++;
	}
	
	return sum;
}

int input(char * input)
{
	int count = 0; 
	char ch;
	while((ch = getchar()) != ' ')
		input[count++] = ch;
	
	input[count] = '\0';
	return count;
}
int findSmallRadix(char * input, int count)
{
	int temp = -1;
	while(--count >= 0)
	{
		if(temp < input[count])
			temp = input[count];
	}
	
	if(temp > 96)
		temp = temp - 87;
	else
		temp = temp - 48;
	return temp;
}


int main()
{
	Digites input1, input2;
	int tag, radix, input1_nums, input2_nums;
	long long nums, nums2;
	input1_nums = input(input1);
	input2_nums = input(input2);
	scanf("%d", &tag);
	scanf("%d", &radix);
	
	long long Radix = -1, smallRadix;
	
	if(tag == 1)
	{
		nums = changeToTen(input1, input1_nums, radix);
		smallRadix = findSmallRadix(input2, input2_nums);
		nums2 = changeToTen(input2, input2_nums, smallRadix);
		while(nums > nums2)
		{
			if(input2_nums <= 1)
				break;
			long long temp = changeToTen(input2, input2_nums, ++smallRadix);
			if(nums == temp)
			{
				Radix = smallRadix;
				break;
			}
		}
		if( nums == nums2)
			Radix = smallRadix;
	}else
	{
		nums2 = changeToTen(input2, input2_nums, radix);
		
		smallRadix = findSmallRadix(input1, input1_nums);
		nums = changeToTen(input1, input1_nums, smallRadix);
		while(nums < nums2)
		{
			if(input1_nums <= 1)
				break;
			long long temp = changeToTen(input1, input1_nums, ++smallRadix);
			if(nums2 == temp)
			{
				Radix = smallRadix;
				break;
			}
		}
		if( nums == nums2)
			Radix = smallRadix;
	}
	
	if(Radix == -1)
		printf("Impossible");
	else 
		printf("%d", Radix);
	return 0;
} 

//构造的测试数据
//1 0 1 10
//171 ab 1 10
//ab 171 2 10
//zzzz zz 1 1000
