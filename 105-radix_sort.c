#include "sort.h"

/**
 * getmax - gets the maximum int in array
 * @array: the array
 * @size: the size of the array
 *
 * Return: the max int
 */
int getmax(int *array, size_t size)
{
	int m = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > m)
			m = array[i];
	return (m);
}

/**
 * my_radix_sort - sorts an array of ints
 * @array: the array
 * @size: the size
 * @radix: the current digit
 */
void my_radix_sort(int *array, size_t size, int radix)
{
	int *out;
	int i, c[10];

	for (i = 0; i < 10; i++)
		c[i] = 0;
	out = malloc(sizeof(int) * size);
	if (out == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		c[(array[i] / radix) % 10]++;
	for (i = 1; i < 10; i++)
		c[i] += c[i - 1];
	for (i = size; i >= 0; i--)
	{
		out[c[(array[i] / radix) % 10] - 1] = array[i];
		c[(array[i] / radix) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
	free(out);
}

/**
 * radix_sort - sorts an array of integers
 * @array: the array
 * @size: the size of teh array
 */
void radix_sort(int *array, size_t size)
{
	int m, radix;

	if (array == NULL || size < 2)
		return;
	m = getmax(array, size);
	for (radix = 1; m / radix > 0; radix *= 10)
	{
		my_radix_sort(array, size, radix);
		print_array(array, size);
	}
}
