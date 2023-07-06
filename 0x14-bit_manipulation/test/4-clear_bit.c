#include "main.h"
/**
 *clear_bit - this function set value of a bit to 0
 *@n: parameter pointer to an integer
 *@index: parameter integer
 *Return: this function return 1 on success and -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int ntest = (1ul << index);

	if (index > 63)
		return (-1);
	*n = (*n ^ ntest);
	return (1);
}
