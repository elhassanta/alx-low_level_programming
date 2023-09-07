#include "hash_tables.h"
/**
 *hash_table_create - this function will creat a hash table
 *@size: param represent size of hash table
 *Return: return pointer to created table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;

	table = (hash_table_t *)malloc(sizeof(hash_table_t) * size);
	return (table);
}
