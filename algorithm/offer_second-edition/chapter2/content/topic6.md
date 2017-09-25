## topic6 从尾到头打印链表

#### 描述

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;输入一个链表的头节点，从尾到头反过来打印每个节点的的值，链表的节点定义如下：

~~~
struct Listnode {
    int Key;
    struct Listnode *next;
};
~~~

#### 思路

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;遍历的顺序是从头到尾，可输出的顺序却是从尾到头。也就是说，第一个遍历到的节点最后一
个输出，而最后一个遍历到的节点第一个输出。由此可知，是个先进后出的顺序。

- <a href="../src/topic6.c">栈</a>
- <a href="../src/topic6.c">递归</a>

#### 总结

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;当链表非常长的时候，就会导致函数调用层级很深，从而有可能导致函数调用栈溢出。
