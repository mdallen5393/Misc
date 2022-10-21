#include <stdio.h>
#include <sys/ioctl.h>
#include <signal.h>

struct winsize sz;

void redraw(int signum)
{
    int i;
    printf("\e[2J");
    ioctl(0, TIOCGWINSZ, &sz);
    int limit = sz.ws_row * sz.ws_col;
    for (i = 0; i < limit; i++)
        putchar('+');
}

int main(int argc, char **argv)
{
    signal(SIGWINCH, redraw);
    redraw(SIGWINCH);
    return (0);
}