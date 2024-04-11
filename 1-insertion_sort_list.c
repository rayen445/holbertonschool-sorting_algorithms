#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm.
 * @list: Pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next, *tmp;

    while (curr != NULL)
    {
        tmp = curr->next;
        while (curr->prev != NULL && curr->n < curr->prev->n)
        {
            curr->prev->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = curr->prev;
            curr->next = curr->prev;
            curr->prev = curr->prev->prev;
            curr->next->prev = curr;
            if (curr->prev != NULL)
                curr->prev->next = curr;
            else
                *list = curr;
            print_list(*list);
        }
        curr = tmp;
    }
}
