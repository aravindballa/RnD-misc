#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void NextBase(int *pre, int *curr)
{
	int t = *curr;
	int p = *pre;
	*curr = t + p;
	*pre = t;
}

int PrevBase(int *pre, int *curr)
{
	int t = *curr;
	*curr = *pre;
	*pre = t - *pre;
}

void GetBF(int input)
{
	int output[10] = { 0 }, result = 0, i = 0, j;

	int curr = 1, pre = 0;
	/* Upward */
	while (result < input)
	{
		output[i++] = 1;
		result += curr;
		NextBase(&pre, &curr);
	}

	/* Downward	*/
	i = i - 2;
	PrevBase(&pre, &curr);
	PrevBase(&pre, &curr);
	while (i > 0)
	{
		if (result == input) break;

		if ((result - curr) < input)
		{
		}
		else if ((result - curr) >= input)
		{
			result -= curr;
			output[i] = 0;
		}
		i--;
		PrevBase(&pre, &curr);
	}

	for (j = 9; j >= 0; j--)
		printf("%d", output[j]);

}

main()
{
	int input;
	scanf("%d", &input);

	GetBF(input);

	_getch();
}