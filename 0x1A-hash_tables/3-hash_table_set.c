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

	if (ht == NULL || key == NULL || ht->size == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	(ht->array)[index] = (hash_node_t *)malloc(sizeof(hash_node_t));
	if ((ht->array)[index] == NULL)
		return (0);
	(ht->array)[index]->key = (char *)key;
	(ht->array)[index]->value = (char *)value;
	(ht->array)[index]->next = NULL;
	return (1);

}
