#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Partitions an array using Lomuto scheme
 * @array: The array to partition
 * @lb: Lower bound index
 * @ub: Upper bound index
 * @size: Size of the array for printing
 *
 * Return: final pivot index
 */
int lomuto_partition(int *array, int lb, int ub, size_t size)
{
    int pivot = array[ub];
    int i = lb, j;

    for (j = lb; j < ub; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != ub && array[i] != array[ub])
    {
        swap(&array[i], &array[ub]);
        print_array(array, size);
    }
    return i;
}

/**
 * quick_sort_recursive - Recursively sorts subarrays
 * @array: The array to sort
 * @lb: Lower bound index
 * @ub: Upper bound index
 * @size: Size of array for printing
 */
void quick_sort_recursive(int *array, int lb, int ub, size_t size)
{
    int pivot_index;

    if (lb < ub)
    {
        pivot_index = lomuto_partition(array, lb, ub, size);
        quick_sort_recursive(array, lb, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, ub, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

