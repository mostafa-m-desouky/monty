#include "monty.h"

/**
 * stack_mul - mul tow ele in stack
 * @db: debut of ls
 * @cl: num of line;
 * Return: void func
 */
void stack_mul(stack_t **db, unsigned int cl)
{
	int k = 0;
	stack_t *ourAux = NULL;

	ourAux = *db;

	for (; ourAux != NULL; ourAux = ourAux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	ourAux = (*db)->next;
	ourAux->n *= (*db)->n;
	stack_pop(db, cl);
}
