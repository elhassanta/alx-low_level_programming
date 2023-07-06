#include "main.h"
/**
 *set_bit - this function set bit at index to 1
 *@n: parameter pointer to integer
 *@index: parameter integer
 *Return: this function return 1 for success and -1 in failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int ntest = (1ul << index);

	if (index > 63)
		return (-1);
	*n = (*n | ntest);
	return (1);
}
