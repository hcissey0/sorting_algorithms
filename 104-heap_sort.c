#include "sort.h"

/**
 * swap - swaps 2 ints
 * @a: the first
 * @b: the second
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * sift_down - repairs the heap
 * @array: the array
 * @size: the size
 * @start: the start
 * @end: the end
 */
void sift_down(int *array, size_t size, int start, int end)
{
	int r = start;
	int ch, swp_idx;

	while (r * 2 + 1 <= end)
	{
		ch = r * 2 + 1;
		swp_idx = r;

		if (array[swp_idx] < array[ch])
			swp_idx = ch;
		if (ch + 1 <= end && array[swp_idx] < array[ch + 1])
			swp_idx = ch + 1;
		if (swp_idx == r)
			return;
		else
		{
			swap(&array[r], &array[swp_idx]);
			print_array(array, size);
			r = swp_idx;
		}
	}
}

/**
 * heaper - orders the elemnt in an array into a heap
 * @array: the array
 * @size: the size of the array
 */
void heaper(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}

/**
 * heap_sort - sorts an array with heap sort algo
 * @array: the array
 * @size: the size
 */
void heap_sort(int *array, size_t size)
{
	int end;
	if (array == NULL || size < 2)
		return;
	heaper(array, size);

	end = size - 1;
	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
