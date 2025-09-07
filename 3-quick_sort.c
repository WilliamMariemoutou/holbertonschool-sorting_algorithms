#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 *  quick_sort - sorts an array of integers in ascending order using the
 *  quick sort algorithm
 *  @array: the values to be sorted
 *  @size: size of the array
 *
 *  Return: the time complexity
 */
void quick_sort(int *array, size_t size)
{
	int lb, ub, i, j, pi, top;
	int temp, k;
	int pivot;
	int stack[1024];

	if (array == NULL || size < 2)
		return;

	lb = 0;
	ub = (int)size - 1;
	top = -1;

	stack[++top] = lb;
	stack[++top] = ub;

	while (top >= 0)
	{
		ub = stack[top--];
		lb = stack[top--];

		pivot = array[ub];
		i = lb - 1;

		for (j = lb; j < ub; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				for (k = 0; k < (int)size; k++)
				{
					if (k != (int)size - 1)
						printf("%d, ", array[k]);
					else
						printf("%d\n", array[k]);
				}
			}
		}

		temp = array[i + 1];
		array[i + 1] = array[ub];
		array[ub] = temp;

		for (k = 0; k < (int)size; k++)
		{
			if (k != (int)size - 1)
				printf("%d, ", array[k]);
			else
				printf("%d\n", array[k]);
		}

		pi = i + 1;

		if (pi - 1 > lb)
		{
			stack[++top] = lb;
			stack[++top] = pi - 1;
		}
		if (pi + 1 < ub)
		{
			stack[++top] = pi + 1;
			stack[++top] = ub;
		}
	}
}
