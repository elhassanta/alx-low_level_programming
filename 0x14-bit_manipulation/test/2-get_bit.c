#include "main.h"
/**
 *
 *
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
