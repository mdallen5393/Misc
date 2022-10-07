#include "main.h"

// int main(void)
// {
// 	card *deck = NULL;
// 	card *hand = NULL;

// 	printf("DECK:\n");
// 	add_card_end(&deck, "A", HEARTS);
// 	add_card_end(&deck, "2", DIAMONDS);
// 	add_card_end(&deck, "3", SPADES);
// 	add_card_end(&deck, "4", CLUBS);
// 	print_cards_sm(deck);

// 	printf(HL HL HL HL HL HL HL HL HL);
// 	printf(HL HL HL HL HL HL HL HL HL);
// 	printf(HL HL HL HL HL HL HL HL HL "\n");

// 	printf("\nHAND:\n");
// 	add_card_end(&hand, "5", HEARTS);
// 	print_cards_sm(hand);
// 	move(deck, 3, hand, 1);
// 	print_cards_sm(hand);
// 	move(deck, 2, hand, 2);
// 	print_cards_sm(hand);
// 	move(deck, 1, hand, 3);
// 	print_cards_sm(hand);
// 	move(deck, 0, hand, 4);
// 	print_cards_sm(hand);
// }

int move(card *src, int src_idx, card *dest, int dest_idx)
{
	card *selection = get_card_at_idx(src, src_idx);
	add_card(&dest, selection->denom, selection->suit, dest_idx);
	delete_card_at_idx(&src, src_idx);
	return (0);
}
