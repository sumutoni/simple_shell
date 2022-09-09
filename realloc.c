#include "shell.h"

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
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void **s;

	if (ptr == NULL)
	{
		s = _calloc(sizeof(char), new_size);
		return (s);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	s = _calloc(sizeof(ptr), new_size);
	if (s)
	{
	return (memcpy(s, ptr, old_size));
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

/**
 * _calloc - allocate a contiguous block of memory to
 * an array
 * @nmemb: the number of elements of the array
 * @size: the size of each element
 *
 * Return: void pointer to new array
 */
void *_calloc(unsigned int size, unsigned int nmemb)
{
	void *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	return (memset(p, 0, nmemb * size));
}
