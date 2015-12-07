#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

int sumOfDigits(char *input)
{
	int index, sum = 0;
	for (index = 0; input[index] != '\0'; index++){
		sum += input[index] - '0';
	}
}

void isDivisibleBy3(char* input, int k)
{
	if (k % 3 == 0)
	{
		printf("It is divisible by 3");
		return;
	}
	if(sumOfDigits(input) % 3 == 0)
	{
		printf("It is divisible by 3");
		return;
	}
	printf("It is divisible NOT by 3");
}


main()
{
	char input[20];
	int k;
	gets(input);
	scanf("%d", &k);

	isDivisibleBy3(input, k);

	_getch();
}