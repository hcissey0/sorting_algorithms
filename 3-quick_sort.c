#include "sort.h"

/**
 * swap - swaps 2 numbers
 * @a: pointer to the first one
 * @b: pointer to the second one
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * partition - partition thr array using the
 * lomuto partition scheme
 * @array: the array
 * @size: size of the array
 * @lo: the first element
 * @hi: the last element
 *
 * Return: index of the pivot
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	i++;
	swap(&array[i], &array[hi]);

	return (i);
}

/**
 * my_quick_sort - my modification to be able to print the array
 *
 * @array: the array
 * @size: the size
 * @lo: the first element
 * @hi: the last element
 */
void my_quick_sort(int *array, size_t size, int lo, int hi)
{
	int p = 0;

	if (lo >= hi || lo < 0 || array == NULL || size < 2)
		return;

	p = partition(array, size, lo, hi);
	my_quick_sort(array, size, lo, p - 1);
	my_quick_sort(array, size, p + 1, hi);

}

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
	my_quick_sort(array, size, 0, size - 1);
}

