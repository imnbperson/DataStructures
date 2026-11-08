#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct List {
    E * array;
    int capacity;
    int size;
};

typedef struct List * ArrayList;

_Bool initList(ArrayList list) {        //初始化
    list->array = malloc(sizeof(E) * 10);       //分配内存
    if (list->array == NULL) return 0;          //检测是否成功
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool insertList(ArrayList list, E element, int index) {        //插入
    if (index < 1 || index > list->size + 1) return 0;          //判定

    if (list->size == list->capacity) {         //扩容
        int newCapacity = list->capacity + (list->capacity >> 1);
        E * newArray = realloc(list->array, newCapacity * sizeof(E));       //怕重新分配不成功
        if (newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }

    for (int i = list->size; i > index - 1; i--) {          //把前一项搬到后一项
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;       //正式插入
    list->size++;
    return 1;
}

_Bool deleteList(ArrayList list, int index) {           //删除
    if (index < 1 || index > list->size) return 0;          //判定
    for (int i = index - 1; i < list->size - 1; ++i) {          //把后一项搬到前一项 array[size]已经不是有效元素了，因为没初始化
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return 1;
}

int sizeList(ArrayList list) {
    return list->size;          //获取表中元素数
}

E * getList(ArrayList list, int index) {            //获取在第index的元素
    if (index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

int findList(ArrayList list, E element) {           //查找元素在第几个
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i + 1;
    }
    return -1;
}

int main() {
    struct List list;
    if (initList(&list)) {
        insertList(&list, 666, 1);
        deleteList(&list, 1);
        printf("%d\n", sizeList(&list));

    }
}

