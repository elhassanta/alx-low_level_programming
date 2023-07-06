#include "main.h"
/**
 *print_binary - this function will print number as binary
 *@n: parameter integer
 */
void print_binary(unsigned int n)
{
	int i = 0, j = 0, k;
	char c[63];

	if (n == 0)
	{
		putchar('0');
		return;
	}
	while (n > 0)
	{
		k = (n & 1);
		if (k)
			c[i++] = '1';
		else
			c[i++] = '0';
		n = (n >> 1);
	}
	i--;
	while (i >= 0)
	{
		putchar(c[i]);
		i--;
	}
	while (c[j] != '\0')
		j++;
}
