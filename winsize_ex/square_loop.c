#include <stdio.h>
#include <sys/ioctl.h>
#include <signal.h>

    signal(SIGWINCH, redraw);
    redraw(SIGWINCH);

void redraw(int signum)
{
    int i;
    printf("\e[2J");
    ioctl(0, TIOCGWINSZ, &sz);

    for (int i = 0; i < sz.ws_col; i++)
        putchar('.');
    putchar('\n');

    for (int i = 3; i < sz.ws_row; i++)
    {
        printf(".");
        for (int j = 2; j < sz.ws_col; j++)
            putchar(' ');
        printf(".");
    }

    for (int i = 0; i < sz.ws_col; i++)
        putchar('.');
    putchar('\n');

}

int main(void)
{
    struct winsize sz;
    ioctl(0, TIOCGWINSZ, &sz);
    // printf("%d\n", sz.ws_row);
    // printf("%d\n", sz.ws_col);

}




