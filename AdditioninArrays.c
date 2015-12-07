/*

Addition in Arrays
i/p-
1 2 3 4 5
    5 2 0

o/p-
----------
1 2 8 6 5
----------

*/

#include<stdio.h>

void GetSum(int *a, int n, int *b, int m)
{
	int maxSize = (n > m) ? n : m, i;
	int *c = (int*)malloc(maxSize*sizeof(int));
	int cIndex = maxSize, adigit, bdigit;
	n--; m--;
	for (i = maxSize; i > 0; i--)
	{
		if (n < 0) adigit = 0;
		else adigit = a[n];
		if (m < 0) bdigit = 0;
		else bdigit = b[m];
		m--; n--;

		if(c[cIndex]>0 ) c[cIndex] = c[cIndex] + adigit + bdigit;
		else c[cIndex] = adigit + bdigit;

		if (c[cIndex] > 9)
		{
			c[cIndex - 1] = c[cIndex] / 10;
			c[cIndex] = c[cIndex] % 10;
		}
		cIndex--;
	}
	if (c[0] < 0) c[0] = 0;

	for (i = 0; i <= maxSize; i++)
		printf("%d", c[i]);

	
}

main()
{
	int a[12], b[12], *c, n, m, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	scanf_s("%d", &m);
	for (i = 0; i < m; i++)
		scanf_s("%d", &b[i]);

	GetSum(a, n, b, m);

	_getch();

}