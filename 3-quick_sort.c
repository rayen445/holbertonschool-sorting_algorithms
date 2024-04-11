#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements of an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for quicksort
 * @array: The array to be sorted
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
 * lomuto_quicksort - Implements the quicksort algorithm using Lomuto partition
 * @array: The array to be sorted
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * @size: The size of the array
 */
void lomuto_quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		lomuto_quicksort(array, low, pi - 1, size);
		lomuto_quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, 0, size - 1, size);
}
