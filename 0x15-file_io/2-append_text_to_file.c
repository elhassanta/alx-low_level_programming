#include "main.h"
/**
 *append_text_to_file - this function append text to a file
 *@filename: pointer the string
 *@text_content: pointer to text
 *Return: this function return an anteger
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, c_write, len;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	fd = open(filename, O_WRONLY | O_APPEND, 0664);
	c_write = write(fd, text_content, len);
	if (fd == -1 || c_write == -1)
		return (-1);
	close(fd);
	return (1);
}
