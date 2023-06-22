#include "monty.h"

/**
 * stack_rotl - return the fr to bottom
 * @db: ls debut
 * @cl: num of line
 * Return: void func
 * amine mohamed
 */
void stack_rotl(stack_t **db, unsigned int cl)
{
	stack_t *ourAx1 = NULL;
	stack_t *ourAx2 = NULL;
	(void)cl;

	if (*db == NULL)
		return;

	if ((*db)->next == NULL)
		return;

	ourAx1 = (*db)->next;
	ourAx2 = *db;

	for (; ourAx2->next != NULL; ourAx2 = ourAx2->next)
		;

	ourAx1->prev = NULL;
	ourAx2->next = *db;
	(*db)->next = NULL;
	(*db)->prev = ourAx2;
	*db = ourAx1;
}
