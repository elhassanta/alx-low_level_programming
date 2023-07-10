#include "main.h"
/**
 *main - this function copy a file in another file
 *@argc: param integer
 *@argv: pointer to strings
 *Return: this function return an integer
 */

int main(int argc, char *argv[])
{
	int fd1, fd2, text1;
	char buffer[127000];

	if (argc < 3)
		return (-1);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		return (-1);
	text1 = read(argv[1], buffer, 127000);
	if (text1 == -1)
	{
		close(fd1);
		return (-1);
	}
	close(fd1);
	fd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);
	if (fd2 == -1)
		return (-1);
	while (*(buffer + i) != '\0')
	{
		if (write(fd2, buffer + i, 1) == -1)
		{
			close(fd2);
			return (-1);
		}
		i++;
	}
	close(fd2);
	return (1);

}
