#include <stdio.h>
#include <stdlib.h>
#include "../Header/function.h"

int main(int argc, char const *argv[])
{
    //node array;
    //node_init(&array);

    node *array = NULL; //0xC1

    push_back(&array, 7);

    push_back(&array, 4);

    push_back(&array, 8);

    printf("test: %d\n", get(array, 0));
    printf("test: %d\n", get(array, 1));
    printf("test: %d\n", get(array, 2));

    // Print the size
    printf("[1] Size of the linked list: %d\n", getSize(array));

    insert(&array, 23, 0);
    printf("test: %d\n", get(array,0));

    // Print the size
    printf("[2] Size of the linked list: %d\n", getSize(array));

    // Pop the last node
    array = popBack(array);
    printLinkedList(array);

    // Print the size
    printf("[3] Size of the linked list: %d\n", getSize(array));

    return 0;
}
