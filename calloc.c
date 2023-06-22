#include "monty.h"
/**
 * calloc_copy - copy of calloc finction
 * @nb: num of ele
 * @sz: type of ele
 * Return: void
 */
void *calloc_copy(unsigned int nb, unsigned int sz)
{
	void *our_p = NULL;
	unsigned int j;

	if (nb == 0 || sz == 0)
	{
		return (NULL);
	}
	our_p = malloc(nb * sz);
	if (our_p == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < (nb * sz); j++)
	{
		*((char *)(our_p) + j) = 0;
	}
	return (our_p);
}
