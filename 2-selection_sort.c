#include "sort.h"

/**
 * selection_sort - Sorts an array using selections sort algo
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, n = size;

	if (array == NULL)
		return;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			j = array[i];
			array[i] = array[min];
			array[min] = j;
			print_array(array, size);
		}
	}
}
