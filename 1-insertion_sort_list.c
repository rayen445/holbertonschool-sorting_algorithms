#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next, *tmp;

    while (curr != NULL)
    {
        tmp = curr->prev;
        while (tmp != NULL && tmp->n > curr->n)
        {
            if (curr->next != NULL)
                curr->next->prev = tmp;

            tmp->next = curr->next;
            curr->next = tmp;
            curr->prev = tmp->prev;

            if (tmp->prev != NULL)
                tmp->prev->next = curr;
            else
                *list = curr;

            tmp->prev = curr;

            print_list(*list);
            tmp = curr->prev;
        }
        curr = curr->next;
    }
}
