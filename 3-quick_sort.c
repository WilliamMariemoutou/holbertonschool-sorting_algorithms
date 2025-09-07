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
void quick_sort(int *array, size_t size);

static void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int lomuto_partition(int *array, int lb, int ub, size_t size)
{
	int pivot, i, j;

	pivot = array[ub];
	i = lb;
	for (j = lb; j < ub; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				for (i = 0; i < (int)size; i++)
				{
					printf("%d", array[i]);
					if (i != (int)size - 1)
						printf(", ");
				}
				printf("\n");
			}
			i++;
		}
	}
	if (i != ub)
	{
		swap(&array[i], &array[ub]);
		for (j = 0; j < (int)size; j++)
		{
			printf("%d", array[j]);
			if (j != (int)size - 1)
				printf(", ");
		}
		printf("\n");
	}
	return (i);
}

static void quick_sort_recursive(int *array, int lb, int ub, size_t size)
{
	int p;

	if (lb < ub)
	{
		p = lomuto_partition(array, lb, ub, size);
		quick_sort_recursive(array, lb, p - 1, size);
		quick_sort_recursive(array, p + 1, ub, size);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, (int)size - 1, size);
}
