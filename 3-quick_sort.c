#include "sort.h"

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	my_quick_sort(array, size, size);
}

/**
 * my_quick_sort - my modification to be able to print the array
 *
 * @array: the array
 * @size: the size
 * @os: the old size
 */
void my_quick_sort(int *array, size_t size, size_t os)
{
	size_t i, j, tmp;
	int pivot;

	if (array == NULL || size <= 1)
		return;
	/* set pivot to last element */
	pivot = array[size - 1];
	i = 0;
	j = 0;
	while (i < size - 1)
	{
		if (array[i] <= pivot)
		{
			/* swap */
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			j++;
		}
		i++;
	}

	/* swap pivot with current j */
	tmp = array[j];
	array[j] = array[size - 1];
	array[size - 1] = tmp;
	print_array(array, os);

	/* do the recursion for the sub arrays */
	my_quick_sort(array, j, os);
	my_quick_sort(array + j + 1, size - j - 1, os);
}
