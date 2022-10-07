#include "main.h"

void print_card(char *num, char *suit);
void print_small(char *num, char *suit);

// int main(void)
// {

// 	printf("Ace of Hearts\n");
// 	print_card("A", HEARTS);
// 	print_small("A", HEARTS);

// 	printf("\nTen of Clubs\n");
// 	print_card("10", CLUBS);
// 	print_small("10", CLUBS);

// 	printf("\nQueen of Spades\n");
// 	print_card("Q", SPADES);
// 	print_small("Q", SPADES);

// 	printf("\nTwo of Diamonds\n");
// 	print_card("2", DIAMONDS);
// 	print_small("2", DIAMONDS);

// 	return (0);
// }

void print_card(char *num, char *suit)
{
	printf("********** \n");

	if (num[1] == '0')
		printf("* %s     * \n", num);
	else
		printf("* %s      * \n", num);
	
	printf("*        * \n");
	printf("*        * \n");
	printf("*   %s    * \n", suit);
	printf("*        * \n");
	printf("*        * \n");
	
	if (num[1] == '0')
		printf("*     %s * \n", num);
	else
		printf("*      %s * \n", num);
	
	printf("********** \n");
}

//LINKED LIST VERSION:
size_t print_cards(const card *hand)
{
	const card *temp = hand;
	int numCards = 0;

	// for (i = 0; i < 7; i++)
	// {
		while (temp)
		{
			printf("********** \n");

			if (temp->num[1])
				printf("* %s     * \n", temp->num);
			else
				printf("* %s      * \n", temp->num);

			printf("*        * \n");
			printf("*        * \n");
			printf("*   %s    * \n", temp->suit);
			printf("*        * \n");
			printf("*        * \n");

			if (temp->num[1])
				printf("*     %s * \n", temp->num);
			else
				printf("*      %s * \n", temp->num);

			printf("********** \n");

			numCards++;
			temp = temp->next;
		}
	// }

	return (numCards);
}

void print_small(char *num, char *suit)
{
	printf("**** \n");

	if (num[1] == '0')
		printf("*10* \n");
	else
		printf("*%s * \n", num);
	
	printf("* %s* \n", suit);

	printf("**** \n");
}

void smcardstr(char **card, char *num, char *suit)
{
	sprintf(card[0], "**** ");
	
	if (num[1] == '0')
		sprintf(card[1], "*10* ");
	else
		sprintf(card[1], "*%s * ", num);

	sprintf(card[2], "* %s* ", suit);
	sprintf(card[3], "**** ");
}

void cardstr(char **card, char *num, char* suit)
{
	int i;

	// malloc for each line in the card
	for (i = 0; i < 7; i++)
		card[i] = malloc(sizeof(char) * 12);

	sprintf(card[0], "********** ");

	// if num = 10, it is 2 digits long
	if (num[1])
		sprintf(card[1], "* %s     * ", num);
	else
		sprintf(card[1], "* %s      * ", num);

	sprintf(card[2], "*        * ");
	sprintf(card[3], "*    %s   * ", suit);
	sprintf(card[4], "*        * ");

	//same check as above for num = 10
	if (num[1])
		sprintf(card[5], "*     %s * ", num);
	else
		sprintf(card[5], "*      %s * ", num);

	sprintf(card[6], "********** ");
}

char **new_hand(char *hand[7], int handsize)
{
	int i;
	hand = malloc(sizeof(card) * handsize);

	return (hand);
}

void print_hand(char **hand)
{
	int i;

	for (i = 0; i < 7; i++)
		printf("%s\n", hand[i]);
}

/* main - for testing only */
int main(void)
{
	char *Ace[7];
	int i;
	int handsize = 5;

	char **hand = new_hand(hand, handsize);

	cardstr(Ace, "A", HEARTS);
	
	for (i = 0; i < 7; i++)
		printf("%s\n", Ace[i]);

	print_hand(hand);
}
