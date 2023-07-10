#include "main.h"
/**
 *read_textfile - reads a text file and prints it to the standard output
 *@filename: parameter pointer
 *@letters: parameter number of letters
 *Return: return a ssize_t parameter
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, byte;
	char buffer[1024];
	ssize_t i = 0, bytesRead, lim = letters;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	bytesRead = read(fd, buffer, letters);
	if (bytesRead < 0)
	{
		close(fd);
		return (0);
	}
	while (i <= lim && i <= bytesRead && (*(buffer + i) != EOF))
	{
		byte = write(STDOUT_FILENO, buffer + i, 1);
		if (byte == -1)
		{
			close(fd);
		}
		i++;
	}
	if (close(fd) == -1)
	{
		return (0);
	}
	return (i);
}

