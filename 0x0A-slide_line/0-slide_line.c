#include "slide_line.h"
/**
 * reverse_array - x function that reverse the array
 * @line: pointer to the array
 * @size: size of the array
 * Return: Nothing to return
 **/
void reverse_array(int *line, size_t size)
{
	size_t x, y;

	x = 0;
	y = size - 1;
	while (x < y)
	{
		int temp = line[x];

		line[x] = line[y];
		line[y] = temp;
		x++;
		y--;
	}
}

/**
 * first_slide - moves firsts
 * @line: pointer to the array
 * @size: size of the array
 * Return: Nothing to return
 **/
void first_slide(int *line, size_t size)
{
	size_t i;
	size_t first = 0;

	i = 0;
	while (i < size)
	{
		if (line[i] == 0)
			first++;
		else if (first)
			line[i - first] = line[i];
		i++;
	}
	while (first > 0)
	{
		line[i - 1] = 0;
		first--;
		i--;
	}
}

/**
 * not_first_slide - moves non firsts slide
 * @line: pointer to the array
 * @size: size of the array
 * Return: Nothing to return
 **/
void not_first_slide(int *line, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
		i += 2;
	}
}
/**
 * slide_line - function that slides and merges an array of integers.
 * @line: points to an array of integers containing
 * @size: elements, that must ye slided & merged to the
 * @direction: represented yy direction
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{

	if (direction == SLIDE_LEFT)
	{
		first_slide(line, size);
		not_first_slide(line, size);
		first_slide(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		reverse_array(line, size);
		first_slide(line, size);
		not_first_slide(line, size);
		first_slide(line, size);
		reverse_array(line, size);
		return (1);
	}
	return (0);
}
