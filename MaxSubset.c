#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int* MaxSubset(int *input, int n)
{
	int subset[10];
	int i, cum = 0, help = 0, j, k=0;
	for (i = 0; i < n; i++)
	{
		if (input[i] < 0)
		{
			j = i;
			while (input[j] < 0)
			{
				help += input[j++];
			}
			help += input[j];

			if (cum + help > cum && cum + input[i] > 0)
			{
				subset[k++] = input[i];
				cum += input[i];
			}
			else if (cum + input[i] <= 0)
			{
				k = 0;
			}
			else break;
		}
		else
		{
			subset[k++] = input[i];
			cum += input[i];
		}
	}

	return subset;
}

main()
{
	int input[10] = { 2, -2, 4, 6, 5, -6, 8, 12, -22, 14 };

	int *result = MaxSubset(input, 10);

	_getch();
}