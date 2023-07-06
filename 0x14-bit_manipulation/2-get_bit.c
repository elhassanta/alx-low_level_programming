#include "main.h"
/**
 *
 *
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	unsigned long int ntest = (1ul << index);

	return (ntest & n);
}
