#include "hash_tables.h"
/**
 *key_index - this function will
 *@key: paramet string
 *@size: parameter integer
 *Return: this function will return an index value of
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key);

	return (index % size);
}
