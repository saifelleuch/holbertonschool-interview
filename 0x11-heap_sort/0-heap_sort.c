#include "sort.h"
/**
 * swap_element - swaps elements
 * @x: The first element
 * @y: The second element
 */
void swap_element(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * make_heap - makes a heap out of array
 * @array: the array
 * @h_size: heap size
 * @i: the index
 * @size: Number of elements of the array
 */
void make_heap(int *array, int h_size, int i, size_t size)
{
	int max = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < h_size && array[left] > array[max])
		max = left;

	if (right < h_size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap_element(&array[i], &array[max]);
		print_array(array, size);
		make_heap(array, h_size, max, size);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Unordered array
 * @size: The number of elements of the array
 */
void heap_sort(int *array, size_t size)
{
	int x;

	for (x = size / 2 - 1; x >= 0; x--)
		make_heap(array, size, x, size);

	for (x = size - 1; x >= 0; x--)
	{
		swap_element(&array[0], &array[x]);
		if (x != 0)
			print_array(array, size);
		make_heap(array, x, 0, size);
	}
}
