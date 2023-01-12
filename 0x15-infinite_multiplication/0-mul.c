#include "holberton.h"

/**
 * is_number - checks if the given argument is a number 
 * @argmt: argument to check
 * Return: 0 or 1
 **/
int is_number(char *argmt)
{
	while (*argmt)
	{
		if (*argmt < '0' || *argmt > '9')
			return (0);
		argmt++;
	}
	return (1);
}

/**
 * _strlen - function that count the length of the string
 * @s: string
 * Return: length of the string
 **/
int _strlen(char *s)
{
	char *tpm = s;

	while (*s)
		s++;
	return (s - tpm);
}

/**
 * multiply - multiply two numbers
 * @a: first number
 * @b: second number
 * Return: Nothing to return
 **/
void multiply(char *a, char *b)
{
	int i, len_a, len_b, total, a_number, b_number, res = 0, ptr;
	int *tpm;

	len_a = _strlen(a);
	len_b = _strlen(b);
	ptr = len_b;
	total = len_a + len_b;
	tpm = malloc(sizeof(int) * total);
	if (!tpm)
		return;
	for (len_a--; len_a >= 0; len_a--)
	{
		a_number = a[len_a] - '0';
		res = 0;
		len_b = ptr;
		for (len_b--; len_b >= 0; len_b--)
		{
			b_number = b[len_b] - '0';
			res += tpm[len_b + len_a + 1] + (a_number * b_number);
			tpm[len_a + len_b + 1] = res % 10;
			res /= 10;
		}
		if (res)
			tpm[len_a + len_b + 1] = res % 10;
	}
	while (*tpm == 0)
	{
		tpm++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", tpm[i]);
	printf("\n");
}

/**
 * main - is the entry point of the program that
 * multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 or 98 on error
 **/
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || !is_number(num1) || !is_number(num2))
	{
		printf("Error\n");
		exit(98);
	}
	multiply(num1, num2);
	return (0);
}
