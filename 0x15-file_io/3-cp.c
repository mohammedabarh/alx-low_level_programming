#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *allocate_buffer(size_t size);
void handle_close(int fd);

/**
 * allocate_buffer - Allocates a buffer of specified size.
 * @size: Size of the buffer to be allocated.
 *
 * Return: A pointer to the allocated buffer.
 */
char *allocate_buffer(size_t size)
{
	char *buffer;

	buffer = malloc(size);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(99);
	}

	return (buffer);
}

/**
 * handle_close - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to be closed.
 */
void handle_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies content from one file to another.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 97 for incorrect argument count,
 * 98 for file read errors, 99 for file write errors, and 100
 * for file close errors.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(1024);

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		handle_close(src_fd);
		exit(99);
	}

	while ((bytes_read = read(src_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			handle_close(src_fd);
			handle_close(dest_fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	}

	free(buffer);
	handle_close(src_fd);
	handle_close(dest_fd);

	return (0);
}

