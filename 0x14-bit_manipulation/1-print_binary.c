#include "main.h"
/**
 *print_binary - this function will print number as binary
 *@n: parameter integer
 */
void print_binary(unsigned long int n)
{
	unsigned long int ntest = (1ul << (sizeof(unsigned long int) * 8 - 1));

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	while ((n & ntest) == 0)
		ntest = (ntest >> 1);
	while ( ntest > 0)
	{
		if (ntest & n)
			_putchar('1');
		else
			_putchar('0');
		ntest = (ntest >> 1);
	}

}
