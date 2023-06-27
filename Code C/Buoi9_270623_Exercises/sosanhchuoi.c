#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// so sanh 2 chuoi
// char arr1[] = "Hello"; char arr2[] = "This is test";

bool isEqual(const char arr1[], const char arr2[]){
    uint8_t i = 0;
    while(arr1[i] == arr2[i]){
        if(arr1[i] == '\0'){ 
            return true;
        }
        i++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    char arr1[] = "Hello";
    char arr2[] = "Hello";

    //for (int i = 0; i < 10; i++)
    //{
        /* code */
        //printf("Test: %x\n", arr[i]);
    //}

    bool cmp = isEqual(arr1, arr2);

    if(cmp == true){
        printf("The strings are equal.\n");
    }else{
        printf("The string are not equal.\n");
    }
    
    return 0;
}
