#include <stdlib.h>
#include "binary_trees.h"

/**
  * heap_insert - inserts value into heap :)
  * @root: root
  * @value: value
  *
  * Return: new node
  */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (root == NULL)
		return (NULL);
	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	if (*root == NULL)
	{
		*root = new_node;
	}
	return (new_node);
}
