#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    _quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursively sorts a partition of an array of integers
 *               in ascending order using the Quick sort algorithm.
 * @array: The array to sort.
 * @low: The starting index of the partition to sort.
 * @high: The ending index of the partition to sort.
 * @size: The size of the original array.
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = _partition(array, low, high, size);
        _quick_sort(array, low, pivot - 1, size);
        _quick_sort(array, pivot + 1, high, size);
    }
}

/**
 * _partition - Partitions a subarray of integers around a pivot
 *              using the Lomuto partition scheme.
 * @array: The array to partition.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 * @size: The size of the original array.
 *
 * Return: The final pivot position.
 */
int _partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i + 1);
}
