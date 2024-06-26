#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Flag to check if any swap has occurred */
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap array[j] and array[j+1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /* Set the flag to true indicating a swap */
				print_array(array, size);
			}
		}
		/*
		 * If no two elements were swapped in the inner loop,
		 * then break
		 */
		if (swapped == 0)
			break;
	}
}
