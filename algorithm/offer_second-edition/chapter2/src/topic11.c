#include <stdio.h>

#define ROW 7
#define COL 10

int testcase[ROW][COL] = {
    {5, 6, 7, 8, 9, 10, 1, 2, 3, 4},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 1},
    {10, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
    {5, 6, 7, 7, 1, 2, 2, 3, 3, 4},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
};

int testcaseonlyone[1] = {1};

static void info_arr(int *arr)
{
    int i;

    for (i = 0; i < COL; i++) {
        printf("%d ", *(arr+i));
    }
    putchar('\n');
}

static int sequeue_search(int start, int end, int *arr)
{
    int i = start;

    while (i < end) {
        if (*(arr+i) > *(arr+i+1))
            break;
        
        i++;
    }

    if (i == end)
        return end;

    return i+1;
}

static int binary_search(int start, int end, int *arr)
{
    int mid = (start + end) / 2;

    if (*(arr+start) == *(arr+mid) && *(arr+start) == *(arr+end))
        return sequeue_search(start, end, arr);

    if (end - start == 1)
        return end;

    if (*(arr+start) <= *(arr+mid))
        return binary_search(mid, end, arr);

    return binary_search(start, mid, arr);
}

int findingmin(int *currcase, int size)
{
    return binary_search(0, size-1, currcase);
}

int main(void)
{
    int i;
    int minvalueid;

    for (i = 0; i < ROW; i++) {
        printf("%d case:", i);
        info_arr(testcase[i]);

        minvalueid = findingmin(testcase[i], COL);
        printf("minvalue:%d\n", *(testcase[i]+minvalueid));
    }

    minvalueid = findingmin(testcaseonlyone, 1);
    printf("onlyone minvalue:%d\n", *(testcaseonlyone+minvalueid));
    return 0;
}
