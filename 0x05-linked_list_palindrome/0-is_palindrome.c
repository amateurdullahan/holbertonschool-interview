#include "lists.h"

/**
 * is_palindrome - check if linked list is palindrome
 * @head: list to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	int len;
	listint_t *p;

	if (head == NULL)
		return (1);

	p = *head;

	if (p == NULL)
		return (1);

	for (len = 0; p != NULL; len++)
		p = p->next;

	return (check(*head, len - 1));
}

/**
 * check - check if list is palindrome
 * @c: list to check
 * @x: start of list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check(listint_t *c, int x)
{
	int i;
	listint_t *j = c;

	for (i = 0; i < x; i++)
		 j = j->next;

	if (c->n != j->n)
		return (0);
	if (x <= 0)
		return (1);
	return (check(c->next, x - 2));
}
