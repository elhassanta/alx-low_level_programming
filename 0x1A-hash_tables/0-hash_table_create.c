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

	table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (table)
	{
		table->size = size;
		while (len < size)
		{
			(table->array)[len] = (hash_node_t *)malloc(sizeof(hash_node_t *));
			if ((table->array)[len] == NULL)
			{
				while (len > 0)
				{
					free((table->array)[len]);
					len--;
				}
			}
			len++;
		}
	}
	return (table);
}
