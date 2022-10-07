#include "main.h"



int main(void)
{
	card *top = NULL;
	card *new;
	card ten = {"10", CLUBS, NULL, NULL};
	size_t n;

	top = &ten;
	new = malloc(sizeof(card));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->num = "A";
	new->suit = HEARTS;
	new->next = top;
	new->prev = NULL;
	top = new;
	n = print_cards(top);
	printf("-> %lu cards\n", n);
	n = print_cards_sm(top);
	printf("-> %lu small cards\n", n);
	free(new);
	return (EXIT_SUCCESS);
}

/**
 * @brief prints a set of cards
 * 
 * @param hand set of cards to print
 * @return size_t number of cards printed
 */
size_t print_cards(const card *hand)
{
	const card *temp = hand;
	int i, numCards = 0;

	while (temp)
	{
		printf("********** ");
		numCards++;
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		if (temp->num[1])
			printf("* %s     * ", temp->num);
		else
			printf("* %s      * ", temp->num);

		temp = temp->next;
	}
	printf("\n");

	for (i = 0; i < 2; i++)
	{
		temp = hand;
		while (temp)
		{
			printf("*        * ");
			temp = temp->next;
		}
		printf("\n");
	}

	temp = hand;
	while (temp)
	{
		printf("*   %s    * ", temp->suit);
		temp = temp->next;
	}
	printf("\n");

	for (i = 0; i < 2; i++)
	{
		temp = hand;
		while (temp)
		{
			printf("*        * ");
			temp = temp->next;
		}
		printf("\n");
	}

	temp = hand;
	while (temp)
	{
		if (temp->num[1])
			printf("*     %s * ", temp->num);
		else
			printf("*      %s * ", temp->num);
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		printf("********** ");
		temp = temp->next;
	}
	printf("\n");

	return (numCards);
}

size_t print_cards_sm(const card *hand)
{
	const card *temp = hand;
	int i, numCards = 0;

	while (temp)
	{
		printf("**** ");
		numCards++;
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		if (temp->num[1])
			printf("*10* ");
		else
			printf("*%s * ", temp->num);
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		printf("* %s* ", temp->suit);
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		printf("**** ");
		temp = temp->next;
	}
	printf("\n");

	return (numCards);
}
