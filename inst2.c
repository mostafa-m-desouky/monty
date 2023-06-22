#include "monty.h"

/**
 * stack_add - adds the top two elements of the stack.
 * @db: head of the linked list
 * @cl: line number;
 * Return: void
 * amine mohamed
 */
void stack_add(stack_t **db, unsigned int cl)
{
	int m = 0;
	stack_t *ourAux = NULL;

	ourAux = *db;

	for (; ourAux != NULL; ourAux = ourAux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	ourAux = (*db)->next;
	ourAux->n += (*db)->n;
	stack_pop(db, cl);
}

/**
 *stack_nop - doesn't do anythinhg
 *
 * @db: head of the linked list
 * @cl: line number;
 * Return: no return
 */
void stack_nop(stack_t **db, unsigned int cl)
{
	(void)db;
	(void)cl;
}

