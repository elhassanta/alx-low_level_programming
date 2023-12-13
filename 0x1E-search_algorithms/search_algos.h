#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_
#include <stdio.h>
#include <stdlib.h>
int linear_search(int *array, size_t, int);
int binary_search(int *array, size_t, int);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);

#endif /* _SEARCH_ALGOS_H */
