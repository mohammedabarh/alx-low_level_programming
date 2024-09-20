#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * generate_key - Generates a key based on the username
 * @username: The username to generate the key for
 * @key: The buffer to store the generated key
 */
void generate_key(const char *username, char *key)
{
    size_t i, len;
    int ch;
    long sum;

    // Initialize key generation
    key[0] = 'O';
    key[1] = 'G';
    key[2] = username[0];
    key[3] = 'H';
    key[4] = '0';
    key[5] = '4';

    // Calculate sum of ASCII values in username
    len = strlen(username);
    sum = 0;
    for (i = 0; i < len; i++)
        sum += username[i];

    // Set the 6th character based on sum
    key[6] = ((sum ^ 79) & 63) + 64;

    // Generate the rest of the key
    ch = 1;
    for (i = 0; i < len; i++)
        ch *= username[i];
    key[7] = ((ch ^ 85) & 63) + 64;

    ch = username[0];
    for (i = 0; i < len; i++)
        if (username[i] > ch)
            ch = username[i];
    key[8] = ((ch ^ 14) & 63) + 64;

    for (i = 0; i < len; i++)
        if (username[i] <= ch && username[i] > key[8])
            key[8] = username[i];
    key[8] = ((key[8] ^ 34) & 63) + 64;

    // Finalize key
    key[9] = '\0';
}

/**
 * main - Entry point, generates a key for crackme5
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    char key[10];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return (1);
    }

    generate_key(argv[1], key);
    printf("%s\n", key);

    return (0);
}
