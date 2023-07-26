#include "sort.h"

/**
 * get_max - get the max value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array to be sorted
 *
 * Return: The maximum integer in the array
 */
int get_max(int *array, int size)
{
    int max_value, index;

    for (max_value = array[0], index = 1; index < size; index++)
    {
        if (array[index] > max_value)
            max_value = array[index];
    }

    return max_value;
}

/**
 * counting_sort - Sorting an array in an accending order.
 * @array: The unordered list that will be sorted
 * @size: The size of the array.
 * 
 * Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array, max_value, index;

    if (array == NULL || size <= 1)
        return;

    sorted_array = malloc(sizeof(*sorted_array) * size);
    if (sorted_array == NULL)
        return;
    max_value = get_max(array, size);
    count_array = malloc(sizeof(*count_array) * (max_value + 1));
    if (count_array == NULL)
    {
        free(sorted_array);
        return;
    }

    for (index = 0; index < (max_value + 1); index++)
        count_array[index] = 0;
    for (index = 0; index < (int)size; index++)
        count_array[array[index]] += 1;
    for (index = 0; index < (max_value + 1); index++)
        count_array[index] += count_array[index - 1];

    print_array(count_array, max_value + 1);

    for (index = 0; index < (int)size; index++)
    {
        sorted_array[count_array[array[index]] - 1] = array[index];
        count_array[array[index]] -= 1;
    }

    for (index = 0; index < (int)size; index++)
        array[index] = sorted_array[index];

    free(sorted_array);
    free(count_array);
}
