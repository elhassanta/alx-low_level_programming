#include "hash_tables.h"
/**
 *hash_table_set - this function will add key-value to hash table
 *@ht: param pointer to hash_table
 *@key: param key to use as index
 *@value: param hold value to store
 *Return: this function return 0 for success and 1 in failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node = NULL;
	hash_node_t *tmp = NULL;

	if (ht == NULL || key == NULL || ht->size == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	if (!(ht->array)[index])
	{
		(ht->array)[index] = (hash_node_t *)malloc(sizeof(hash_node_t));
		if ((ht->array)[index] == NULL)
			return (0);
		(ht->array)[index]->key = (char *)strdup(key);
		(ht->array)[index]->value = (char *)strdup(value);
		(ht->array)[index]->next = NULL;
	}
	else
	{
		node = (ht->array)[index];
		while (node->next)
		{
			if (!strcmp(node->key, key))
			{
				free(node->value);
				node->value = strdup(value);
				return (1)
			}
			node = node->next;
		}
		if (!strcmp(node->key, key))
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		tmp = (hash_node_t *)malloc(sizeof(hash_node_t));
		tmp->key = (char *)strdup(key);
		tmp->value = (char *)strdup(value);
		tmp->next = NULL;
		node->next = tmp;
	}
	return (1);

}
