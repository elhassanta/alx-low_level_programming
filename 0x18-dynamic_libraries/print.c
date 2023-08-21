#include <stdio.h>
#include <stdlib.h>

int printf(const char *format, ...)
{
	char str[] = "Congratulation, you win jackpot!";

	write(1, str, sizeof(str));
	return (0);
}
