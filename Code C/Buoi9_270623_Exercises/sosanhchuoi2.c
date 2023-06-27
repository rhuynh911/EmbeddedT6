#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// so sanh 2 chuoi
// char arr1[] = "ABC"; char arr2[] = "MNQ";

typedef enum{
    SMALLER, //0
    BIGGER, //1
    EQUAL //2
}Compare;

Compare isEqual(const char arr1[], const char arr2[]){
    uint8_t i = 0;
    while(arr1[i] == arr2[i]){
        if(arr1[i] == '\0'){ 
            return EQUAL;
        }
        i++;
    }
    
    if(arr1[i] - arr2[i] < 0){
        return SMALLER;
    }

    if(arr1[i] - arr2[i] > 0){
        return BIGGER;
    }

}

int main(int argc, char const *argv[])
{
    /* code */
    char arr1[] = "ABC";
    char arr2[] = "MNQ";

    //for (int i = 0; i < 10; i++)
    //{
        /* code */
        //printf("Test: %x\n", arr[i]);
    //}

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