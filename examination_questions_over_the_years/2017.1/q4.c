#include <stdio.h>

enum {
    ERROR,
    OK
};

typedef int KeyType;

typedef struct QNode {
    KeyType data;
    struct QNode *next;
} QNode, *LinkQueue;

typedef struct {
    int size;
    LinkQueue rear;
} Queue;

// 函数EnQueue（Queue *Q，KeyType new_elem） 的功能是将元素new_elem加入队尾。
int EnQueue(Queue *Q, KeyType new_elem) {
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    if (!p) {
        return ERROR;
    }

    p -> data = new_elem;

    if (Q -> rear) {
        // 如果有头节点
        p -> next = Q -> rear -> next;
        // (1) rear也是QNode类型
        Q -> rear -> next = p;
    } else {
        // 保证循环结构
        p -> next = p;
        // (2)
        Q -> rear = p;
    }

    Q -> size++;

    return OK;
}

// 函数DnQueue（Queue *Q，KeyType *elem）的功能使将非空队列的队头元素出队（从队列中删除），
// 并通过参数带回刚出队的元素。
int DeQueue(Queue *Q, KeyType *elem) {
    QNode *p;

    if (Q -> size == 0) {
        return ERROR;
    }

    // p = (3);
    p = Q -> rear -> next;
    *elem = p -> data;
    // Q -> rear -> next = (4);
    Q -> rear -> next = Q -> rear -> next -> next;

    // if ((5)) {
    if (Q -> rear -> next == p) {
        // 被删的节点是唯一节点
        Q -> rear = NULL;
    }

    free(p);
    Q -> size--;
    return OK;
}