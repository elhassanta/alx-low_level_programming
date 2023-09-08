#include "hash_tables.h"
/**
 *hash_table_delete - this function will delete a hash table
 *@ht: param pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int size = 0;
	hash_node_t *node;
	hash_node_t *next;

	if (ht == NULL)
		return;
	size = ht->size;
	while (size > 0)
	{
		if ((ht->array)[size])
		{
			node = (ht->array)[size];
			while (node)
			{
				next = node->next;
				free(node->key);
				free(node->value);
				node = next;
			}
		}
		size--;
	}
	free(ht->array);
	free(ht);
}
