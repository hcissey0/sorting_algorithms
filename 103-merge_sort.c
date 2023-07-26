#include "sort.h"

/**
 * merger - merges 2 sub arrays
 * @array: the array
 * @tmp: the temp
 * @l: the left
 * @m: the middle
 * @r: the right
 */
void merger(int *array, int *tmp, int l, int m, int r)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l + 1);
	printf("[right]: ");
	print_array(array + m + 1, r - m);

	for (i = l, j = m + 1, k = 0; k <= r - l; k++)
	{
		if (i <= m && (j > r || array[i] <= array[j]))
			tmp[k] = array[i++];
		else
			tmp[k] = array[j++];
	}
	for (i = l, k = 0; i <= r; i++, k++)
		array[i] = tmp[k];
	printf("[Done]: ");
	print_array(array + l, r - l +1);
}

/**
 * my_merge_sort - my recursive merge sort
 * @array: the array
 * @tmp: the temp
 * @l: the left index
 * @r: the right index
 */
void my_merge_sort(int *array, int *tmp, int l, int r)
{
	int m;

	if (r <= l)
		return;
	m = (l + r) / 2;
	my_merge_sort(array, tmp, l, m);
	my_merge_sort(array, tmp, m + 1, r);
	merger(array, tmp, l, m, r);
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
	my_merge_sort(array, tmp, 0, size - 1);

	free(tmp);
}
