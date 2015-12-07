#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int DigitProd(long int num)
{
	int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	long int product = 1;

	while (num > 0)
	{
		product *= primes[(num % 10)];
		num = num / 10;
	}

	return product;
}

int SameDigitsinRes(long int a, int multiplier)
{
	if (DigitProd(a) == DigitProd(multiplier*a))
		return 1;
	return -1;
}

void GetNumbers(long int digits)
{
	long int i;
	int count = 0, multiplier;
	for (multiplier = 2; multiplier <= 8; multiplier++)
	{
		count = 0;
		for (i = 100000; i < 999999/multiplier; i++)
		{
			if (SameDigitsinRes(i, multiplier) == 1)
			{
				printf("%d\n", i);
				count++;
			}
		}
		printf("%ld numbers with multiplier %d\n\n", count, multiplier);
	}
}

main()
{
	long int digits = 6;
	//scanf("%ld", &input);

	GetNumbers(digits);


	_getch();
}