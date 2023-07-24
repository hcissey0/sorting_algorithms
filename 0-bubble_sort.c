#include "sort.h"

/**
 * bubble_sort - This is the bubble sort algorithm in C
 *
 * @array: The array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	int swapped = 1, tmp;

	if (array == NULL || size < 2)
		return;
	while (swapped)
	{
		swapped = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		n = n - 1;
	}
}
