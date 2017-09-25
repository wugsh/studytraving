#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char textcase[6][20] = {
    "we are happy",
    "we  are happy",
    "we are happy ",
    " we are happy",
    "             ",
    "",
};

char replace[] = "%20";

static int total_whiteblocks(char *currcase)
{
    int cnt = 0;
    char *pos = currcase;

    while(*pos != '\0') {
        if (*pos == ' ')
            cnt++;

        pos++;
    }

    return cnt;
}

int main(void)
{
    return 0;
}
