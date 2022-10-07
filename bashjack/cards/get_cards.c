#include "main.h"

// int main(void)
// {
// 	card *top;
// 	card *cardToFind;

// 	printf("TESTING get_card_at_idx FUNCTION\n");

// 	top = NULL;
// 	add_card_end(&top, "A", HEARTS);
// 	add_card_end(&top, "2", DIAMONDS);
// 	add_card_end(&top, "10", SPADES);
// 	add_card_end(&top, "Q", CLUBS);
// 	print_cards(top);

// 	cardToFind = get_card_at_idx(top, 3);
// 	printf("Card 3: %s of %s\n", cardToFind->denom, cardToFind->suit);
// 	cardToFind = get_card_at_idx(top, 2);
// 	printf("Card 2: %s of %s\n", cardToFind->denom, cardToFind->suit);
// 	cardToFind = get_card_at_idx(top, 1);
// 	printf("Card 1: %s of %s\n", cardToFind->denom, cardToFind->suit);
// 	cardToFind = get_card_at_idx(top, 0);
// 	printf("Card 0: %s of %s\n", cardToFind->denom, cardToFind->suit);
// 	cardToFind = get_card_at_idx(top, 200);
// 	if (cardToFind)
// 		printf("Card 200: %s of %s\n", cardToFind->denom, cardToFind->suit);
// 	else
// 		printf("Card 200: does not exist\n");
// 	free_cards(top);
// 	top = NULL;

// 	return (EXIT_SUCCESS);
// }

card *get_card_at_idx(card *top, unsigned int index)
{
	unsigned int i = 0;
	card *temp = top;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	if (index > i)
		return (NULL);

	return (temp);
}

int build_deck(card *top)
{
	add_to_deck(*top, HEARTS);
	add_to_deck(*top, CLUBS);
	add_to_deck(*top, SPADES);
	add_to_deck(*top, DIAMONDS);
	return (0)
}

int add_to_deck(card *top, const char *suit)
{
	int i;

	add_card_end(&top, "A", suit)
	for (i = 2; i <= 10; i++)
		add_card_end(&top, itoa(i), suit)
	add_card_end(&top, "J", suit)
	add_card_end(&top, "Q", suit)
	add_card_end(&top, "K", suit)
}
