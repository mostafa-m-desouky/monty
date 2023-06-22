#include "monty.h"

/**
 * stack_div - div the second ele by the first
 * @db: debut of list
 * @cl: num of line;
 * Return: void func
 * amine mohamed
 */
void stack_div(stack_t **db, unsigned int cl)
{
	int h = 0;
	stack_t *ourAux = NULL;

	ourAux = *db;

	for (; ourAux != NULL; ourAux = ourAux->next, h++)
		;

	if (h < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	if ((*db)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	ourAux = (*db)->next;
	ourAux->n /= (*db)->n;
	stack_pop(db, cl);
}
