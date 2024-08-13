#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * allocate_buffer - Allocates 1024 bytes for a buffer.
 * @filename: The name of the file buffer is being allocated for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocate_buffer(char *filename)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't allocate buffer for %s\n", filename);
		exit(99);
	}

	return (buf);
}

/**
 * close_file_descriptor - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int status;

	status = close(fd);
	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If source_file does not exist or cannot be read - exit code 98.
 * If destination_file cannot be created or written to - exit code 99.
 * If source_file or destination_file cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, read_bytes, written_bytes;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
		exit(97);
	}

	buf = allocate_buffer(argv[2]);
	src_fd = open(argv[1], O_RDONLY);
	read_bytes = read(src_fd, buf, 1024);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		written_bytes = write(dest_fd, buf, read_bytes);
		if (dest_fd == -1 || written_bytes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		read_bytes = read(src_fd, buf, 1024);
		dest_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buf);
	close_file_descriptor(src_fd);
	close_file_descriptor(dest_fd);

	return (0);
}

