#include<stdio.h>


void computeArray1(int a[], int b[], int n)
{
	int i, j, product=1;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
		{
			if(i!=j && a[j]!=0) product *= a[j];
		}
		b[i] = product;
	}
}

void computeArray2(int a[], int b[], int n)
{
	int product = 1, i;

	for  (i = 0; i < n; i++)
		if(a[i] !=0) product *= a[i];

	for (i = 0; i < n; i++)
		if (a[i] != 0) b[i] = product / a[i];
		else b[i] = product;
}

void computeArray3(int a[], int b[], int n)
{
	int lma[10], rma[10], i;
	lma[0] = a[0]; rma[n - 1] = a[n - 1];

	for (i = 1; i < n; i++)
	{
		lma[i] = lma[i - 1] * a[i];
		rma[(n - 1) - i] = rma[n - i] * a[n - 1 - i];
	}

	for (i = 1; i < n - 1; i++)
	{
		b[i] = lma[i - 1] * rma[i + 1];
	}
	b[0] = rma[1]; b[n - 1] = lma[n - 2];

}

void computeArray4(int a[], int b[], int n)
{
	int lma[10], i;
	lma[0] = a[0]; b[n - 1] = a[n - 1];

	for (i = 1; i < n; i++)
	{
		lma[i] = lma[i - 1] * a[i];
		b[(n - 1) - i] = b[n - i] * a[n - 1 - i];
	}

	b[0] = b[1];
	for (i = 1; i < n - 1; i++)
	{
		b[i] = lma[i - 1] * b[i + 1];
	}
	b[n - 1] = lma[n - 2];

}

void computeArray5(int a[], int b[], int n)
{
	int i, lm = a[0];
	b[n - 1] = a[n - 1];

	for (i = 1; i < n; i++)
	{
		b[(n - 1) - i] = b[n - i] * a[n - 1 - i];
	}

	b[0] = b[1];
	for (i = 1; i < n - 1; i++)
	{
		b[i] = lm * b[i + 1];
		lm *= a[i];
	}
	b[n - 1] = lm;

}

main()
{
	int a[10], b[10], i, n;
	scanf_s("%d", &n);

	for ( i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}

	computeArray5(a, b, n);

	for (i = 0; i < n; i++)
		printf("%d  ", b[i]);

	_getch();
}