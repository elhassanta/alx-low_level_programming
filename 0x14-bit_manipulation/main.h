#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
unsigned int binary_to_uint(char const *b);
void print_binary(unsigned long int n);
int _putchar(char c);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
#endif /* MAIN_H */
