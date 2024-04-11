#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: A pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr, *tmp;

    for (curr = (*list)->next; curr != NULL; curr = tmp)
    {
        tmp = curr->next;
        while (curr->prev != NULL && curr->n < curr->prev->n)
        {
            curr->prev->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = curr->prev;
            curr->next = curr->prev;
            curr->prev = curr->next->prev;
            curr->next->prev = curr;
            if (curr->prev == NULL)
                *list = curr;
            else
                curr->prev->next = curr;
            print_list(*list);
        }
    }
}
