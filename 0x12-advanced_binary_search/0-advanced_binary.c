#include "search_algos.h"

/**
 * advanced_binary - Advanced binary search.
 * @array: Pointer to head of array.
 * @size: Size of the array.
 * @value: Search value.
 * Return: First index of value or -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;
	int low = 0;
	int high = size - 1;

	if (array == NULL || size == 0 || value < array[0])
	{
		return (-1);
	}
	index = recursive_binary(array, low, high, value);
	return (index);
}

/**
 * recursive_binary - Recursive binary search.
 * @array: Pointer to head of array.
 * @low: Low end of array.
 * @high: High end of array.
 * @value: Target value.
 * Return: First index of value or -1.
 */
int recursive_binary(int *array, int low, int high, int value)
{
	if (high >= low)
	{
		int i;
		int index;
		int mid;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
		}
		printf("\n");
		mid = low + (high - low) / 2;
		if (array[mid] == value && array[mid - 1] != value)
		{
			return (mid);
		}
		else if (array[mid] >= value)
		{
			index = recursive_binary(array, low, mid, value);
		}
		else
		{
			index = recursive_binary(array, mid + 1, high, value);
		}
		return (index);
	}
	return (-1);
}
