#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initList(Node node) {
    node->next = NULL;
}

_Bool insertList(Node head, E element,int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }

    Node node = (Node) malloc(sizeof(*node));
    if (node == NULL) return 0;
    node->element = element;
    node->next = head->next;
    head->next = node;
    return 1;
}

_Bool deleteList(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;

    Node tmp = head->next;
    head->next = tmp->next;
    free(tmp);
    return 1;
}

E * getList(Node head, int index) {
    if (index < 1) return NULL;
    do {
        head = head->next;
        if (head == NULL) return NULL;
    }while (--index);
    return &head->element;
}

int findList(Node head, E element) {
    head = head->next;
    int index = 1;
    while (head) {
        if (head->element == element) return index;
        head = head->next;
        index++;
    }
    return -1;
}

int sizeList(Node head) {
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

int main() {
    struct ListNode head;
    initList(&head);
    insertList(&head,10,1);
    insertList(&head,20,2);
    insertList(&head,30,3);
    int size = sizeList(&head);
    printf("链表长度：%d\n", size);
    int index = findList(&head, 20);
    printf("查找结果：%d\n", index);
    E *p = getList(&head, 2);
    if (p != NULL) {
        printf("第二个元素：%d\n", *p);
    }
}