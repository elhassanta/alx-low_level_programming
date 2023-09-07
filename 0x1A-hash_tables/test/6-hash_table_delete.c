#include "hash_tables.h"
/**
 *hash_table_delete - this function will delete a hash table
 *@ht: param pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int size = 0;

	if (ht == NULL)
		return;
	size = ht->size;
	while (size > 0)
	{
		if ((ht->array)[size])
			free((ht->array)[size]);
		size--;
	}
	free(ht->array);
	free(ht);
}
