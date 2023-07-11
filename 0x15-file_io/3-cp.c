#include "main.h"
/**
 *main - this function copy a file in another file
 *@argc: param integer
 *@argv: pointer to strings
 *Return: this function return an integer
 */

int main(int argc, char *argv[])
{
	int fd1, fd2, text1, i;
	char buffer[127000];

	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", argv[1]);
		exit(98);
	}
	text1 = read(fd1, buffer, 127000);
	if (text1 == -1)
	{
		close(fd1);
		dprintf(STDERR_FILENO, "Error: Can't read %s\n", argv[1]);
		exit(98);
	}
	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", argv[2]);
		exit(99);
	}
	while (*(buffer + i) != '\0')
	{
		if (write(fd2, buffer + i, 1) == -1)
		{
			close(fd2);
			dprintf(STDERR_FILENO, "Error: Can't write %s\n", argv[2]);
			exit(100);
		}
		i++;
	}
	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}
	return (1);

}
