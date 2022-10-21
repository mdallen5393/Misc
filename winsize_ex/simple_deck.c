#include <stdio.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <string.h>

#define ROWS sz.ws_row
#define COLS sz.ws_col


int main(void)
{
    struct winsize sz;
    int i, j;
    ioctl(0, TIOCGWINSZ, &sz);
    char *deck = "|------|";
    int num_cards = 43;
    int len = strlen(deck);

    printf("%d\n", ROWS);
    printf("%d\n", COLS);

    printf("Deck: %s\n%d\n", deck, len);
    printf("---------------------------------\n");
    printf("THIS IS TERRIBLE OUTPUT:\n");
    for (i = 0; i < num_cards; i++)
    {
        printf("%s ", deck);
    }
    printf("\n");

    printf("---------------------------------\n");
    printf("THIS IS CORRECT OUTPUT:\n");

    int cards_per_line = COLS / (len + 1);
    int num_lines = num_cards * (len + 1) / COLS + 1;
    for (i = 0; i < num_lines; i++)
    {
        for (j = 0; j < cards_per_line; j++)
            printf("%s ", deck);
        printf("\n");
    }

    for (i = 0; i < num_cards - cards_per_line * num_lines; i++)
        printf("%s ", deck);
    printf("\n");
}
