#include "lists.h"

/**
 * check_cycle - finds a loop in list
 * @list: list to be checked
 *
 * Return: 1 if true, else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *p = list, *p2 = list;

	if (list == NULL)
		return (0);

	p2 = p2->next;

	while (p2 != NULL)
	{
		if (p == p2)
			return (1);

		p = p->next;
		p2 = p2->next;
		if (p2 != NULL)
			p2 = p2->next;
	}

	return (0);
}
