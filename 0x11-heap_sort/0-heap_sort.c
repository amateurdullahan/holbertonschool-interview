#include <stdio.h>
#include "sort.h"

/**
  * heap_sort - heap sorts, sift-down
  * @array: the array
  * @size: the size of array!
  */

void heap_sort(int *array, size_t size)
{
	int tmp;
    int i;
    int arr_size;

	if (array == NULL)
    {
		return;
    }
    if (size < 2)
    {
        return;
    }
    if (size == 2)
    {
		if (array[0] >= array[1])
		{
			tmp = array[0];
			array[0] = array[1];
			array[1] = tmp;
			print_array(array, size);
		}
		return;
	}
	arr_size = size;
	for (i = (arr_size / 2) - 1; i >= 0; i--)
    {
		heapify(array, size, i);
    }
    for (i = arr_size - 1; i >= 0; i--)
	{
		swap(array, &array[0], &array[i]);
		heapify(array, i, 0);
	}
}

/**
  * heapify - heapifys
  * @arr: the array
  * @size: the size
  * @root: the root
  */

void heapify(int *arr, size_t size, size_t root)
{
	int left = (root * 2) + 1;
	int right = (root * 2) + 2;
	int parent = root;
	int arr_size = size;

	if (left < arr_size && arr[left] > arr[parent])
    {
		parent = left;
    }
    if (right < arr_size && arr[right] > arr[parent])
	{
        parent = right;
    }
    if (parent != (int)root)
    {
		swap(arr, &arr[root], &arr[parent]);
		heapify(arr, size, parent);
	}
}

/**
  * swap - swaps
  * @arr: the array
  * @parent: the parent
  * @child: the child
  */

void swap(int *arr, int *parent, int *child)
{
	int tmp;
	size_t i;

	tmp = *parent;
	*parent = *child;
	*child = tmp;
	for (i = 0; arr[i]; i++)
    {
		continue;
    }
    if (parent != child)
    {
		print_array(arr, i);
    }
}
