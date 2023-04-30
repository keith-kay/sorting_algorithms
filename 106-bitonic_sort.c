#include "sort.h"
#include <stdio.h>
/** bitonic_sort */

/**
* bitonic_comp - sort bitonic algorithm
* @top: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
*/

void bitonic_comp(char top, int *array, size_t size)
{
	size_t i, eva;
	int swap;

	eva = size / 2;
	for (i = 0; i < eva; i++)
	{
		if ((array[i] > array[i + eva]) == top)
		{
			swap = array[i];
			array[i] = array[i + eva];
			array[i + eva] = swap;
		}
	}
}

/**
* bit_join - recursion to mergess ub-arrays
* @top: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
*
* Return: void
*/

void bit_join(char top, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_comp(top, array, size);
	bit_join(top, array, size / 2);
	bit_join(top, array + (size / 2), size / 2);
}

/**
* rec_sort - recursive bitonic sort algorithm
* @top: direction of sorting
* @array: sub-array to sort
* @size: size of the sub-array
* @t: total size of the original array
*
* Return: void
*/

void rec_sort(char top, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (top == 1) ? "top" : "DOWN");
	print_array(array, size);
	rec_sort(1, array, size / 2, t);
	rec_sort(0, array + (size / 2), size / 2, t);
	bit_join(top, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (top == 1) ? "top" : "DOWN");
	print_array(array, size);

}

/**
* bitonic_sort - sorts an array in ascending order
* @array: array to sort
* @size: size of the array
*
* Return: void
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	rec_sort(1, array, size, size);
}
