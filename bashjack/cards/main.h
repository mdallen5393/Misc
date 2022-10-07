#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macros (Suits) */
/* Suits */
#define HEARTS "\u2665"
#define CLUBS "\u2663"
#define SPADES "\u2660"
#define DIAMONDS "\u2666"

/* Card Borders */
#define HL "\u2500"
#define VL "\u2502"
#define TL "\u250C"
#define TR "\u2510"
#define BL "\u2514"
#define BR "\u2518"

/* Structs & Typedefs */
typedef struct card_s {
	char *denom; //denomination - card number/letter
	char *suit;
	struct card_s *next;
	struct card_s *prev;
} card;

/* Function Prototypes */
size_t print_cards(const card *hand);
size_t print_cards_sm(const card *hand);
size_t num_cards(const card *hand);
card *add_card(card **top, const char *denom, const char *suit, int idx);
card *add_card_front(card **top, const char *denom, const char *suit);
card *add_card_end(card **top, const char *denom, const char *suit);
void free_cards(card *top);
card *get_card_at_idx(card *top, unsigned int index);
int delete_card_at_idx(card **top, unsigned int index);
int move(card *src, int src_idx, card *dest, int dest_idx);


#endif
