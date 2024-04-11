/* sort.h */
#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Provided functions */
void print_array(const int *array, size_t size);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
