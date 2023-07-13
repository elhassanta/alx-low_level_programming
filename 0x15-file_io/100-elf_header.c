#include "elf.h"
void check_elf(unsigned char *e_ident);
const char *print_class(Elf64_Ehdr ehdr);
void print_magic(Elf64_Ehdr ehdr);
void print_version(Elf64_Ehdr ehdr);

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
close(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, ehdr, sizeof(Elf64_Ehdr));
check_elf((*ehdr).e_ident);
printf("ELF Header\n");
print_magic(*ehdr);

class_str = print_class(*ehdr);
printf("Class: %s\n", class_str);

print_data(*ehdr);

print_version(*ehdr);

print_osabi(*ehdr);

print_abi_version(*ehdr);

print_type(*ehdr);
if (r == -1)
{
free(ehdr);
close(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
free(ehdr);
close(o);
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

	printf("Magic: ");
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
	printf("Version: %d\n", version);
}
