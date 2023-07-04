#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    /* data */
    int value;
    struct node *next;
}node;

node* createNode(int value){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

//void node_init(node *ptr){
    //ptr = NULL;
//}

void push_back(node **array, int value){
    node *temp, *p;
    temp = createNode(value);
    if(*array == NULL){
        *array = temp;
    }
    else{
        p = *array;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

int main(int argc, char const *argv[])
{
    //node array;
    //node_init(&array);

    node *array = NULL; //0xC1

    push_back(&array, 7);

    push_back(&array, 4);

    push_back(&array, 8);

    return 0;
}
