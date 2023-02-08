#include "sort.h"

/**
 * merge_func - merging elements of the array
 * @array: array to ordered
 * @arr: aux array
 * @primary: primary index
 * @middle: middle index
 * @final: final index
 * Return: Nothing
 */
void merge_func(int *array, int *arr, int primary, int middle, int final)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + primary, middle - primary);
	printf("[right]: ");
	print_array(array + middle, final - middle);

	for (i = primary, j = middle, k = 0; i < middle && j < final; k++)
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	while (i < middle)
		arr[k++] = array[i++];
	while (j < final)
		arr[k++] = array[j++];
	for (i = primary, k = 0; i < final; i++)
		array[i] = arr[k++];

	printf("[Done]: ");
	print_array(array + primary, final - primary);
}

/**
 * split - function that splits an array
 * @array: array to ordered
 * @arr: aux array
 * @primary: primary index
 * @final: final index
 * Return: Nothing
 */
void split_func(int *array, int *arr, int primary, int final)
{
	int middle;

	if (final - primary > 1)
	{
		middle = (final - primary) / 2 + primary;
		split_func(array, arr, primary, middle);
		split_func(array, arr, middle, final);
		merge_func(array, arr, primary, middle, final);
	};
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: unordered array
 * @size: the array's size to order
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	arr = malloc(sizeof(int) * size);
	split_func(array, arr, 0, size);
	free(arr);
}
