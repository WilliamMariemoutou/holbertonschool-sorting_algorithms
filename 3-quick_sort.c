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
#include <stddef.h>

void quick_sort(int *array, size_t size);

static int lomuto_partition(int *array, int lb, int ub)
{
    int pivot, i, j, tmp;

    pivot = array[ub];
    i = lb;

    for (j = lb; j < ub; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
        }
    }

    if (i != ub)
    {
        tmp = array[i];
        array[i] = array[ub];
        array[ub] = tmp;
    }

    return i;
}

static void quick_sort_recursive(int *array, int lb, int ub)
{
    int pivot_index;
    if (lb < ub)
    {
        pivot_index = lomuto_partition(array, lb, ub);
        quick_sort_recursive(array, lb, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, ub);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_recursive(array, 0, (int)size - 1);
}
