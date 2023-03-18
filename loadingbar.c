#include <stdio.h>
#include "loadingbar.h"

struct LoadingBar loadingbar_init(int max, char Fill, char Empty, char left, char right)
{
    struct LoadingBar bar;

    bar.curLen = 0;
    bar.maxLen = max;
    bar.percent = 0;

    bar.fill = Fill;
    bar.empty = Empty;

    bar.leftCap = left;
    bar.rightCap = right;

    return bar;
}

void loadingbar_draw(struct LoadingBar *bar)
{
    // move to start of line and print left cap char
    printf("\r%c", bar->leftCap);

    if (bar->curLen > bar->maxLen)
        bar->curLen = bar->maxLen;

    if (bar->percent > 100)
        bar->percent = 100;

    printf("%d%% ", bar->percent);

    for (int i = 0; i < bar->curLen; i++)
        printf("%c", bar->fill);

    int diff = bar->maxLen - bar->curLen;
    for (int i = 0; i < diff; i++)
        printf("%c", bar->empty);

    printf("%c", bar->rightCap);
    
    fflush(stdout);
}