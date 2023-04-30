#include "sort.h"

/** heap_ssort */

/**
* shift_down - fixes a heap
* @array: the heap to be fixed
* @root: root of heap
* @end: ;ast index of the heap
* @size: size of the array
*/

void shift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t x, y, swp;
	int tmp;

	while ((x = (2 * root) + 1) <= end)
	{
		swp = root;
		y = x + 1;
		if (array[swp] < array[x])
			swp = x;
		if (y <= end && array[swp] < array[y])
			swp = y;
		if (swp == root)
			return;
		tmp = array[root];
		array[root] = array[swp];
		array[swp] = tmp;
		print_array(array, size);
		root = swp;
	}
}

/**
* heap - makes a heap from an unsorted array
* @array: array to turn into a heap
* @size: size of the array
*
* Return: void
*/

void heap(int *array, size_t size)
{
	size_t srce;

	for (srce = ((size - 1) - 1) / 2; 1; srce--)
	{
		shift_down(array, srce, size - 1, size);
		if (srce == 0)
			break;
	}
}

/**
* heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
* @array: array to sort
* @size: size of the array
*
* Return: void
*/

void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;

	if (array == NULL || size < 2)
		return;
	heap(array, size);
	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		shift_down(array, 0, end, size);
	}
}
