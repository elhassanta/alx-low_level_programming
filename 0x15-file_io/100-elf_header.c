#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
/**
 *main - this function will print inf about ELF file header
 *@argc: param integer represent number arguments
 *@argv: name of the ELF file
 */

void main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;
	ssize_t bytes_read;
	unsigned char class;
	const char *class_str = "Unknown";

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file\n");
		exit(98);
	}
	bytes_read = read(fd, &ehdr, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		perror("Failed to read file\n");
		exit(98);
	}
	printf("ELF Header\n");
	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ehdr.e_ident[i]);
	}
	printf("\n");

	class = ehdr.e_ident[EI_CLASS];
	switch (class)
	{
		case ELFCLASS32:
			class_str = "32-bit";
			break;
		case ELFCLASS64:
			class_str = "64-bit";
			break;
	}
	printf("Class: %s\n", class_str);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: error occured while closing the file with fd %d\n", fd);
		exit(98);
	}
}
