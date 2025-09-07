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
	size_t lb, ub, i, j, pi, k;
	int pivot, temp;
	size_t stack[1024];
	int top = -1;

	if (array == NULL || size < 2)
		return;

	stack[++top] = 0;
	stack[++top] = size - 1;

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

				for (k = 0; k < size; k++)
					printf("%d ", array[k]);
				printf("\n");
			}
		}

		temp = array[i + 1];
		array[i + 1] = array[ub];
		array[ub] = temp;

		for (k = 0; k < size; k++)
			printf("%d ", array[k]);
		printf("\n");

		pi = i + 1;

		if (pi > 0 && pi - 1 > lb)
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
