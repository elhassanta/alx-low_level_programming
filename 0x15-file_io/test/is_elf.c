/**
 *is_elf_file - this function check if a file is ELF file
 *@filename: param pointer to file name
 *Return: this function return 1 true or -1 false
 */
int is_elf_file(const char *filename)
{
	int fd;
	unsigned char ident[4];
	ssize_t bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return (-1);
	}
	bytes_read = read(fd, ident, sizeof(ident));
	if (bytes_read != sizeof(ident))
	{
		perror("Failed to read file");
		close(fd);
		return (-1);
	}
	close(fd);
	if (ident[0] == 0x7F && ident[1] == 'E' && ident[2] == 'L' && ident[3] == 'F') {
		return (1);
	}
	return (-1);
}

