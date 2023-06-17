#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *array = (int *)malloc(sizeof(int) * 4);

    for(int i = 0; i < 4; i++){
        array[i] = 3 * i;
    }

    for(int i = 0; i < 4; i++){
        printf("i = %d\n", array[i]);
    }

    array = (int *)realloc(array, sizeof(int) * 7);

    for(int i = 0; i < 7; i++){
        array[i] = 2 * i;
    }

    for(int i = 0; i < 7; i++){
        printf("i = %d\n", array[i]);
    }

    return 0;
}
