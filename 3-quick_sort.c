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
	int lb, ub, i, j, tmp, pivot;
	void recursive(int *arr, int lb, int ub);

	if (array == NULL || size < 2)
		return;

	recursive(array, 0, (int)size - 1);

	void recursive(int *arr, int lb, int ub)
	{
		int k;

		if (lb < ub)
		{
			pivot = arr[ub];
			i = lb;
			for (j = lb; j < ub; j++)
			{
				if (arr[j] < pivot)
				{
					if (i != j)
					{
						tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
						for (k = 0; k < (int)size; k++)
						{
							printf("%d", arr[k]);
							if (k != (int)size - 1)
								printf(", ");
						}
						printf("\n");
					}
					i++;
				}
			}
			if (i != ub)
			{
				tmp = arr[i];
				arr[i] = arr[ub];
				arr[ub] = tmp;
				for (k = 0; k < (int)size; k++)
				{
					printf("%d", arr[k]);
					if (k != (int)size - 1)
						printf(", ");
				}
				printf("\n");
			}
			recursive(arr, lb, i - 1);
			recursive(arr, i + 1, ub);
		}
	}
}
