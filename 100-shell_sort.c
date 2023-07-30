#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	/* Calculate initial gap value */
	size_t gap = 1;

    /* check if size is less than or equal to 1 */
    if (size <= 1 || array == NULL)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Compare and swap elements within the gap interval */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}

		/* Print array after each gap interval */
		print_array(array, size);

		/* Reduce the gap for the next iteration */
		gap = (gap - 1) / 3;
	}
}
