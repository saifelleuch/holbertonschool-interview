#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 * Return: 2D Menger Sponge or nothing
 */

void menger(int level)
{
	int i, j, x, y;
	char str;

	if (level < 0)
		return;
	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level);)
		{
			str = '#';
			x = i;
			y = j++;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					str = ' ';
				x /= 3;
				y /= 3;
			}
			putchar(str);
		}
		printf("\n");
	}
}
