#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using the bubble sort
 * @array: expected to be printed when we swap two elements
 * @size: size of the array
 *
 * Return: big o notation of the time complexity
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;
	int swapped;

	if (array  == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}

		}

		if (swapped == 0)
			break;
	}
}
