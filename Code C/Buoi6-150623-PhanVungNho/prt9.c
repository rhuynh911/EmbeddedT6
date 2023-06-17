#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test1(){
    int array[4];
    printf("Dia chi test1: %p\n", array);
}

void test2(){
    int *array = (int *)malloc(sizeof(int) * 4);
    printf("Dia chi test2: %p\n", array);
    free(array);
}


int main(int argc, char const *argv[])
{
    test1();
    test1();

    test2();
    test2();

    return 0;
}
