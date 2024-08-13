#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - Prints an error message to stderr and exits with a status code
 * @msg: The error message to print
 * @exit_code: The exit status code
 */
void print_error(const char *msg, int exit_code)
{
	fprintf(stderr, "%s\n", msg);
	exit(exit_code);
}

/**
 * print_elf_header - Prints the ELF header information
 * @ehdr: Pointer to the ELF header structure
 */
void print_elf_header(const Elf64_Ehdr *ehdr)
{
	printf("ELF Header:\n");

	printf("  Magic:   %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x "
		   "%.2x %.2x %.2x %.2x\n",
		ehdr->e_ident[0], ehdr->e_ident[1], ehdr->e_ident[2], ehdr->e_ident[3],
		ehdr->e_ident[4], ehdr->e_ident[5], ehdr->e_ident[6], ehdr->e_ident[7],
		ehdr->e_ident[8], ehdr->e_ident[9], ehdr->e_ident[10], ehdr->e_ident[11],
		ehdr->e_ident[12], ehdr->e_ident[13], ehdr->e_ident[14], ehdr->e_ident[15]);

	printf("  Class:                             %s\n",
		ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");

	printf("  Data:                              %s\n",
		ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? 
		"2's complement, little endian" : 
		"2's complement, big endian");

	printf("  Version:                           %d (current)\n",
		ehdr->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
		ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? 
		"UNIX - System V" : 
		"Unknown");

	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n",
		ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" : "Unknown");

	printf("  Entry point address:               0x%lx\n", ehdr->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename", 98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_error("Error opening file", 98);
	}

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		close(fd);
		print_error("Error reading file", 98);
	}
	close(fd);

	if (ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' ||
		ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F')
	{
		print_error("Not an ELF file", 98);
	}

	print_elf_header(&ehdr);
	return (0);
}

