#include "main.h"
/**
 *read_textfile - reads a text file and prints it to the standard output
 *@filename: parameter pointer
 *@letters: parameter number of letters
 *Return: return a ssize_t parameter
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);
free(buf);
close(fd);
return (w);
}

