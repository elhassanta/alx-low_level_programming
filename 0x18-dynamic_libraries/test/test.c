#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int printf(const char *format, ...)
{
	char str1[] = "9 8 10 24 75 - 9\nCongratulations, you win the jackpot!\n";

	write(1, str1, 56);
	/** becuse we change the behavior of printf and we make it print what we want
	 *now let's resolve the probleme that the funciton is used six times
	 *so we need to exit from progran in after the program calls printf once
	 *
	 * */
	exit(EXIT_SUCCESS);
}
