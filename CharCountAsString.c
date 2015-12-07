#include<stdio.h>

char* PrintCount(char *input)
{
	int characters[256] = {0}, i, k=0;
	char output[20] = {'\0'};

	for (i = 0; input[i] != '\0'; i++)
	{
		characters[input[i]]++;
	}

	for (i = 0; i < 256; i++)
	{
		if (characters[i] > 0)
		{
			//printf("%c", i);
			//printf("%d", characters[i]);
			output[k++] = (char) i;
			output[k++] = characters[i] + '0';
		}
	}

	return output;
}

main()
{
	char input[10];
	gets_s(input, 11);

	printf("%s", PrintCount(input));

	_getch();
}