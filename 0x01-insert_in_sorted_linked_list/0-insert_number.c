#include "lists.h"

/**
  * insert_node - insert node L)
  * @head: head of list
  * @number: number to insert
  *
  * Return: linked list
  */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *current;

	current = *head;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->n = number;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else if (current->n > number)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		while (current->next != NULL && current->next->n <= number)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	return (newNode);
}