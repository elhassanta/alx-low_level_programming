#include "main.h"
/**
 *read_textfile - reads a text file and prints it to the standard output
 *@filename: parameter pointer
 *@letters: parameter number of letters
 *Return: return a ssize_t parameter
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
ssize_t fd;
ssize_t c_write;
ssize_t c_read;

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buffer = malloc(sizeof(char) * letters);
c_read = read(fd, buffer, letters);
c_write = write(STDOUT_FILENO, buffer, c_read);
free(buffer);
close(fd);
return (c_write);
}

