#include "hash_tables.h"
/**
 *hash_table_print - this function will print a hash table
 *@ht: parameter pointer to hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int size = 0, count = 0;
	hash_node_t *node;
	if(ht == NULL)
		return (NULL);

	printf("{");
	while (size < ht->size)
	{
		if ((ht->array)[size])
		{
			if (count == 0)
			{
				printf("'%s': '%s'", (ht->array)[size]->key, (ht->array)[size]->value);
				count++;
			}
			else
			{
				printf(", '%s': '%s'", (ht->array)[size]->key, (ht->array)[size]->value);
			}
			node = (ht->array)[size]->next;
			if (node)
			{
				while (node)
				{
					printf(", '%s': '%s'", node->key, node->value);
					node = node->next;
				}

			}
		}
		size++;
	}
	printf("}\n");
}
