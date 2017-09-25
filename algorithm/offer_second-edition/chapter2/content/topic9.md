## topic9 用两个栈实现队列

#### 描述

用两个栈实现一个队列，并实现他的两个函数：appendtail和deletehead,分别完成在队列尾部插入节点和在队列头部删除节点的功能。

#### 分析

- 需要两个栈组合才能实现“先进进出”的队列，一个输入栈，用于缓冲输入的数据， 一个输出栈，用于输入数据。
- appendtail : 完成在队列尾部插入节点的功能。
  - 输入栈满，1. 输出栈空 2.输出栈不为空
  - 输入栈未满
- deletehead : 完成在队列头部删除节点的功能。
  - 输出栈不为空
  - 输出栈空，但输入栈不为空
  - 输入栈和输出栈都为空。

#### 代码

<a href="..src/topic9.c">源代码</a>

#### 附录

#### 栈

栈实现的是一种先进后出的策略。栈所有的操作只改变栈顶元素，类似与垒盘子。

##### 数据结构

~~~
typedef struct {
    elemType buffer[STACK_SIZE];  //栈的缓冲区
    int top; // 永远指向栈顶
}Stack;
~~~

##### 基本操作

~~~
//初始化操作，主要是初始化缓冲区，和栈顶指针。
Stack *init_stack(void)  

//出栈， 删除栈顶的元素,返回栈顶元素。
elemType pop(Stack *s)

//入栈（压栈）。
void push(Stack *s)

//返回栈顶元素，但不删除栈顶元素
elemType top(Stack *s)

//判断是否栈上溢(overflow),返回1上溢。
int isfull(Stack *s)

//判断是否栈下溢(underflow),即栈为空，返回1下溢。
int isempty(Stack *s)
~~~

#### 队列

队列实现的是一种先进先出的策略。入队只在队尾添加元素，出队只在对首删除元素，类似与生活中排队。

##### 数据结构

~~~
typedef struct {
    elemType buffer[QUEUE_SIZE];  //队列的缓冲区。
    int head, tail; // head指向对首，tail指向队尾。
}Qeueu;
~~~

##### 基本操作
~~~
//初始化操作，主要是初始化缓冲区，和对首队尾指针。
Stack *init_queue(void)  

//出队， 删除对首的元素,改变对首指针，返回队首元素。
elemType dequeue(Queue *q)

//入队，添加队尾元素，改变队尾指针。
void enqueue(Queue *q)

//判断是否队满,返回1队满。
int isfull(Stack *s)

//判断是否队空，返回1队空。
int isempty(Stack *s)
~~~
