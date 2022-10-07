#include "main.h"

// int main(void)
// {
// 	card *top;

// 	top = NULL;
// 	add_card(&top, "A", HEARTS, num_cards(top));
// 	// add_card_end(&top, "A", HEARTS);
// 	add_card_end(&top, "2", DIAMONDS);
// 	add_card_end(&top, "10", SPADES);
// 	add_card_end(&top, "Q", CLUBS);
// 	print_cards_sm(top);

// 	printf(HL HL HL HL HL HL HL HL HL);
// 	printf(HL HL HL HL HL HL HL HL HL);
// 	printf(HL HL HL HL HL HL HL HL HL "\n");

// 	top = NULL;
// 	add_card_front(&top, "A", HEARTS);
// 	add_card_front(&top, "2", DIAMONDS);
// 	add_card_front(&top, "10", SPADES);
// 	// add_card_front(&top, "Q", CLUBS);
//  	add_card(&top, "J", DIAMONDS, 1);
// 	print_cards_sm(top);

// 	return (EXIT_SUCCESS);
// }

card *add_card(card **top, const char *denom, const char *suit, int idx)
{
	card *new = malloc(sizeof(card));
	card *temp = *top;
	int i = 0;

	if (!new)
		return (NULL);

	if (idx >= num_cards(*top))
		add_card_end(top, denom, suit);
	else if (idx <= 0)
		add_card_front(top, denom, suit);
	else
	{
		while (i < idx - 1)
		{
			i++;
			temp = temp->next;
		}
		new->next = temp->next;
		new->prev = temp;
		temp->next->prev = new;//FIXME:
		temp->next = new;
		new->denom = strdup(denom);
		new->suit = strdup(suit);
	}
}

card *add_card_front(card **top, const char *denom, const char *suit)
{
	card *new = malloc(sizeof(card));

	if (!new)
		return (NULL);
		//TODO: copy EXIT_FAILURE from main

	if (*top)
		(*top)->prev = new;

	new->denom = strdup(denom);
	new->suit = strdup(suit);
	new->next = *top;
	new->prev = NULL;

	*top = new;
	return (*top);
}

card *add_card_end(card **top, const char *denom, const char *suit)
{
	card *temp = *top;
	card *new = malloc(sizeof(card));

	if (!new)
		return (NULL);
		//TODO: Copy EXIT_FAILURE from main

	new->denom = strdup(denom);
	new->suit = strdup(suit);
	new->next = NULL;
	new->prev = NULL;

	if (*top == NULL)
	{
		*top = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
	return (new);
}
