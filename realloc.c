#include "shell.h"

command **_memcpy(command **dest, command **src, unsigned int n);

/**
 * _realloc - change the memory size of memory allocated
 * to a process
 * @ptr: a pointer to the previous memory block
 * @old_size: the original number of bytes allocated
 * @new_size: the new number of bytes to be allocated
 *
 * Return: a pointer to the longer string
 *	NULL if malloc fails or new_size = 0
 */
void *_realloc(command **ptr, unsigned int old_size, unsigned int new_size)
{
	command **s;

	if (ptr == NULL)
	{
		s = malloc(sizeof(command *) * new_size);
		return (s);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	s = malloc(sizeof(command *) * new_size);
	if (s)
	{
	return (_memcpy(s, ptr, old_size));
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}
/**
 * _memcpy - copies a memory area from one area of memory
 * to another
 * @src: the pointer to the source array
 * @dest: a pointer to the destination
 * @n: unassigned int for quantity of copy
 *
 * Return: pointer to the destination memory
 */
command **_memcpy(command **dest, command **src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	for (i = 0; src[i]; i++)
	{
		free(src[i]);
	}
	src = NULL;
	return (dest);
}

