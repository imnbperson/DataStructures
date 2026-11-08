#include <stdio.h>
#include <stdlib.h>

/*初始化1
插入
 扩容
删除*/
//两获取一查找

typedef int E;

struct List {
    E * array;
    int size;
    int capacity;
};

_Bool initList(struct List * list) {
    list->array = malloc(sizeof(E) * 10);
    if (list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool insertList(struct List * list, E element, int index) {      //index 位序 1 2 3...
    if (index < 1 || index > list->size + 1) return 0;

    if (list->size == list->capacity) {             //扩容
        int newCapacity = list->capacity + (list->capacity >> 1);
        E * newArray = realloc(list->array, newCapacity * sizeof(E));
        if (newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1; --i) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return 1;
}

_Bool deleteList(struct List * list, int index) {
    if (index < 1 || index > list->size) return 0;

    for (int i = index - 1; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return 1;
}

int sizeList(struct List * list) {
    return list->size;
}

E * getList(struct List * list, int index) {
    if (index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

int findList(struct List * list, E element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i + 1;
    }
    return -1;
}

int main() {
    struct List list;
    if (initList(&list)) {
        printf("成功初始化\n");
        if (insertList(&list, 10, 1)) {
            printf("插入成功\n");
        } else {
            printf("插入失败\n");
        }
        insertList(&list, 20, 2);
        insertList(&list, 30, 3);
        for (int i = 0; i < list.size; i++) {
            printf("%d ", list.array[i]);
            if (i == list.size - 1) {
                printf("\n");
            }
        }
        printf("元素数量为%d\n", sizeList(&list));
        E *p = getList(&list, 2);
        if (p != NULL) {
            printf("第2个元素是%d\n", *p);
        } else {
            printf("获取元素失败\n");
        }
        printf("20是第%d个元素\n", findList(&list, 20));
    }
    else {
        printf("初始化失败\n");
    }
}