#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Queue {
    E * array;
    int capacity;
    int rear, front;
};

typedef struct Queue * ArrayQueue;

_Bool initQueue(ArrayQueue queue) {
    queue->array = malloc(sizeof(E) * 10);
    if (queue->array == NULL) return 0;
    queue->capacity = 10;
    queue->rear = queue->front = 0;
    return 1;
}

_Bool offerQueue(ArrayQueue queue, E e) {
    if ((queue->rear + 1) % queue->capacity == queue->front)
        return 0;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = e;
    return 1;
}

_Bool isEmpty(ArrayQueue queue) {
    return queue->front == queue->rear;
}

E pullQueue(ArrayQueue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

int main() {
    struct Queue queue;
    initQueue(&queue);
}