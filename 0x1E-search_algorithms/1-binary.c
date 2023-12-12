#include "search_algos.h"
/**
 * binary_search - searches for a value in a sorted array of integers
 * using the binary search
 * @array: the array to search in
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: the index of the value if exists and -1 otherwise
 */

int binary_search(int *array, size_t size, int value)
{
	int start, end, i, mid;

	if (!array || size == 0)
		return (-1);
	start = 0;
	end = (int)size - 1;
	while (start <= end)
	{
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i != end)
				printf(" ,");
			else
				printf("\n");
		}
		mid = start + (end - start) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
		{
			end = mid - 1;
		}
		else if (array[end / 2] < value)
		{
			start = mid + 1;
		}
		else
			return (end / 2);
	}
	return (-1);
}
