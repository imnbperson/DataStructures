#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

void initList(Node node) {          //初始化 
    node->next = NULL;
}

_Bool insertList(Node head, E element, int index) {         //插入
    if (index < 1) return 0;        //限制左边界
    while (--index) {           //寻找前驱节点，先减在循环
        head = head->next;
        if (head == NULL) return 0;         //限制右边界
    }

    Node node = malloc(sizeof(struct ListNode));        //创建新结点
    if (node == NULL) return 0;         //常规检查
    node->element = element;
    node->next = head->next;        //指向下一个结点
    head->next = node;          //前驱结点指向新节点
    return 1;
}

_Bool deleteList(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;           //寻找前驱结点

    Node tmp = head->next;          //head->next 是要删除的结点，先存他的地址
    head->next = head->next->next;      //让前驱结点保存所删结点所指地址
    free(tmp);          //因为存的是struct ListNode 类型指针，所以直接释放，结点就没了
    return 1;
}

E * getList(Node head, int index) {
    if (index < 1) return NULL;
    do {
        head = head->next;
        if (head == NULL) return NULL;          //限制边界
    }while (--index);
    return &head->element;
}

int findList(Node head, E element) {
    head = head->next;
    int i = 1;
    while (head) {
        if (head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}

int sizeList(Node head) {
    int i = -1;         //因为head走到空才结束，所以是i=-1而不是0
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}


