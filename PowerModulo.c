#include<stdio.h>

int powerModulo1(int x, int y, int a){
	int powerResult = 1, i;

	for (i = 0; i < y; i++) powerResult *= x;

	return powerResult%a;
}

int powerModulo2(int x, int y, int a)
{
	int powerResult = 1, square = x;
	if (y == 0)
		return 1;
	while (y != 0)
	{
		if (y % 2)
			powerResult = powerResult*square;
		square = (square*square) % a;
		y = y / 2;
		if (powerResult > a)
			powerResult = powerResult % a;
	}
	return powerResult;
}

main()
{
	unsigned int x, y, a;
	scanf_s("%ud", &x);
	scanf_s("%ud", &y);
	scanf_s("%ud", &a);

	if (a != 0)
		printf("%d", powerModulo2(x, y, a));

	else printf("Invalid!");

	_getch();
}