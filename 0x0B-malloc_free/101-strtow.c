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
 * get_word_length - helper function to get the length of a word
 * @str: the input string
 *
 * Return: the length of the word
 */
int get_word_length(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
		len++;

	return (len);
}

/**
 * allocate_words_array - helper function to allocate memory for the words array
 * @num_words: the number of words
 *
 * Return: a pointer to the allocated memory, or NULL if it fails
 */
char **allocate_words_array(int num_words)
{
	char **words;

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	return (words);
}

/**
 * free_words_array - helper function to free the memory of the words array
 * @words: the array of words
 * @num_words: the number of words to free
 */
void free_words_array(char **words, int num_words)
{
	for (int i = 0; i < num_words; i++)
		free(words[i]);
	free(words);
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

	words = allocate_words_array(num_words);
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;

		if (*str == '\0')
			break;

		word_len = get_word_length(str);

		word = malloc((word_len + 1) * sizeof(char));
		if (word == NULL)
		{
			free_words_array(words, i);
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
