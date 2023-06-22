#include "monty.h"

/**
 * realloc_copy - copy o realloc funct
 * @pr: ptr for malloc func
 * @odSz: old size
 * @nwSz: new size
 * Return: void
 */
void *realloc_copy(void *pr, unsigned int odSz, unsigned int nwSz)
{
	char *p = NULL;
	unsigned int i;

	if (nwSz == odSz)
		return (pr);
	if (pr == NULL)
	{
		p = malloc(nwSz);
		if (!p)
			return (NULL);
		return (p);
	}
	if (nwSz == 0 && pr != NULL)
	{
		free(pr);
		return (NULL);
	}
	if (nwSz > odSz)
	{
		p = malloc(nwSz);
		if (!p)
			return (NULL);
		for (i = 0; i < odSz; i++)
			p[i] = *((char *)pr + i);
		free(pr);
	}
	else
	{
		p = malloc(nwSz);
		if (!p)
			return (NULL);
		for (i = 0; i < nwSz; i++)
			p[i] = *((char *)pr + i);
		free(pr);
	}
	return (p);
}
