#include <stdio.h>

/* Function prototype */
static void print_message(void) __attribute__ ((constructor));

/**
 * print_message - Prints a sentence before the main function executes
 */
static void print_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

