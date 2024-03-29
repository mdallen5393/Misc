#include "main.h"

// int main(void)
// {
// 	card *top = NULL;
// 	card *new;
// 	card ten = {"10", CLUBS, NULL, NULL};
// 	size_t n;

// 	top = &ten;
// 	new = malloc(sizeof(card));
// 	if (new == NULL)
// 	{
// 		dprintf(2, "Error: Can't malloc\n");
// 		return (EXIT_FAILURE);
// 	}
// 	new->denom = "A";
// 	new->suit = HEARTS;
// 	new->next = top;
// 	new->prev = NULL;
// 	top = new;
// 	n = print_cards(top);
// 	printf("-> %lu large cards\n", n);
// 	n = print_cards_sm(top);
// 	printf("-> %lu small cards\n", n);
// 	printf("-> %lu cards total\n", num_cards(top) + num_cards(top));
// 	free(new);
// 	return (EXIT_SUCCESS);
// }

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

	if (!temp)
		return (0);

	while (temp)
	{
		printf(TL HL HL HL HL HL HL HL HL TR " ");
		numCards++;
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		if (temp->denom[1])
			printf(VL " %s     " VL " ", temp->denom);
		else
			printf(VL " %s      " VL " ", temp->denom);

		temp = temp->next;
	}
	printf("\n");

	for (i = 0; i < 1; i++)
	{
		temp = hand;
		while (temp)
		{
			printf(VL "        " VL " ");
			temp = temp->next;
		}
		printf("\n");
	}

	temp = hand;
	while (temp)
	{
		printf(VL "   %s    " VL " ", temp->suit);
		temp = temp->next;
	}
	printf("\n");

	for (i = 0; i < 1; i++)
	{
		temp = hand;
		while (temp)
		{
			printf(VL "        " VL " ");
			temp = temp->next;
		}
		printf("\n");
	}

	temp = hand;
	while (temp)
	{
		if (temp->denom[1])
			printf(VL "     %s " VL " ", temp->denom);
		else
			printf(VL "      %s " VL " ", temp->denom);
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		printf(BL HL HL HL HL HL HL HL HL BR " ");
		temp = temp->next;
	}
	printf("\n");

	return (numCards);
}

size_t print_cards_sm(const card *hand)
{
	const card *temp = hand;
	int i, numCards = 0;

	if (!temp)
		return (0);

	while (temp)
	{
		printf(TL HL HL HL HL TR " ");
		numCards++;
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		if (temp->denom[1])
			printf(VL " 10 " VL " ");
		else
			printf(VL " %s  " VL " ", temp->denom);
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		printf(VL "  %s " VL " ", temp->suit);
		temp = temp->next;
	}
	printf("\n");

	temp = hand;
	while (temp)
	{
		printf(BL HL HL HL HL BR " ");
		temp = temp->next;
	}
	printf("\n");

	return (numCards);
}

size_t num_cards(const card *hand)
{
	const card *temp = hand;
	size_t numCards = 0;

	while (temp)
	{
		numCards++;
		temp = temp->next;
	}

	return (numCards);
}

size_t print_deck(const card *hand)
{
	struct winsize sz;
	int i, j;
	ioctl(0, TIOCGWINSZ, &sz);
	int len = 6;
	card *deck_row;

	int cards_per_line = COLS / (len + 1);
	int num_lines = num_cards(hand) * (len + 1) / COLS + 1;

	j = 0;
	for (i = 0; i < num_lines; i++)
	{
		while (j < cards_per_line)
		{
			add_card(&deck_row, hand->denom, hand->suit, j)
			deck_row = deck_row->next
		}
		/* TODO: figure out how many cards to print*/
		print_cards_sm(deck_row)
	}

	for (i = 0; i < num_cards(hand) - cards_per_line * num_lines; i++)
		print_cards_sm(deck_row)
}
