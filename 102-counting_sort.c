#include "sort.h"
#include <stdlib.h>


/** 102-counting_sort */

/**
 * counting_sort - sorts an array of integers
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *countarr, k;
	size_t i, j, arr;

	if (array == NULL || size <= 1)
		return;
	arr = array[0];
	for (i = 0; array[i]; i++)
	{
		if (array[i] > (int)arr)
			arr = array[i];
	}

	arr += 1;

	countarr = malloc(arr * sizeof(int *));
	if (countarr == NULL)
		return;

	for (i = 0; i < arr; i++)
		countarr[i] = 0;

	for (i = 0; i < size; i++)
		countarr[array[i]] += 1;

	for (i = 0; i <= arr; i++)
		countarr[i] += countarr[i - 1];

	print_array(countarr, arr);

	for (i = 1, j = 0; i <= arr; i++)
		if (countarr[i] != countarr[i - 1])
		{
			for (k = 0; k < countarr[i] - countarr[i - 1]; k++)
				array[j++] = i;
		}
	free(countarr);
}
