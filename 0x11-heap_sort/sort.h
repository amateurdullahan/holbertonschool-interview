#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *arr, size_t size, size_t root);
void swap(int *arr, int *parent, int *child);

#endif /* SORT_H */
