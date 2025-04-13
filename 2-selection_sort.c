#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: The array to print
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	/*variables de boucles (for) et de stockage de valeur la + petite*/
	size_t i, j, min_index;
	int temp; /*variable de stockage pour le swap*/

	if (!array || size < 2) /*si l'array est vide ou index < 2*/
		return; /*on quitte la fonction*/

	for (i = 0; i < size - 1; i++) /*on boucle sur l'array*/
	{
		min_index = i; /*on stock la val la plus petite*/

		/*boucle en partant de i + 1, on vérifie sa valeur*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index]) /*si plus petit*/
				min_index = j; /*on met à jour la val la plus petite*/
		}

		if (min_index != i) /*si val plus petite trouvée on swap*/
		{
			temp = array[i]; /*on stock la valeur*/
			array[i] = array[min_index]; /*on swap la petite valeur*/
			array[min_index] = temp; /*on place la valeur stockée*/
			print_array(array, size); /*on print l'array*/
		}
	}
}
