#include "monty.h"

/**
 * node_push - add ele to stack
 * @db: debut of linked ls
 * @cl: num of line
 * Return: void
 */
void node_push(stack_t **db, unsigned int cl)
{
	int num, f;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cl);
		dprintf(2, "usage: push integer\n");
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	for (f = 0; vglo.arg[f] != '\0'; f++)
	{
		if (!isdigit(vglo.arg[f]) && vglo.arg[f] != '-')
		{
			dprintf(2, "L%u: ", cl);
			dprintf(2, "usage: push integer\n");
			ovgloVide();
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(vglo.arg);

	if (vglo.ourLf == 1)
		NodeAdd(db, num);
	else
		addToEnd(db, num);
}

/**
 * stack_pall - print all value of ele in the stack
 * @db: the head
 * @cl: line number
 * Return: void
 */
void stack_pall(stack_t **db, unsigned int cl)
{
	stack_t *ourAux;
	(void)cl;

	ourAux = *db;

	while (ourAux)
	{
		printf("%d\n", ourAux->n);
		ourAux = ourAux->next;
	}
}

/**
 * stack_pint - function print the ele of stakc or queue
 * @db: the head
 * @cl: number of line
 * Return: void
 */
void stack_pint(stack_t **db, unsigned int cl)
{
	(void)cl;

	if (*db == NULL)
	{
		dprintf(2, "L%u: ", cl);
		dprintf(2, "can't pint, stack empty\n");
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*db)->n);
}

/**
 * stack_pop - to pop the ele in the top
 * @db: the head
 * @cl: number of line
 * Return: void
 */
void stack_pop(stack_t **db, unsigned int cl)
{
	stack_t *ourAux;

	if (db == NULL || *db == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}
	ourAux = *db;
	*db = (*db)->next;
	free(ourAux);
}

/**
 * stack_swap - function swap tow ele in top
 * @db: the head
 * @cl: line number
 * Return: void
 */
void stack_swap(stack_t **db, unsigned int cl)
{
	int vrm = 0;
	stack_t *ourAux = NULL;

	ourAux = *db;

	for (; ourAux != NULL; ourAux = ourAux->next, vrm++)
		;

	if (vrm < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cl);
		ovgloVide();
		exit(EXIT_FAILURE);
	}

	ourAux = *db;
	*db = (*db)->next;
	ourAux->next = (*db)->next;
	ourAux->prev = *db;
	(*db)->next = ourAux;
	(*db)->prev = NULL;
}
