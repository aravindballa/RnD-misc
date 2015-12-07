#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

void getBaseNegative2(int n)
{
	int bases[8] = { 1, -2, 4, -8, 16, -32, 64 };
	int resBinary[8] = { 0 };
	int i = 0, result;

	while (bases[i] < n) i = i + 2;
	result = bases[i];
	resBinary[i] = 1;

	i--;

	while (1) {

		while (result > n)
		{
			if (n < result) result = result + bases[i];
			resBinary[i] = 1;
			i = i - 2;
		}

		i = 0;
		while (result < n)
		{
			if (n > result) result = result + bases[i];
			resBinary[i] = 1;
			i = i + 2;
		}

		if (n = result) break;
	}

	for (i = 7; i >= 0; i--){
		printf("%d", resBinary[i]);
	}
}

/* Function to convert decimal to binary.*/
char* decimal_binary(int n)
{
	int rem, j = 0;
	char binary[10] = { '0' };
	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		binary[j++] = rem + '0';
	}

	return binary;
}

//takes the string starting from (-2)^0
void getBaseMinus2(int n)
{
	char *input = decimal_binary(n);
	int i = 0, k, sizeofBinary = 0;

	while (input[i++] != '\0')
		sizeofBinary++;

	input[sizeofBinary] = '0'; input[sizeofBinary+1] = '0';

	for (i = 1; input[i] != '\0'; i = i + 2)
	{
		if (input[i] == '1')
		{
			input[i + 1] += 1;
			k = i + 1;
			while (input[k] == '2')
			{
				input[k] = '0';
				input[k + 1] += 1;
				k++;
			}
		}
	}
	
	//the final output will be the string printed in reverse
	printf("%s", input);
}

main()
{
	int n;
	//char base2[10];
	//gets(base2);
	scanf("%d", &n);
	//getBaseNegative2(n);

	getBaseMinus2(n);


	_getch();
}