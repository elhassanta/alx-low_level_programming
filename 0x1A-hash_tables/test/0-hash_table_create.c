#include "hash_tables.h"
/**
 *hash_table_create - this function will creat a hash table
 *@size: param represent size of hash table
 *Return: return pointer to created table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;
	unsigned long int len = 0;

	table = (hash_table_t *)malloc(sizeof(hash_table_t) * size);
	if (table != NULL)
	{
		while(len < size)
		{
			(table + len)->size = size;
			(table + len)->array = NULL;
			len++;
		}
	}
	return (table);
}
