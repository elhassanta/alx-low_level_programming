#ifndef ELF_H
#define ELF_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
void print_osabi(Elf64_Ehdr ehdr);
void print_data(Elf64_Ehdr ehdr);
void print_abi_version(Elf64_Ehdr ehdr);
void print_type(Elf64_Ehdr ehdr);
#endif /* ELF_H */
