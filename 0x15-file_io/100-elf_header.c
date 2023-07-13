#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
void print_osabi(Elf64_Ehdr ehdr);
void print_data(Elf64_Ehdr ehdr);
void print_abi_version(Elf64_Ehdr ehdr);
void print_type(Elf64_Ehdr ehdr);
void check_elf(unsigned char *e_ident);
const char *print_class(Elf64_Ehdr ehdr);
void print_magic(Elf64_Ehdr ehdr);
void print_version(Elf64_Ehdr ehdr);
void close_elf(int elf);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
/**
 *main - this function will print inf about ELF file header
 *@argc: param integer represent number arguments
 *@argv: name of the ELF file
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *ehdr;
int o, r;
const char *class_str;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
ehdr = malloc(sizeof(Elf64_Ehdr));
if (ehdr == NULL)
{
close_elf(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, ehdr, sizeof(Elf64_Ehdr));
check_elf((*ehdr).e_ident);
printf("ELF Header\n");
print_magic(*ehdr);

class_str = print_class(*ehdr);
printf(" Class: %s\n", class_str);

print_data(*ehdr);

print_version(*ehdr);

print_osabi(*ehdr);

print_abi_version(*ehdr);

print_type(*ehdr);

print_entry((*ehdr).e_entry, (*ehdr).e_ident);

if (r == -1)
{
free(ehdr);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
free(ehdr);
close_elf(o);
return (0);
}
/**
 * check_elf - Checks if the file is an elf file
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' &&
				e_ident[i] != 'L' &&
				e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 *print_magic - this function will print magic
 *@ehdr: parameter struct
 */
void print_magic(Elf64_Ehdr ehdr)
{
	int i;

	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ehdr.e_ident[i]);
	}
	printf("\n");
}
/**
 *print_class - this function will find elf file class
 *@ehdr: parameter struct
 *Return:return char pointer to class name
 */
const char *print_class(Elf64_Ehdr ehdr)
{
	unsigned char class;
	const char *class_str;

	class = ehdr.e_ident[EI_CLASS];
	switch (class)
	{
		case ELFCLASS32:
			class_str = "ELF32";
			break;
		case ELFCLASS64:
			class_str = "ELF64";
			break;
	}
	return (class_str);
}
/**
 *print_version - this function will print version
 *@ehdr: parameter struct
 */
void print_version(Elf64_Ehdr ehdr)
{
	unsigned char version;

	version = ehdr.e_ident[EI_VERSION];
	printf(" Version: %d\n", version);
}
#include "elf.h"

/**
 *print_data - this function will print data
 *@ehdr: parameter struct
 */
void print_data(Elf64_Ehdr ehdr)
{
unsigned char data_encoding;
const char *data_encoding_str = "Unknown";

data_encoding = ehdr.e_ident[EI_DATA];
data_encoding_str = "Unknown";
switch (data_encoding)
{
case ELFDATA2LSB:
data_encoding_str = "2's complement, little endian";
break;
case ELFDATA2MSB:
data_encoding_str = "2's complement, big endian";
break;
}
printf(" Data: %s\n", data_encoding_str);
}
/**
 *print_osabi - this function will print os abi
 *@ehdr: parameter struct
 */
void print_osabi(Elf64_Ehdr ehdr)
{
unsigned char osabi;
const char *osabi_str = "Unknown";
int x = 0;

osabi = ehdr.e_ident[EI_OSABI];
osabi_str = "Unknown";
switch (osabi)
{
case ELFOSABI_SYSV:
osabi_str = "UNIX - System V";
break;
case ELFOSABI_LINUX:
osabi_str = "LINUX";
break;
default:
x = 1;
osabi_str = "<unknown:";
}
if (x == 1)
{
printf(" OS/ABI: %s %d>\n", osabi_str, osabi);
}
else
printf(" OS/ABI: %s\n", osabi_str);
}
/**
*print_abi_version - this function will print abi version
*@ehdr: parameter struct
*/
void print_abi_version(Elf64_Ehdr ehdr)
{
unsigned char abi_version;

abi_version = ehdr.e_ident[EI_ABIVERSION];
printf(" ABI Version: %d\n", abi_version);
}
/**
 *print_type - this function will print type
 *@ehdr: parameter struct
 */
void print_type(Elf64_Ehdr ehdr)
{
int hexValue;
char *type = " Unknown";

hexValue = ehdr.e_type;
switch (hexValue)
{
case ET_NONE:
type = " NONE (No file Type)";
break;
case ET_REL:
type = " REL (Relocatable object file)";
break;
case ET_EXEC:
type = " EXEC (Executable file)";
break;
case ET_DYN:
type = " DYN (Shared object file)";
break;
case ET_CORE:
type = " CORE (Core file)";
break;
case ET_LOOS:
type = " LOOS (Start of the OS-specific range)";
break;
case ET_HIOS:
type = " HIOS (End of the OS-specific range)";
break;
case ET_LOPROC:
type = " LOPROC (Start of the processor-specific range)";
break;
case ET_HIPROC:
type = " HIPROC (End of the processor-specific range)";
break;
default:
type = " Unknown";
}
printf(" Type: %s\n", type);
}
/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO,
" Error: Can't close fd %d\n", elf);
exit(98);
}
}
/**
 *print_entry - this function will print entry point
 *@e_entry: param integer
 *@e_ident: param pointer
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf(" Entry point address: ");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}
if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);
else
printf("%#lx\n", e_entry);
}