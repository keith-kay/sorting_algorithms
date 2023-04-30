#include "sort.h"
# include <stdio.h>

/** 107-quick_sort_hoare */

/**
* partition - ssort using Hoare version
* @array: array to sort
* @min: lowest index
* @max: highest index
* @size: size of the array
*
* Return: partition index
*/

size_t partition(int *array, zsize_t min, zsize_t max, size_t size)
{
	int swp, pvt;

	pvt = array[max];
	while (min <= max)
	{
		while (array[min] < pvt)
			min++;
		while (array[max] > pvt)
			max--;
		if (min <= max)
		{
			if (min != max)
			{
				swp = array[min];
				array[min] = array[max];
				array[max] = swp;
				print_array(array, size);
			}
			min++;
			max--;
		}
	}
	return (max);
}

/**
* ssort - sorts a partition of an array of integers
* @array: array to sort
* @min: lowest index of the partition to sort
* @max: highest index of the partition to sort
* @size: size of the array
*
* Return: void
*/
void ssort(int *array, zsize_t min, zsize_t max, size_t size)
{
	zsize_t pvt;

	if (min < max)
	{
		pvt = partition(array, min, max, size);
		ssort(array, min, pvt, size);
		ssort(array, pvt + 1, max, size);

	}
}

/**
* quick_sort_hoare - sorts an array of integer with quick sort
* @array: The array to sort
* @size: The size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	ssort(array, 0, size - 1, size);
}
