#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initStack(Node head) {
    head->next = NULL;
}

_Bool pushStack(Node head, E element) {
    Node newNode = malloc(sizeof(struct ListNode));
    if (newNode == NULL) return 0;
    newNode->next = head->next;
    newNode->element = element;
    head->next = newNode;
}

_Bool isEmpty(Node head) {
    return head->next == NULL;
}

E popStack(Node head) {
    Node top = head->next;
    head->next = top->next;
    E e = top->element;
    free(top);
    return e;
}

void printStack(Node head){
    printf("| ");
    head = head->next;
    while (head){
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode head;
    initStack(&head);
    for (int i = 0; i < 3; ++i) {
        pushStack(&head, i*100);
    }
    printStack(&head);
    while (!isEmpty(&head)) {
        printf("%d ", popStack(&head));
    }
}