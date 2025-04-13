#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	/*variables pour le node courant, une balise et un stockage*/
	listint_t *current, *next_node, *temp;

	/*si la liste, le ptr sur liste ou le node suivant NOK*/
	if (!list || !*list || !(*list)->next)
		return; /*on quitte la fonction*/

	current = (*list)->next; /*on se place sur le 2e node de la liste*/

	while (current != NULL) /*boucle jusqu'à la fin de la liste*/
	{
		next_node = current->next; /*on place la balise sur le node suivant*/

		/*boucle tant qu'il y a un node préc & compare les valeurs des nodes*/
		while (current->prev && current->n < current->prev->n)
		{
			temp = current->prev; /*on stock le node dans le stockage*/

			if (current->next) /*si il y a un node suivant*/
				current->next->prev = temp; /*lie le prev au node swap*/
			temp->next = current->next; /*lie le node au next*/

			current->prev = temp->prev; /*lie le node prev au node swap*/
			current->next = temp; /*swap entre le node next et le stocké*/

			if (temp->prev) /*vérifie si il y a un lien prev*/
				temp->prev->next = current; /*lie au node courant*/
			else
				*list = current; /*sinon devient le head*/

			temp->prev = current; /*le node précédent devient le courant*/

			print_list(*list); /*on print la chaine*/
		}

		current = next_node; /*on va a la balise*/
	}
}

