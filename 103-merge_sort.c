#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/** 103-merge_sort.c */

/**
* TopDownMerge - sorts and merges the sub arrays
* @begin: begining index
* @mid: middle of index
* @end: end index
* @dest: destination for the data
* @source: source of the data
*
* Return: void
*/

void TopDownMerge(size_t begin, size_t mid, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + begin, mid - begin);
	printf("[right]: ");
	print_array(source + mid, end - mid);
	i = begin;
	j = mid;
	for (k = begin; k < end; k++)
	{
		if (i < mid && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + begin, end - begin);
}

/**
* TopDownSplitMerge - recursively splits the array, merge and sort
* @begin: begining index (inclusive)
* @end: end index (exclusive)
* @array: the array to sort
* @copy: a copy of the array
*/

void TopDownSplitMerge(size_t begin, size_t end, int *array, int *copy)
{
	size_t mid;

	if (end - begin < 2)
		return;
	mid = (begin + end) / 2;
	TopDownSplitMerge(begin, mid, array, copy);
	TopDownSplitMerge(mid, end, array, copy);
	TopDownMerge(begin, mid, end, array, copy);
	for (mid = begin; mid < end; mid++)
		copy[mid] = array[mid];
}

/**
* merge_sort - sorts an array of integers
* Merge sort algorithm
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	TopDownSplitMerge(0, size, array, copy);
	free(copy);
}
