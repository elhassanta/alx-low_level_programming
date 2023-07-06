#include <stdio.h>
/**
 *binary_to_uint - this function will convert a binary number to a number
 *@b: take a character string
 *@Return: return an int number
 */
unsigned int binary_to_uint(char const *b)
{
	int i, j, m;
	unsigned int p, number;
	char const *bin;
	if (b == NULL)
		return (0);

	i = 0;
	j = 0;
	p = 1;
	bin = b;
	number = 0;
	while (*bin != '\0')
	{
		i++;
		bin++;
	}
	i--;
	while (i >= 0)
	{
		if (b[i] > '1' || b[i] < '0')
			return (0);
		if (j == 0)
		{
			p = 1 * (b[i] - '0');
		}
		else
		{
			p = 1;
			for (m = 1; m <= j; m++)
				p = p * 2;
			p = (b[i] - '0') * p;
		}
		number = number + p;
		i--;
		j++;
	}
	return (number);
}
