/*
* File: compare.h
* Author: HVI1HC
* Date: 27/06/2023
* Description: This is a header file for comparing 2 string
*/

#ifndef COMPARE_H
#define COMPARE_H

typedef enum{
    SMALLER, //0
    BIGGER, //1
    EQUAL //2
}Compare;

/*
* Function: isEqual
* Description: This function compare two input string
* Input:
*   a - first input string
*   b - second input string
* Output:
*   returns result after comparing 2 string (SMALLER, BIGGER, EQUAL)
*/
Compare isEqual(const char arr1[], const char arr2[]);


#endif
