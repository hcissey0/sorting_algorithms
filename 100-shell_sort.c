#include "sort.h"

/**
 * shell_sort - the shell sort algorithm
 * @array: array
 * @size: size of the pointer
 */
void shell_sort(int *array, size_t size)
{
	size_t g = 1;
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (g < size / 3)
		g = g * 3 + 1;
	while (g >= 1)
	{
		for (i = g; i < size; i++)
		{
			for (j = i; j >= g && array[j] < array[j - g]; j -= g)
			{
				tmp = array[j];
				array[j] = array[j - g];
				array[j - g] = tmp;
			}
		}
		print_array(array, size);
		g /= 3;
	}
}
