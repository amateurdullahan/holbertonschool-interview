#include "search.h"

/**
  * linear_skip - search thru skip list
  * @list: list to search
  * @value: value searching for
  *
  * Return: pointer to node or null
  */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tor = list;
	skiplist_t *har = list;
	int last;

	if (list == NULL)
		return (NULL);
	har = har->express;
	while (har && har->n < value)
	{
		if (har == NULL)
			break;
		printf("Value checked at index [%d] = [%d]\n", (int)har->index, har->n);
		tor = har;
	    har = har->express;
	}
	if (har != NULL)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)har->index, har->n);
		last = (int)har->index;
	}
	else
	{
		har = tor;
		while (har->next != NULL)
			har = har->next;
		last = (int)har->index;
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)tor->index, last);
	har = tor->express;
	while (tor != NULL && tor != har)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)tor->index, tor->n);
		if (tor->n == value)
			return (tor);
		tor = tor->next;
	}
	return (NULL);
}
