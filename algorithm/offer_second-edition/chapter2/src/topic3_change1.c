#include <stdio.h>

#define MAXLIMIT 10
#define COL MAXLIMIT+1
#define ROW 3

int testcase[ROW][COL] = {
    {1, 2, 10, 3, 9, 8, 5, 6, 4, 7, 1},
    {3, 2, 1, 3, 9, 8, 6, 5, 4, 4, 10},
    {10, 2, 1, 1, 3, 4, 5, 6, 7, 7, 3},
};


static int totalcnt(int *currline, int min, int max)
{
    int precnt = 0;
    int delta = max - min;
    int mid = min + delta / 2;
    int i;

    if (!delta)
        return max;

    for (i = 0; i < COL; i++) {
        if (min <= *(currline+i) && mid >= *(currline+i))
            precnt++;
    }

    if (precnt != (mid-min+1))
        return totalcnt(currline, min, mid);
    
    return  totalcnt(currline, min+1, max);
}

int main(void)
{
    int i, ret;

    for (i = 0; i < ROW; i++) {
        ret = totalcnt(testcase[i], 1, MAXLIMIT);
        printf("the repeative element:%d\n", ret);
    }
    return 0;
}
