#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table
 * @ht: a pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node = NULL;

	if (ht)
	{
		if (ht->array)
		{
			while (ht->size  > 0)
			{
				node = ht->array[ht->size - 1];
				while (ht->array[ht->size - 1])
				{
					ht->array[ht->size - 1] = node->next;
					free(node->key);
					free(node->value);
					free(node);
					node = ht->array[ht->size - 1];
				}
				ht->size--;
			}
			free(ht->array);
			free(ht);
		}
	}
}
