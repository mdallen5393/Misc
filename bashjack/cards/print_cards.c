#include <stdio.h>

void print_card(char *num, char *suit);
void print_small(char *num, char *suit);

int main(void)
{

	printf("Ace of Hearts\n");
	print_card("A", HEARTS);
	print_small("A", HEARTS);

	printf("\nTen of Clubs\n");
	print_card("10", CLUBS);
	print_small("10", CLUBS);

	printf("\nQueen of Spades\n");
	print_card("Q", SPADES);
	print_small("Q", SPADES);

	printf("\nTwo of Diamonds\n");
	print_card("2", DIAMONDS);
	print_small("2", DIAMONDS);

	return (0);
}

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

/* 
 *	printf("\u2660\n");
 *	printf("\u2663\n");
 *	printf("\u2665\n");
 *	printf("\u2666\n");
 */

/* small cards
	***
	*A*
	***

	***
	*A*
	***
 */
