/* Given an array where every element is repeated thrice except one element which 
occurs only once. Find that one. */

#include<stdio.h>

int Search(int *a, int k, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == k) return i;
	}
	return -1;
}

int OccuredOnce(int *input, int n)
{
	int elements[15], i, j=0, k;
	int eleCount[15] = {0};
	for (i = 0; i < n; i++)
	{
		k = Search(elements, input[i], n);
		if (k == -1)
		{
			elements[j] = input[i];
			eleCount[j++]++;
			continue;
		}
		eleCount[k]++;
	}

	for (i = 0; i < n; i++)
	{
		if (eleCount[i] == 1) return elements[i];
	}

}

main()
{
	int input[15], n, i;
	printf("how many elements?\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &input[i]);

	printf("\n%d", OccuredOnce(input, n));

	_getch();
}