#include <stdio.h>

int tong(int a, int b){
    return a+b;
}

int a = 10;

int main(int argc, char const *argv[])
{
    /* code */
    printf("Dia chi: %p\n", &tong);
    printf("Dia chi: %p\n", &a);
    return 0;
}
