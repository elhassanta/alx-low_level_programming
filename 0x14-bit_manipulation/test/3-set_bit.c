#include "main.h"
/**
 *
 *
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int ntest = (1ul << index);
	if ( index > 63)
		return (-1);
	*n = ( *n | ntest);
	return (1);
}
