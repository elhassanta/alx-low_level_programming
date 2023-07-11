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
	int fd, i;
	Elf64_Ehdr ehdr;
	ssize_t bytes_read;
	unsigned char class;
	const char *class_str = "Unknown";
	unsigned char version;
	unsigned char data_encoding;
	const char *data_encoding_str = "Unknown";
	unsigned char osabi;
	const char *osabi_str = "Unknown";
	unsigned char abi_version;
	int hexValue;

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
	for (i = 0; i < EI_NIDENT; i++)
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

	version = ehdr.e_ident[EI_VERSION];
	printf("Version: %d\n", version);

	data_encoding = ehdr.e_ident[EI_DATA];
	data_encoding_str = "Unknown";
	switch (data_encoding)
	{
		case ELFDATA2LSB:
			data_encoding_str = "Little Endian";
			break;
		case ELFDATA2MSB:
			data_encoding_str = "Big Endian";
			break;
	}
	printf("Data: %s\n", data_encoding_str);

	osabi = ehdr.e_ident[EI_OSABI];
	osabi_str = "Unknown";
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			osabi_str = "UNIX - System V";
			break;
		case ELFOSABI_LINUX:
			osabi_str = "Linux";
			break;
	}
	printf("OS/ABI: %s\n", osabi_str);

	abi_version = ehdr.e_ident[EI_ABIVERSION];
	printf("ABI Version: %d\n", abi_version);

	hexValue = ehdr.e_type;
	switch (hexValue)
	{
		case ET_NONE:
			type = "No file Type";
			break;
		case ET_REL:
			type = "Relocatable object file";
			break;
		case ET_EXEC:
			type = "Executable file";
			break;
		case ET_DYN: 
			type = "Shared object file";
		case ET_CORE:
			type = "Core file";
			break;
		case ET_LOOS:
			type = "Start of the OS-specific range";
			break;
		case ET_HIOS:
			type = "End of the OS-specific range";
			break;
		case ET_LOPROC:
			type = "Start of the processor-specific range";
			break;
		case ET_HIPROC:
			type = "End of the processor-specific range";
			break;
	}
	printf("Type: 0x%x\n", ehdr.e_type);

	
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: error occured while closing the file with fd %d\n", fd);
		exit(98);
	}
}
