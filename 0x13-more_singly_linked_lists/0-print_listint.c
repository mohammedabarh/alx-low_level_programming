#include "lists.h"
#include <unistd.h> /* For _putchar */

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		_putchar(h->n + '0'); /* Convert integer to character */
		_putchar('\n');      /* Print newline */
		count++;             /* Increment the node counter */
		h = h->next;         /* Move to the next node */
	}

	return (count);
}

