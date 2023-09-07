#include "hash_tables.h"
/**
 *hash_djb2 - this function will implemante djb2 algorithm
 *@str: parameter string that the function take
 *Return: this function return an unsigned integer
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
