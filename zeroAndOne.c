#include <stdio.h>

void sortArray1(int a[], int n)
{
	int index, zeros = 0;
	for (index = 0; index < n; index++)
		if (a[index] == 0) zeros++;

	for (index = 0; index < zeros; index++)
		a[index] = 0;

	for (index = zeros; index < n; index++)
		a[index] = 1;
}

void sortArray2(int a[], int n)
{
	int i, countOnes = 0;
	for (i = 0; i < n; i++){
		countOnes += a[i];
	}

	for (i = n - 1; i >= 0; i--){
		if(countOnes == 0) a[i] = 0;
		else{
			a[i] = 1; countOnes--;
		}
	}
}

void sortArray3(int a[], int n)
{
	int left = 0, right = n - 1;

	while (left < right)
	{
		while (a[left] == 0 && left < right)
			left++;
		while (a[right] == 1 && left < right)
			right--;

		if (left < right)
		{
			a[left] = 0;
			a[right] = 1;
			left++;
			right--;
		}
	}
}


main()
{
	int a[100], n, index;
	scanf_s("%d", &n);

	for (index = 0; index < n; index++)
		scanf_s("%d", &a[index]);

	sortArray2(a, n);

	for (index = 0; index < n; index++) 
		printf("%d ", a[index]);

	_getch();
}



