#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/* Doubly linked list node structure */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);

#endif /* SORT_H */
