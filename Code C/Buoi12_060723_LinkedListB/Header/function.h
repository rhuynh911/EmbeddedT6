/*
* File: function.h
* Author: HVI1HC
* Date: 07/07/2023
* Description: This is a header file contain many functions for single linkedlist
*/

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    /* data */
    int value;
    struct node *next;
}node;

/*
* Function: createNode
* Description: This function compare two input string
* Input:
*   int value : 
* Output:
*   returns a created node with input value
*/
node* createNode(int value);

/*
* Function: push_back
* Description: This function to push a node to linkedlist
* Input:
*   node **array : a new node to push into a linkedlist
*   int value: value of that new node to be pushed into a linkedlist 
* Output:
*   
*/
void push_back(node **array, int value);

/*
* Function: get
* Description: This function to get a node from a linkedlist at specific index
* Input:
*   node **array : linkedlist want to find a node
*   int index: index want to get a node from linkedlist
* Output:
*   value of that node
*/
int get(node *array, int index);

/*
* Function: insert
* Description: This function to get a node from a linkedlist at specific index
* Input:
*   node **array : linkedlist want to insert a node
*   int value: value of node want to push into linkedlist
*   int pos: postion want to push into linkedlist
* Output:
*   
*/
void insert(node **array, int value, int pos);

/*
* Function: eraseNode
* Description: This function to erase a node in a linked list
* Input:
*   node *head : linkedlist
*   int key: value of node want to be deleted from linkedlist
* Output:
*   linkedlist without deleted node
*/
node* eraseNode(node* head, int key);

/*
* Function: printLinkedList
* Description: Function to print the linked list
* Input:
*   node *head : linkedlist
* Output:
*   
*/
void printLinkedList(node* head);

/*
* Function: popBack
* Description: Function to pop the last node from a linked list
* Input:
*   node *head : linkedlist
* Output:
*   
*/
node* popBack(node* head);

/*
* Function: getSize
* Description: Function to calculate the size of a linked list
* Input:
*   node *head : linkedlist
* Output:
*  
*/
int getSize(node* head);

#endif
