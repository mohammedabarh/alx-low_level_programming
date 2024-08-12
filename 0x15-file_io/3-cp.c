#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(void);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates a buffer of 1024 bytes.
 *
 * Return: A pointer to the allocated buffer.
 */
char *allocate_buffer(void)
{
	char *buffer;

	buffer = malloc(1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Unable to allocate buffer\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_file_descriptor(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies content from one file to another.
 * @argc: The number of command line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 97 if the argument count is incorrect.
 * Exits with code 98 if the source file cannot be read.
 * Exits with code 99 if the destination file cannot be written to.
 * Exits with code 100 if file descriptors cannot be closed.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer();

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file_descriptor(from_fd);
		free(buffer);
		exit(99);
	}

	while ((bytes_read = read(from_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_file_descriptor(from_fd);
			close_file_descriptor(to_fd);
			free(buffer);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	}

	close_file_descriptor(from_fd);
	close_file_descriptor(to_fd);
	free(buffer);

	return (0);
}

