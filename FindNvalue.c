#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

int nValue(int *a)
{
	int j = 1;
	while (j < 50)
	{
		if (a[j - 1] < a[j] && a[j + 1] > a[j] && a[j] != 0)
			j = j * 2;
	}
	if (a[j] == 0)
		while (a[j - 1] == 0) j--;

	if (a[j] == 0)
		return j-2;
}

main()
{
	int a[50], i, k;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("%d", nValue(a));
}