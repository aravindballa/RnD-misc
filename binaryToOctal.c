#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int octal(int n)
{
	int octal = 0, d = 0, i = 0;
	while (n != 0)
	{
		d += (n % 10)*pow(2, i);
		++i;
		n /= 10;
	}

	i = 1;
	while (d != 0)
	{
		octal += (d % 8)*i;
		d /= 8;
		i *= 10;
	}
	return octal;
}

main()
{
	int n;
	scanf("%d", &n);

	printf("%d", octal(n));
}