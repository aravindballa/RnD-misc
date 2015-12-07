#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

int LengthOf(char *array)
{
	int i=0;
	while (array[i] != '\0') i++;
	return i;
}

int isDivBy11(char* input, int k)
{
	int index, diff = 0;

	for (index = 0; input[index] != '\0'; index++)
	{
		if (index % 2 == 0) diff += k*(input[index] - '0');
		else diff -= k*(input[index] - '0');
	}

	if (diff % 11 == 0) return 1;
	else return -1;
}

int Check11Divisibility(char* input, int k)
{
	int len = LengthOf(input);
	//if the number is of odd length
	if (len % 2 != 0)
	{
		if (k % 2 == 0) return 1;
		else return isDivBy11(input, 1);
	}
	else return isDivBy11(input, k);
}

main()
{
	char input[20];
	int k;
	gets(input);
	scanf("%d", &k);

	printf("\n");
	
	if (Check11Divisibility(input, k) == 1) printf("It is divisible by 11!\n");
	else printf("It is NOT divisible by 11");

	_getch();
}