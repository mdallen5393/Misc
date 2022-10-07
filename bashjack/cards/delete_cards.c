#include "main.h"

// int main(void)
// {
// 	card *top;

// 	printf("TESTING free_cards FUNCTION\n");
// 	top = NULL;
// 	add_card_end(&top, "A", HEARTS);
// 	add_card_end(&top, "2", DIAMONDS);
// 	add_card_end(&top, "10", SPADES);
// 	add_card_end(&top, "Q", CLUBS);
// 	print_cards_sm(top);
// 	free_cards(top);
// 	top = NULL;
// 	return (EXIT_SUCCESS);
// }

// int main(void)
// {
// 	card *top = NULL;

// 	printf("TESTING delete_card_at_idx FUNCTION\n");
// 	add_card_end(&top, "A", HEARTS);
// 	add_card_end(&top, "2", DIAMONDS);
// 	add_card_end(&top, "10", SPADES);
// 	add_card_end(&top, "Q", CLUBS);
// 	print_cards_sm(top);
// 	printf("-----------------\n");
// 	delete_card_at_idx(&top, 2);
// 	print_cards_sm(top);
// 	printf("-----------------\n");
// 	delete_card_at_idx(&top, 0);
// 	print_cards_sm(top);
// 	printf("-----------------\n");
// 	delete_card_at_idx(&top, 0);
// 	print_cards_sm(top);
// 	printf("-----------------\n");
// 	delete_card_at_idx(&top, 0);
// 	print_cards_sm(top);
// 	printf("-----------------\n");
// 	delete_card_at_idx(&top, 0);
// 	printf("-----------------\n");
// 	delete_card_at_idx(&top, 0);
// 	printf("-----------------\n");
// 	print_cards_sm(top);
// 	top = NULL;
// 	return (0);
// }

void free_cards(card *top)
{
	card *temp = top;

	while (temp)
	{
		temp = temp->next;
		free(top->denom);
		free(top->suit);
		free(top);
		top = temp;
	}

	free(temp);
}

int delete_card_at_idx(card **top, unsigned int index)
{
	card *temp;
	card *cardToDelete;
	unsigned int i = 0;

	if (*top == NULL || top == NULL)
		return (-1);

	temp = *top;
	if (index == 0)
	{
		if (temp->next)
		{
			*top = temp->next;
			(*top)->prev = NULL;
		}
		else
			*top = NULL;

		free(temp->denom);
		free(temp->suit);
		free(temp);
		return (1);
	}

	while (temp && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	if (!temp)
		return (-1);

	cardToDelete = temp->next;
	temp->next = cardToDelete->next;

	if (cardToDelete->next)
		cardToDelete->next->prev = temp;

	free(cardToDelete->denom);
	free(cardToDelete->suit);
	free(cardToDelete);

	return (1);
}
