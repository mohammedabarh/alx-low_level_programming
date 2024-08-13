#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verify_elf(unsigned char *e_ident);
void display_magic(unsigned char *e_ident);
void display_class(unsigned char *e_ident);
void display_data(unsigned char *e_ident);
void display_version(unsigned char *e_ident);
void display_osabi(unsigned char *e_ident);
void display_abi(unsigned char *e_ident);
void display_type(unsigned int e_type, unsigned char *e_ident);
void display_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_file(int fd);

/**
 * verify_elf - Verifies if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Exits with code 98 if the file is not an ELF file.
 */
void verify_elf(unsigned char *e_ident)
{
    if (e_ident[0] != 127 || e_ident[1] != 'E' ||
        e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}

/**
 * display_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void display_magic(unsigned char *e_ident)
{
    int i;

    printf(" Magic: ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", e_ident[i]);
        if (i < EI_NIDENT - 1)
            printf(" ");
        else
            printf("\n");
    }
}

/**
 * display_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_class(unsigned char *e_ident)
{
    printf(" Class: ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
        break;
    }
}

/**
 * display_data - Prints the data encoding of an ELF header.
 * @e_ident: A pointer to an array containing the ELF data encoding.
 */
void display_data(unsigned char *e_ident)
{
    printf(" Data: ");

    switch (e_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
        break;
    }
}

/**
 * display_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void display_version(unsigned char *e_ident)
{
    printf(" Version: %d", e_ident[EI_VERSION]);

    if (e_ident[EI_VERSION] == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}

/**
 * display_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF OS/ABI.
 */
void display_osabi(unsigned char *e_ident)
{
    printf(" OS/ABI: ");

    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
        break;
    }
}

/**
 * display_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void display_abi(unsigned char *e_ident)
{
    printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * display_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf(" Type: ");

    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
        break;
    }
}

/**
 * display_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_entry(unsigned long int e_entry, unsigned char *e_ident)
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

/**
 * close_file - Closes an ELF file descriptor.
 * @fd: The file descriptor of the ELF file.
 */
void close_file(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(98);
    }
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 98 if the file is not an ELF file
 * or if there are issues reading the file.
 */
int main(int argc, char *argv[])
{
    Elf64_Ehdr *header;
    int fd, read_bytes;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        close_file(fd);
        dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
        exit(98);
    }

    read_bytes = read(fd, header, sizeof(Elf64_Ehdr));
    if (read_bytes == -1)
    {
        free(header);
        close_file(fd);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    verify_elf(header->e_ident);
    printf("ELF Header:\n");
    display_magic(header->e_ident);
    display_class(header->e_ident);
    display_data(header->e_ident);
    display_version(header->e_ident);
    display_osabi(header->e_ident);
    display_abi(header->e_ident);
    display_type(header->e_type, header->e_ident);
    display_entry(header->e_entry, header->e_ident);

    free(header);
    close_file(fd);
    return (0);
}

