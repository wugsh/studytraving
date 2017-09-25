#include <stdio.h>


int target[4][4] = {
    {1, 2, 8, 9},
    {2, 4, 9, 12},
    {4, 7, 10, 13},
    {6, 8, 11, 15},
};

static int dfs_start_rightup(int currx, int curry, int selectelem)
{
    if (currx < 0 || curry > 3 || currx > 3 || curry < 0)
        return 1;

    if (target[currx][curry] == selectelem)
        return 0;

    if (target[currx][curry] < selectelem)
        return dfs_start_rightup(currx+1, curry, selectelem);

    if (target[currx][curry] > selectelem);
        return dfs_start_rightup(currx, curry-1, selectelem);
}

static int __finding_start_rightup(int selectelem)
{
    int startx = 0, starty = 3;

    return dfs_start_rightup(startx, starty, selectelem);
}

static int dfs_start_leftdown(int currx, int curry, int selectelem)
{
    if (currx < 0 || curry > 3 || currx > 3 || curry < 0)
        return 1;

    if (target[currx][curry] == selectelem)
        return 0;

    if (target[currx][curry] < selectelem)
        return dfs_start_leftdown(currx, curry+1, selectelem);

    if (target[currx][curry] > selectelem);
        return dfs_start_leftdown(currx-1, curry, selectelem);
}

static int __finding_start_leftdown(int selectelem)
{
    int startx = 3, starty = 0;

    return dfs_start_leftdown(startx, starty, selectelem);
}

static int finding(int selectelem)
{
   return  __finding_start_leftdown(selectelem);
}

int main(void)
{
    printf(!finding(8) ? "found!\n" : "not found!\n");
    printf(!finding(15)? "found!\n" : "not found!\n");
    printf(!finding(1)? "found!\n" : "not found!\n");
    printf(!finding(20)? "found!\n" : "not found!\n");

    return 0;
}
