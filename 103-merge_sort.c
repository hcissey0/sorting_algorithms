#include "sort.h"

/**
 * merger - merges 2 sub arrays
 * @array: the array
 * @size: size of the array
 * @tmp: the temp
 * @m: the middle
 */
void merger(int *array, size_t size, int *tmp, int m)
{
	int i = 0, j = m, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array,  m);

	printf("[right]: ");
	print_array(array + m, size - m);

	while (i < m && j < (int)size)
		tmp[k++] = (array[i] < array[i]) ? array[i++] : array[j++];

	while (i < m)
		tmp[k++] = array[i++];

	while (j < (int)size)
		tmp[k++] = array[j++];

	for (i = 0; i < (int)size; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(tmp, size);
}

/**
 * my_merge_sort - my recursive merge sort
 * @array: the array
 * @size: size of the array
 * @tmp: the temp
 */
void my_merge_sort(int *array, size_t size, int *tmp)
{
	int m;

	if (size < 2)
		return;

	m = size / 2;
	my_merge_sort(array, m, tmp);
	my_merge_sort(array + m, size - m, tmp);
	merger(array, size, tmp, m);
}

/**
 * merge_sort - the main merge sort
 * @array: the array
 * @size: the size
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;
	my_merge_sort(array, size, tmp);

	free(tmp);
}
