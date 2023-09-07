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
	(void)value;

	if (ht == NULL || key == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	printf("%lu\n", index);/**
	arr = ((ht + index)->array);
	printf("%p\n", arr);
	*(*((ht + index)->array))->value = value;
	printf("%s\n", ((ht + index)->array)->key);*/
	return (1);

}
