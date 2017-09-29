#include <stdio.h>
#include <stdlib.h>


char path[3][5] = {
    "abtg",
    "cfcs",
    "jdeh",
};

int book[3][5];

char *pathstring = "bfcg";

int direct[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

static int dfs(int currx, int curry, int currstep)
{
    int nextx, nexty;
    int i;


    if (currx < 0 || currx > 3 || curry < 0 || curry > 3)
        return 0;

    if (book[currx][curry] == 1)
        return 0;

    if (path[currx][curry] != *(pathstring+currstep))
        return 0;
    
    book[currx][curry] = 1;
      
    if (currstep == 3){
        printf("successed\n");
        return 1;
    }
    for (i = 0; i < 4; i++) {
        
        nextx = currx+direct[i][0];
        nexty = curry+direct[i][1];
        if (dfs(nextx, nexty, currstep+1))
            return 1;
    }

    /* 当前节点的四周遍历结束仍没有合适节点， 返回到上一个节点*/
    book[currx][curry] = 0;
    return 0;
}

static int matching_path(int startx, int starty)
{
    int step = 0;

    return dfs(startx, starty, step);
}

int main(void)
{
    int startx = 0, starty = 1;
    int ret;

    ret = matching_path(startx, starty);
    printf("%d\n", ret);
    return 0;
}
