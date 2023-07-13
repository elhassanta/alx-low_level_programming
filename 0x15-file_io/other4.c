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
printf("Data: %s\n", data_encoding_str);
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
printf("OS/ABI: %s %d>\n", osabi_str, osabi);
}
else
printf("OS/ABI: %s\n", osabi_str);
}
/**
*print_abi_version - this function will print abi version
*@ehdr: parameter struct
*/
void print_abi_version(Elf64_Ehdr ehdr)
{
unsigned char abi_version;

abi_version = ehdr.e_ident[EI_ABIVERSION];
printf("ABI Version: %d\n", abi_version);
}
/**
 *print_type - this function will print type
 *@ehdr: parameter struct
 */
void print_type(Elf64_Ehdr ehdr)
{
int hexValue;
char *type = "Unknown";

hexValue = ehdr.e_type;
switch (hexValue)
{
case ET_NONE:
type = "NONE (No file Type)";
break;
case ET_REL:
type = "REL (Relocatable object file)";
break;
case ET_EXEC:
type = "EXEC (Executable file)";
break;
case ET_DYN:
type = "DYN (Shared object file)";
break;
case ET_CORE:
type = "CORE (Core file)";
break;
case ET_LOOS:
type = "LOOS (Start of the OS-specific range)";
break;
case ET_HIOS:
type = "HIOS (End of the OS-specific range)";
break;
case ET_LOPROC:
type = "LOPROC (Start of the processor-specific range)";
break;
case ET_HIPROC:
type = "HIPROC (End of the processor-specific range)";
break;
default:
type = "Unknown";
}
printf("Type: %s\n", type);
}
