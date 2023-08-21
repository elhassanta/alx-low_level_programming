#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int printf(const char *format, ...)
{
	char str[] = "Congratulation, you win jackpot!";
	char str1[] = "9 8 10 24 75 - 9\n";

	write(1, str1, sizeof(str1));
	write(1, str, sizeof(str));
	/** becuse we change the behavior of printf and we make it print what we want
	 *now let's resolve the probleme that the funciton is used six times
	 *so we need to exit from progran in after the program calls printf once
	 *
	 * */
	exit(EXIT_SUCCESS);
}
