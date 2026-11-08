#include <stdio.h>
#include <stdlib.h>


typedef int E;

struct Lnode {
    E element;
    struct Lnode * next;
};

typedef struct Lnode * Node;

struct Queue {
    Node front, rear;
};

typedef struct Queue * Linkedqueue;

_Bool initQueue(Linkedqueue queue) {
    Node node = malloc(sizeof(struct Lnode));
    if (node == NULL) return 0;
    node->next = NULL;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(Linkedqueue queue, E e) {
    Node node = malloc(sizeof(struct Lnode));
    if (node == NULL) return 0;
    node->next = NULL;
    node->element = e;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isEmpty(Linkedqueue queue) {
    return queue->front == queue->rear;
}

E pollQueue(Linkedqueue queue) {
    E e = queue->front->next->element;
    Node node = queue->front->next;             //queue->front->next是第一个元素位置,node是出队
    queue->front->next = node->next;
    if (queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}

void printqueue(Linkedqueue queue) {
    printf("<<<");
    Node node = queue->front->next;
    while (1) {
        printf("%d ", node->element);
        if (node->next == NULL) break;
        else node = node->next;
    }
    printf("<<<\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 1; i <= 5; i++) {
        offerQueue(&queue, i * 100);
    }
    printqueue(&queue);
    while (!isEmpty(&queue)){
        printf("%d ", pollQueue(&queue));
    }
}