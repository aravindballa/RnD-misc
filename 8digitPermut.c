#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

void swap(int *a, int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void printIt(int *a)
{
	int i;
	for (i = 0; i < 8; i++)
		printf("%d", a[i]);
	printf("\n");
}

void Permute(int *a)
{
	int low = 0, high = 7;
	while (low < 8){
		high = 7;
		while (low < high){
			printIt(a);
			swap(a, low, high);
			high--;
		}
		low++;
	}
	while (high >+ 0){
		low = 0;
		while (low < high){
			printIt(a);
			swap(a, low, high);
			low++;
		}
		high--;
	}
}

main()
{
	int a[8], i;
	for (i = 0; i < 8; i++)
	{
		scanf("%d", &a[i]);
	}

	Permute(a);

	_getch();
}