#include <stdio.h>

#define COL 10
#define ROW 4

#ifndef DEBUG 
#define DEBUG 0
#endif

int testcase[ROW][COL] = {
    {0, 2, 1, 3, 9, 8, 5, 6, 4, 7},
    {0, 2, 1, 3, 9, 8, 6, 5, 4, 4},
    {0, 2, 1, 1, 3, 4, 5, 6, 7, 7},
    {3, 22},
};

#if DEBUG
static void print_arr(int *currline, char *prefix)
{
    int i;

    printf("%s", prefix);
    for (i = 0; i < COL; i++)
        printf("%d ", *(currline+i));
    putchar('\n');

    return ;
}
#endif

static void isrepeated(int *a)
{
    int repeated = 0;
    int i, m, tmp;

    for (i = 0; i < COL; i++) {
        
        for( ; ; ) {
            m = a[i];
            
            if (m == i) {
                break;
            } else if (a[m] == a[i]) {
                repeated = 1;
                break;
            } else {
                tmp = a[i];
                a[i] = a[m];
                a[m] = tmp;
            }
        }

        if (repeated == 1)
            break;
    }

    printf(!repeated ? "This testcase do not exist the repeative element\n" : "the repeative element is %d\n", m);

    return ;
}

static int check(int *currline)
{
    int i;

    if (!currline)
        return 0;

    for (i = 0; i < COL; i++) {
        if (*(currline+i) >= COL || *(currline+i) < 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    int i;

    for (i = 0; i < ROW; i++) {
#if DEBUG
        print_arr(testcase[i], "origin: ");
#endif

        if (!check(testcase[i])) {
#if DEBUG
            printf("error\n");
#endif
            continue;
        } else {
#if DEBUG
            printf("right\n");
#endif
        } 
        isrepeated(testcase[i]);

#if DEBUG
        print_arr(testcase[i], "result: ");
#endif
        putchar('\n');
    }
    return 0;
}
