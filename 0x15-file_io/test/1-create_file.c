#include "main.h"
/**
 *create_file - this function will creat a file
 *@filename: parameter pointer hold the filename
 *@text_content: this param hold the text
 *Return: this function return an integer
 */
int create_file(const char *filename, char *text_content)
{
	int fd, c_write, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len] != '\0'; len++)
			;
	}
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	c_write = write(fd, text_content, len);
	if (fd == -1 || c_write == -1)
		return (-1);
	close(fd);
	return (1);
}
