#include "sort.h"

/**
 * counting_sort - sorts an array with counting sort algo
 * @array: the array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int m = 0;
	int *c, *out;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > m)
			m = array[i];
	c = malloc(sizeof(int) * (m + 1));
	out = malloc(sizeof(int) * size);
	for (i = 0; i < (size_t)m; i++)
		c[i] = 0;
	for (i = 0; i < size; i++)
		c[array[i]]++;
	for (i = 1; i <= (size_t)m; i++)
		c[i] += c[i - 1];
	print_array(c, m + 1);
	for (i = 0; i < size; i++)
	{
		out[c[array[i]] - 1] = array[i];
		c[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = out[i];
	free(c);
	free(out);
}
