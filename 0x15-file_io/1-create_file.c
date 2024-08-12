#include "main.h"

/**
 * create_file - Creates a file and writes text_content to it.
 * @filename: Pointer to the file name.
 * @text_content: Pointer to the content to write.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written;
	size_t content_length = 0;

	/* Validate filename */
	if (filename == NULL)
		return (-1);

	/* Calculate length of text_content if not NULL */
	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	/* Open file with read/write permissions and truncate it */
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC,
		S_IRUSR | S_IWUSR);
	if (file_descriptor < 0)
		return (-1);

	/* Write content to file */
	bytes_written = write(file_descriptor, text_content, content_length);

	/* Check for write errors */
	if (bytes_written < 0)
	{
		close(file_descriptor);
		return (-1);
	}

	/* Close the file */
	close(file_descriptor);

	return (1);
}

