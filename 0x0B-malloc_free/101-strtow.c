#include <stdlib.h>
#include <stddef.h>

/**
 * count_words - helper function to count the number of words in a string
 * @str: the input string
 *
 * Return: the number of words in the string
 */
int count_words(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (*str == ' ')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the input string
 *
 * Return: a pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words, *word;
	int i, j, k, word_len, num_words;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;

		if (*str == '\0')
			break;

		word_len = 0;
		while (str[word_len] && str[word_len] != ' ')
			word_len++;

		word = malloc((word_len + 1) * sizeof(char));
		if (word == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (k = 0; k < word_len; k++)
			word[k] = str[k];
		word[k] = '\0';

		words[i] = word;
		i++;
		str += word_len;
	}
	words[i] = NULL;
	return (words);
}
