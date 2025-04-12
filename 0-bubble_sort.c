#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i; /*variable de boucle par l'index*/
	int temp; /*variable de stockage temporaire de valeur*/
	int swapped = 1; /*variable boolienne (true/false)*/

	/*vérifie si l'array est vide ou si la taille de l'array < 2*/
	if (array == NULL || size < 2)
		return; /*si oui on sort de la fonction*/

	while (swapped == 1) /*on continue tant que swapped vaut true*/
	{
		swapped = 0; /*on initialise le booléen à false a chaque tour*/

		for (i = 0; i < size - 1; i++) /*on parcours l'array*/
		{
			/*si la valeur > à la valeur suivante*/
			if (array[i] > array[i + 1])
			{
				temp = array[i]; /*on stock la valeur courante*/
				array[i] = array[i + 1]; /*val courante devient val suivante*/
				array[i + 1] = temp; /*val suivante devient val stockée*/
				swapped = 1; /*le booléen vaut true*/
				print_array(array, size); /*on print l'array*/
			}
		}
	}
}
