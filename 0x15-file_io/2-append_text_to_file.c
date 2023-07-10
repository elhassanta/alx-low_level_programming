#include "main.h"
/**
 *append_text_to_file - this function append text to a file
 *@filename: pointer the string
 *@text_content: pointer to text
 *Return: this function return an anteger
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, i = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	while (*(text_content + i) != '\0')
	{
		if (write(fd, text + i, 1) == -1)
		{
			close(fd);
			return (-1);
		}
		i++;
	}
	close(fd);
	return (1);
}
