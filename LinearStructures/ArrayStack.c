#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack {
    E * array;
    int capacity;
    int top;        //栈顶，存下标
};

typedef struct Stack * ArrayStack;

_Bool initStack(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * 10);
    if (stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;        //没有元素，默认-1，0是第一个元素
    return 1;
}

_Bool pushStack(ArrayStack stack, E element) {          //入栈
    if (stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + stack->capacity >> 1;
        E * newArray = realloc(stack->array, newCapacity * sizeof(E));
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
    return 1;
}

_Bool isEmpty(ArrayStack stack) {           //判断栈是否为空，空还出啥
    return stack->top == -1;
}

E popStack(ArrayStack stack) {          //出栈
    return stack->array[stack->top--];
}


void printStack(ArrayStack stack) {
    printf("| ");
    for (int i = 0; i < stack->top + 1; i++) {
        printf("%d, ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);
    for (int i = 0; i < 3; ++i) {
        pushStack(&stack, i * 100);
    }
    printStack(&stack);
    while (!isEmpty(&stack)) {
        printf("%d ", popStack(&stack));
    }
}