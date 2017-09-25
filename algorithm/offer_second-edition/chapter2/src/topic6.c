#include <stdio.h>
#include <stdlib.h>

int arr_data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

struct Listnode {
    union {
        int key;
        int cnt;
    };
    struct Listnode *next;
};

typedef struct {
    int *buffer;
    int top;
}Stack;

static Stack *init_stack_helper(struct Listnode *head)
{
    Stack *s;
    int *buffer;
    
    s = (Stack *)malloc(sizeof(*s));
    if (!s)
        return NULL;

    buffer = malloc(sizeof(int)*(head->cnt));
    if (!buffer)
        return NULL;

    s->buffer = buffer;
    s->top = 0;

    return s;
}

static void push_helper(Stack *s, struct Listnode *node)
{
    s->buffer[s->top++] = node->key;
}

static int pop_helper(Stack *s)
{
    return s->buffer[--s->top];
}

static void delete_stack_helper(Stack *s)
{
    free(s->buffer);
    free(s);
}

static void insert(struct Listnode *head)
{
    struct Listnode *node, *pos = head;
    int i;

    for (i = 0; i < 10; i++) {
        
        node = malloc(sizeof(struct Listnode *));
        if (!node)
            break;
        node->key = arr_data[i];
        node->next = NULL;

        pos->next = node;
        pos = node;
        head->cnt++;
    }

    return ;
}

static struct Listnode *create(void)
{
    struct Listnode *head;

    head = malloc(sizeof(struct Listnode));
    if (!head)
        return NULL;
    
    head->cnt = 0;
    head->next = NULL;

    insert(head);
    return head;
}

static void dfs(struct Listnode *node)
{
    if (!node)
        return ;

    dfs(node->next);
    printf("%d ", node->key);

    return ;
}

static void loop(struct Listnode *head)
{
    int i;
    Stack *s;
    struct Listnode *pos = head->next;

    s = init_stack_helper(head);
    if (!s)
        return ;

    for (i = 1; i <= head->cnt; i++) {
        push_helper(s, pos);
        pos = pos->next;
    }

    while (s->top) {
        printf("%d ", pop_helper(s));
    }

    delete_stack_helper(s);
    return ;
}

static void print_reversal_list(struct Listnode *head)
{
    struct Listnode *firstnode = head->next;
   
    if (!firstnode) {
        printf("this is a empty list\n");
        return ;
    }

    //dfs(firstnode);
    loop(head);
    putchar('\n');

    return ;
}

int main(void)
{
    struct Listnode *head;

    head = create();
    if (!head)
        return 1;

    printf("head info: %d\n", head->cnt);
    print_reversal_list(head);
    return 0;
}
