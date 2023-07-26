#include "sort.h"

/**
 * radix_sort - sorts an array of integers
 * @array: the array
 * @size: the size of teh array
 */
void radix_sort(int *array, size_t size)
{
	int *out = NULL;
	int m =  array[0], radix, c[10] = {0};
	size_t i;

	/* find the max */
	for (i = 1; i < size; i++)
		if (array[i] > m)
			m = array[i];
	for (radix = 1; m / radix > 0; radix *= 10)
	{
		/* count each digit */
		for (i = 0; i < size; i++)
			c[(array[i] / radix) % 10]++;

		for (i = 1; i < 10; i++)
			c[i] += c[i - 1];

		out = malloc(sizeof(int) * size);
		if (out == NULL)
			return;
		for (i = size - 1; i > 0; i--)
		{
			out[c[(array[i] / radix) % 10] - 1] = array[i];
			c[(array[i] / radix) % 10]--;
		}
		out[c[(array[0] / radix) % 10] - 1] = array[0];
		for (i = 0; i < size; i++)
			array[i] = out[i];
		print_array(array, size);

		free(out);
	}
}
