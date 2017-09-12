#include <stdio.h>

union {
    int a;
    long b;
}big_little;

int main(void)
{
    long val = 1;

    big_little.b = val << 32;

    printf("int size:%dB\nlong size:%dB\nunion size:%dB\n", 
            (int)sizeof(int), (int)sizeof(long), (int)sizeof(big_little));
    printf("b val:0x%lx\n", big_little.b);
    printf("a val:0x%x\n", big_little.a);

    return 0;
}
