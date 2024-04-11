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

    listint_t *curr = (*list)->next, *tmp;

    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;
        while (tmp->prev != NULL && tmp->n < tmp->prev->n)
        {
            tmp->prev->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->prev = tmp->prev;
            tmp->next = tmp->prev;
            tmp->prev = tmp->next->prev;
            tmp->next->prev = tmp;
            if (tmp->prev == NULL)
                *list = tmp;
            else
                tmp->prev->next = tmp;
            print_list(*list);
        }
    }
}
