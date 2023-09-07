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
	unsigned long int index = key_index(key);

	if (ht == NULL || (*ht) == NULL)
		return (1);
	if (ht->size < index)
		return (1);
	return (0);

}
