#include <stdio.h>
#include "../Header/compare.h"

int main(int argc, char const *argv[])
{
    char arr1[] = "ABC";
    char arr2[] = "MNQ";
    Compare cmp = isEqual(arr1, arr2);

    if(cmp == SMALLER){
        printf("The strings are SMALLER.\n");
    }

    if(cmp == BIGGER){
        printf("The strings are BIGGER.\n");
    }

    if(cmp == EQUAL){
        printf("The strings are EQUAL.\n");
    }
    
    return 0;
}
