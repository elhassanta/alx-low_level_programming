#include "main.h"
/**
 *get_bit - this function return the value of bit at index
 *@n: parameter integer
 *@index: parameter integer
 *Return: return 0 or 1 or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int ntest = (1ul << index);

	if (index > 63)
		return (-1);
	if (ntest & n)
		return (1);
	else
		return (0);
}
