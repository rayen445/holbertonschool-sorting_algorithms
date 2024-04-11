#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void print_array(const int *array, size_t size);
void quick_sort(int *array, size_t size);
void _quick_sort(int *array, int low, int high, size_t size);
int _partition(int *array, int low, int high, size_t size);

#endif /* SORT_H */
