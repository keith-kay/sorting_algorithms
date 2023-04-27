#include "sort.h"
/*100-shell_sort.c*/

/**
 * swap - swap two elements in an integer array
 * @array: integer array
 * @index1: index of first element
 * @index2: index of second element
 */

void swap(int *array, int item1, int item2)
{

	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * shell_sort - sort an integer array in ascending order using the Shell sort algorithm
 * @array: integer array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
