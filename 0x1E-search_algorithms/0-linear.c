#include "search_algos.h"
/**
 * linear_search - is a function that search for a value in an array
 * @array: the array to search in
 * @size: the size of the array
 * @value: the value to search
 *
 * Return: the value the index of the value if exist and -1 if not exist
 */

int linear_search(int *array, size_t size, int value)
{
	int i;

	if (!array || size == 0)
		return (-1);
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
