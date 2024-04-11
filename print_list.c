#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 * @list: A pointer to the head of the list
 */
void print_list(const listint_t *list)
{
    const listint_t *current = list;

    while (current != NULL)
    {
        printf("%d", current->n);
        current = current->next;
        if (current != NULL)
            printf(", ");
    }
    printf("\n");
}
