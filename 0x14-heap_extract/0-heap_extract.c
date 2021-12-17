#include "binary_trees.h"

/**
  * heap_extract - extract root node of max binary heap
  * @root: double pointer root node of heap
  *
  * Return: value in node or 0 on failure
  */

int heap_extract(heap_t **root)
{
	int value, height;
	heap_t *top;

	if (root == NULL || (*root) == NULL)
	{
		return (0);
	}
	top = *root;
	value = top->n;

	if (top->left == NULL && top->right == NULL)
	{
		*root = NULL;
	}
	else
	{
		height = find_height(*root, 1);
		top = get_top(*root, height, 1);
		(*root)->n = top->n;
		if (top->parent->right == top)
		{
			top->parent->right = NULL;
		}
		else
		{
			top->parent->left = NULL;
		}
		heapify(*root);
	}
	free(top);

	return (value);
}

/**
  * heapify - heapify the heap
  * @node: node start
  */

void heapify(heap_t *node)
{
	int tmp;
	heap_t *max = node;

	if (node->left != NULL && node->left->n > max->n)
	{
		max = node->left;
	}

	if (node->right != NULL && node->right->n > max->n)
	{
		max = node->right;
	}

	if (max != node)
	{
		tmp = node->n;
		node->n = max->n;
		max->n = tmp;
		heapify(max);
	}
}

/**
  * find_height - find height
  * @node: node start
  * @height: height of start node
  *
  * Return: heap height
  */

int find_height(heap_t *node, int height)
{
	int left, right;

	if (node == NULL)
	{
		return (height - 1);
	}
	height++;
	left = find_height(node->left, height);
	right = find_height(node->right, height);
	if (left > right)
	{
		return (left);
	}

	return (right);
}

/**
  * get_top - get top
  * @node: node start
  * @height: heap height
  * @node_height: node height
  *
  * Return: new top
  */

heap_t *get_top(heap_t *node, int height, int node_height)
{
	heap_t *tmp;

	if (node_height >= height - 1)
	{
		if (node->right != NULL)
		{
			return (node->right);
		}
		return (node->left);
	}
	tmp = get_top(node->right, height, node_height + 1);
	if (tmp != NULL)
	{
		return (tmp);
	}

	return (get_top(node->left, height, node_height + 1));
}