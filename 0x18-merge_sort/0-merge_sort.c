#include "sort.h"

/**
  * merge_sort - sort an array using merge sort ascending
  * @array: array to be sorted
  * @size: size of array
  */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);

	sort(array, size, temp);
	free(temp);
}

/**
  * sort - actually does the sorting
  * @arr: array to be sorted
  * @size: size of array
  * @temp: temporary array
  */
void sort(int *arr, size_t size, int *temp)
{
	size_t left_s = size / 2;
	size_t right_s = size - left_s;
	size_t i = 0, j = 0, k = 0;
	int *right = arr + left_s;

	if (size <= 1)
	{
		return;
	}
	sort(arr, left_s, temp);
	sort(right, right_s, temp);
	for (i = 0; i < left_s; i++)
	{
		temp[i] = arr[i];
	}
	i = 0;
	printf("Merging...\n[left]: ");
	print_array(arr, left_s);
	printf("[right]: ");
	print_array(right, right_s);
	while (i < left_s || j < right_s)
	{
		while (j < right_s && (i >= left_s || right[j] < temp[i]))
		{
			arr[k] = right[j];
			k++;
			j++;
		}
		while (i < left_s && (j >= right_s || temp[i] <= right[j]))
		{
			arr[k] = temp[i];
			k++;
			i++;
		}
	}
	printf("[Done]: ");
	print_array(arr, size);
}
