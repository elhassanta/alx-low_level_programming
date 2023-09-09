#include "hash_tables.h"
/**
 *hash_table_get - this function will retrieve a value associated with a key
 *@ht: parameter pointer point to a constant string
 *@key: parameter pointer to a constant hash table
 *Return: this function return pointer to hash table
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	char *value = NULL;
	hash_node_t *node;

	if (key == NULL || ht == NULL || ht->array == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	if ((ht->array)[index] != NULL)
	{
		if (!strcmp((ht->array)[index]->key, key))
		{
			value = (ht->array)[index]->value;
		}
		else if ((ht->array)[index]->next != NULL)
		{
			node = node->next;
			while (node)
			{
				if (strcmp(node->key, key))
					return (node->value);
				node = node->next;
			}
		}
	}
	else
		hash_table_set((hash_table_t *)ht, key, NULL);
	return (value);
}
