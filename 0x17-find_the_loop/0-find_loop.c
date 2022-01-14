#include "lists.h"


listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortise, *hare;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}
	tortise = head;
	hare = head;
	while (hare->next && hare->next->next)
	{
		tortise = tortise->next;
		hare = hare->next->next;
		if (tortise == hare)
		{
			tortise = head;
			while (hare != NULL)
			{
				if (tortise == hare)
				{
					return (hare);
				}
				tortise = tortise->next;
				hare = hare->next;
			}
		}
	}
	return (NULL);
}
