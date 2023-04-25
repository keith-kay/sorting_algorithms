#include "sort.h"
/* 3-quick_sort.c */

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: the array to sort
 * @size: the number of elements in the array
 */

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * qs - sorts a partition of an array using the Quick sort algorithm
 * @array: the array to sort
 * @first: the first index of the partition
 * @last: the last index of the partition
 * @size: the number of elements in the array
 */

int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: the array to partition
 * @first: the first index of the partition
 * @last: the last index of the partition
 * @size: the number of elements in the array
 *
 * Return: the pivot index
 */

void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * swap - swaps two integers
 * @a: a pointer to the first integer
 * @b: a pointer to the second integer
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
