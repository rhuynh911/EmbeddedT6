#include "../Header/function.h"
#include <stdint.h>

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

int get(node *array, int index){
    int i = 0;

    while (array->next != NULL && index != i){
        array = array->next;
        i++;
    }

    return array->value;
    
}

void insert(node **array, int value, int pos){
    node *temp, *p;
    
    p = *array;
    temp = createNode(value);

    int i = 1;

    if(pos == 0){
        temp->next = *array;
        *array = temp;
    }else{
        while (p->next->next != NULL && pos != i){
        p = p->next;
        i++;
        }
    }

    temp->next = p->next;
    p->next = temp;

}

// Function to erase a node in a linked list
node* eraseNode(node* head, int key) {
    node* current = head;
    node* previous = NULL;

    // Traverse the linked list until the key is found
    while (current != NULL && current->value != key) {
        previous = current;
        current = current->next;
    }

    // If key is not found, return the original linked list
    if (current == NULL) {
        return head;
    }

    // Update the links to bypass the current node
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        head = current->next;
    }

    // Free the memory of the current node
    free(current);

    return head;
}

// Function to print the linked list
void printLinkedList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to pop the last node from a linked list
node* popBack(node* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, return NULL
        return NULL;
    }

    node* current = head;
    node* previous = NULL;

    // Traverse the linked list until the last node is reached
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Update the links to remove the last node
    previous->next = NULL;

    // Free the memory of the last node
    free(current);

    return head;
}

// Function to calculate the size of a linked list
int getSize(node* head) {
    int count = 0;
    node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
