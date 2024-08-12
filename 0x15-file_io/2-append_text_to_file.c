#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Pointer to the file name.
 * @text_content: String to be appended to the file.
 *
 * Return: 1 on success, or -1 on failure or if filename is NULL.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written;
	size_t content_length = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Calculate the length of text_content if it's not NULL */
	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	/* Open the file for appending */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor < 0)
		return (-1);

	/* Write text_content to the file */
	bytes_written = write(file_descriptor, text_content, content_length);
	if (bytes_written < 0)
	{
		close(file_descriptor);
		return (-1);
	}

	/* Close the file descriptor */
	close(file_descriptor);

	return (1);
}

