#include "search_algos.h"
/**
 * print_result - a function that print the array
 * @array: pointer to the first element of the array to print
 * @left: the first element of the array
 * @right: the last element of the array
 * Return: Nothing to return
 **/
void print_result(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%i, ", array[left]);
		left++;
	}
	printf("%i\n", array[left]);
}
/**
 * recursion_used - search function using recursion
 * @array: pointer to the first element of the array to search in
 * @left: index of first element of the array
 * @right: index of last element of the array
 * @value: the value to search for
 * Return: the index where value is located, or -1
 **/
int recursion_used(int *array, int left, int right, int value)
{
	int center;

	print_result(array, left, right);
	center = (right - left) / 2 + left;
	if (left == right)
		return (-1);
	if (array[center] == value && array[center - 1] != value)
		return (center);
	if (array[center] >= value)
		return (recursion_used(array, left, center, value));
	if (array[center] <= value)
		return (recursion_used(array, center + 1, right, value));
	return (-1);
}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the index where value is located, or -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (recursion_used(array, 0, size - 1, value));
}
