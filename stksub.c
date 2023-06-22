#include "monty.h"

/**
 * stack_sub - sub the top ele
 * @db: debut of linked list
 * @cl: num of ln;
 * Return: void func
 * amine mohamed
 */
void stack_sub(stack_t **db, unsigned int cl)
{
	int c = 0;
	stack_t *ourAux = NULL;

	ourAux = *db;

	for (; ourAux != NULL; ourAux = ourAux->next, c++)
		;

	if (c < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	ourAux = (*db)->next;
	ourAux->n -= (*db)->n;
	stack_pop(db, cl);
}
