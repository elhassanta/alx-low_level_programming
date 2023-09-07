#include "hash_tables.h"
#include <string.h>
/**
 *hash_table_print - this function will print a hash table
 *@ht: parameter pointer to hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int size = 0, number_elements = 0, count = 0;

	while (size < ht->size)
	{
		if ((ht->array)[size])
		{
			number_elements++;
		}
		
		size++;
	}
	size = 0;
	printf("{");
	while (size < ht->size)
	{
		if ((ht->array)[size])
		{
			if (count == 0)
			{
				printf("'%s': '%s'", (ht->array)[size]->key, (ht->array)[size]->value);
			}
			else
			{
				printf(", '%s': '%s'", (ht->array)[size]->key, (ht->array)[size]->value);
			}
			count++;
		}
		size++;
	}
	printf("}\n");
}
