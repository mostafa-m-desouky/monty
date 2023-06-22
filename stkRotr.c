#include "monty.h"

/**
 * stack_rotr - this func revese stck
 * @db: ls debut
 * @cl: num of line
 * Return: void func
 * amine mohamed
 */
void stack_rotr(stack_t **db, unsigned int cl)
{
	stack_t *ourAux = NULL;
	(void)cl;

	if (*db == NULL)
		return;

	if ((*db)->next == NULL)
		return;

	ourAux = *db;

	for (; ourAux->next != NULL; ourAux = ourAux->next)
		;

	ourAux->prev->next = NULL;
	ourAux->next = *db;
	ourAux->prev = NULL;
	(*db)->prev = ourAux;
	*db = ourAux;
}

