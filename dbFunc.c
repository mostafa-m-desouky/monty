#include "monty.h"

/**
 *addToEnd - function to add node to the and of list
 *@debut: the position
 *@nber: linked list data
 *Return: db linked list
 */
stack_t *addToEnd(stack_t **debut, const int nber)
{
	stack_t *t_m_p, *fx;

	if (debut == NULL)
		return (NULL);
	t_m_p = malloc(sizeof(stack_t));
	if (!t_m_p)
	{
		dprintf(2, "Error: malloc failed\n");
		ovgloVide();
		exit(EXIT_FAILURE);
	}
	t_m_p->n = nber;
	if (*debut == NULL)
	{
		t_m_p->next = *debut;
		t_m_p->prev = NULL;
		*debut = t_m_p;
		return (*debut);
	}
	fx = *debut;
	while (fx->next)
		fx = fx->next;
	t_m_p->next = fx->next;
	t_m_p->prev = fx;
	fx->next = t_m_p;
	return (fx->next);
}

/**
 *NodeAdd - function to add node to the begining
 *@debut: position
 *@n: linkedl ist data
 *Return: db linked ls
 */
stack_t *NodeAdd(stack_t **debut, const int n)
{
	stack_t *t_m_p;

	if (debut == NULL)
		return (NULL);
	t_m_p = malloc(sizeof(stack_t));
	if (!t_m_p)
	{
		dprintf(2, "Error: malloc failed\n");
		ovgloVide();
		exit(EXIT_FAILURE);
	}
	t_m_p->n = n;
	if (*debut == NULL)
	{
		t_m_p->next = *debut;
		t_m_p->prev = NULL;
		*debut = t_m_p;
		return (*debut);
	}
	(*debut)->prev = t_m_p;
	t_m_p->next = (*debut);
	t_m_p->prev = NULL;
	*debut = t_m_p;
	return (*debut);
}

/**
 * linkedVide - this func free linked list
 * @debut: debut
 * Return: void
 */
void linkedVide(stack_t *debut)
{
	stack_t *t_m_p;

	while ((t_m_p = debut) != NULL)
	{
		debut = debut->next;
		free(t_m_p);
	}
}
