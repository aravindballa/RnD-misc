#include<stdio.h>
//input - size(length of number) less than 5
//input - number

/*Returns the index of the element searched for*/
int searchEle(int *a, int n, int k){
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == k) return i;
	return -1;
}

/*Bubble Sort*/
void sortarray(int *a, int n){
	int i, j, t;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1]){
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

int minRank(int n, int r, int size)
{
	/*Input is stored into an array a[]*/
	int a[5], i = 0, required[5], minRank = 0;
	while (n > 0)
	{
		a[i++] = n % 10;
		n = n / 10;
	}

	sortarray(a, size);

	//the required element is stored into required[]
	i = 0;
	while (r > 0)
	{
		required[(size - 1) - i] = r % 10;
		r = r / 10;
		i++;
	}

	for (i = 0; i < size; i++){
		minRank = minRank + (((size - 1) - i) * searchEle(a, size, required[i]));
	}

	return minRank;
}

main(){

	int original, req, n;

	scanf_s("%d", &n);
	while (n > 5)
	{
		printf("Please enter less than or equal to 5 digits \n");
		scanf_s("%d", &n);
	}

	scanf_s("%d", &original);

	req = original;

	printf("%d", minRank(original, req, n));


	_getch();

}