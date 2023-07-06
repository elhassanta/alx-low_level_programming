#include "main.h"
/**
 *flip_bits - this function will flip bits of two integers
 *@n: parameter integer
 *@m: parameter integer
 *Return: this function return an unsigned integer
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int p = (n ^ m), i = 0;

	while (p > 0)
	{
		if (p & 1)
			i++;
		p = (p >> 1);
	}
	return (i);
}
