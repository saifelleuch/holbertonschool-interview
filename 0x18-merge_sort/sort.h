#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void split_func(int *array, int *arr, int primary, int final);
void merge_func(int *array, int *arr, int primary, int middle, int final);
void merge_sort(int *array, size_t size);

#endif
