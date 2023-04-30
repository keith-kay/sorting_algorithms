#include "sort.h"

/** heap_sort */

/**
* rad_10 - calculates a ppower of 10
* @power: power of 10 for calculation
* Return: final rsltult
*/

unsigned int rad_10(unsigned int power)
{
	unsigned int i, rslt;

	rslt = 1;
	for (i = 0; i < power; i++)
		rslt *= 10;
	return (rslt);
}

/**
* asc_sort - sorts an array of integers in ascending order
* @array: array to be sorted
* @size: size of the array to be sorted
* @num: num to sort
*
* Return: 1 if when need to keep sorting, otherwise 0
*/

unsigned int asc_sort(int *array, size_t size, unsigned int num)
{
	int i, count[10] = {0};
	int *cpy = NULL;
	size_t j, temp, total = 0;
	unsigned int dp1, dp2, sort = 0;

	dp2 = rad_10(num - 1);
	dp1 = dp2 * 10;
	cpy = malloc(sizeof(int) * size);
	if (cpy == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] / dp1 != 0)
			sort = 1;
	}
	for (i = 0; i < 10 ; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[(array[j] % dp1) / dp2] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[(cpy[j] % dp1) / dp2]] = cpy[j];
		count[(cpy[j] % dp1) / dp2] += 1;
	}
	free(cpy);
	return (sort);
}

/**
* radix_sort - Radix sort algorithm
* @array: array to sort
* @size: size of the array
*/

void radix_sort(int *array, size_t size)
{
	unsigned int i, sort = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; sort == 1; i++)
	{
		sort = asc_sort(array, size, i);
		print_array(array, size);
	}
}
