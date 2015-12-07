#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

int isDivisibleBy11_1(char* input)
{
	int diff, evenSum = 0, oddSum = 0, index;

	//calculating the difference between even and odd positioned digits
	for (index = 0; input[index] != '\0'; index++)
	{
		if (index % 2 == 0) evenSum += input[index] - '0';
		else oddSum += input[index] - '0';
	}
	diff = evenSum - oddSum;

	if (diff % 11 == 0) return 1;
	else return -1;
}

int isDivisibleBy11_2(char* input)
{
	int diff = 0, index;
	for (index = 0; input[index] != '\0'; index++)
	{
		diff += input[index++] - '0';
		diff -= input[index] - '0';
	}

	if (diff % 11 == 0) return 1;
	else return -1;
}

main()
{
	char input[20];
	gets(input);

	printf("\n");
	if (isDivisibleBy11_2(input) == 1) printf("1 - It is divisible by 11!\n");
	else printf("1 - It is NOT divisible by 11\n");

	if (isDivisibleBy11_2(input) == 1) printf("2 - It is divisible by 11!\n");
	else printf("2 - It is NOT divisible by 11");

	_getch();
}