#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INIT_SIZE 2

typedef struct {
    int *buffer;
    int top;
    int size;
}Stack;

static Stack *init_stack_helper(void)
{
    Stack *s;
    int *buffer;

    s = (Stack *)malloc(sizeof(Stack));
    if (!s)
        return NULL;

    buffer = (int *)malloc(sizeof(int)*INIT_SIZE);
    if (!buffer) {
        free(s);
        return NULL;
    }
        
    s->top = 0;
    s->buffer = buffer;
    s->size = INIT_SIZE;

    return s;
}

static int isempty_stack_helper(Stack *s)
{
    return s->top == 0;
}

static int isfull_stack_helper(Stack *s)
{
    return s->top == s->size;
}

static int pop_stack_helper(Stack *s)
{
    return s->buffer[--s->top];
}

static void push_stack_helper(Stack *s, int elem)
{
    s->buffer[s->top++] = elem;

    return ;
}

static Stack *init_queue(void)
{
    return init_stack_helper();
}

/* 返回-1， 输出栈不为空&输入栈满了， 不能再进数据了*/
static int appendtail(Stack *input, Stack *output, int elem)
{
    /* 输入栈满 */
    if (isfull_stack_helper(input)) {
        /* 输出栈空 */
        if (isempty_stack_helper(output)) {
            while (!isempty_stack_helper(input))
                push_stack_helper(output, pop_stack_helper(input));
        } else { // 输出栈不为空
            return -1;
        }
    } 

    /* 输入栈未满，继续入栈 */
    push_stack_helper(input, elem);

    return 0;
}

/* 返回-1， 两个栈都没有数据 */
static int deletehead(Stack *input, Stack *output)
{
    /* 输出栈有数据 */
    if (!isempty_stack_helper(output))
        return pop_stack_helper(output);

    /* 输出栈无数据， 但输入栈有数据 */
    if (isempty_stack_helper(output) && !isempty_stack_helper(input)) {
        while (!isempty_stack_helper(input))
            push_stack_helper(output, pop_stack_helper(input));

        return pop_stack_helper(output);
    }

    /* 输入栈也没数据 */
    return -1;
}

/* 打印栈信息 */
static void info(Stack *s, char *string)
{
    int i;

    printf("%s:", string);
    for (i = 0; i < s->top; i++)
        printf("%d ", s->buffer[i]);

    putchar('\n');
}

int main(void)
{
    Stack *in, *out;
    int del, ret;

    in = init_queue();
    out = init_queue();
   
    printf("empty queue testcase:\n");
    del = deletehead(in, out);
    printf(del == -1 ? "empty\n":"del:%d\n", del);
    putchar('\n');

    ret = appendtail(in, out, 1);
    ret = appendtail(in, out, 2);
    printf("appendtail testcase:\n");
    info(in, "in");
    info(out, "out");
    putchar('\n');

    ret = appendtail(in, out, 3);
    ret = appendtail(in, out, 4);
    printf("appendtail testcase:\n");
    info(in, "in");
    info(out, "out");
    putchar('\n');
    
    printf("delete testcase:");
    del = deletehead(in, out);
    printf(del == -1 ? "empty\n":"del:%d\n", del);
    putchar('\n');

    printf("appendtail testcase but in is full and out is not empty:\n");
    ret = appendtail(in, out, 5);
    printf("ret:%d\n", ret);
    info(in, "in");
    info(out, "out");
    putchar('\n');
   
    printf("appendtail testcase and in is full and out is empty:\n");
    del = deletehead(in, out);
    ret = appendtail(in, out, 5);
    printf("ret:%d\n", ret);
    info(in, "in");
    info(out, "out");
    putchar('\n');
    
    return 0;
}
