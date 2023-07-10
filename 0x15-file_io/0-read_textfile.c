#include "main.h"
/**
 *read_textfile - function that reads a text file and prints it to the POSIX standard output
 *@filename
 *@letters
 *Return: return a ssize_t parameter
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buffer[letters];
	ssize_t bytesRead, bytesWritten;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	bytesRead = read(fd, buffer, sizeof(buffer));
	if (bytesRead == -1)
	{
		close(fd);
		return (0);
	}
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten == -1)
	{
		close(fd);
		return (0);
	}
	if (close(fd) == -1)
	{
		return (0);
	}
	return (bytesWritten);
}

