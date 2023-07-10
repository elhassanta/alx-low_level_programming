#include "main.h"
/**
 *create_file - this function will creat a file
 *@filename: parameter pointer hold the filename
 *@text_content: this param hold the text
 *Return: this function return an integer
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytesWriten = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == -1)
	{
		return (-1);
	}
	while (*(text_content + bytesWriten) != '\0')
	{
		if (write(fd, text_content + bytesWriten, 1) == -1)
		{
			close(fd);
			return (-1);
		}
		bytesWriten++;
	}

	close(fd);
	return (1);
}
