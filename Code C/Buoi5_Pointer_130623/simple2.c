#include <stdio.h>

int a = 10;

int main(int argc, char const *argv[])
{
    /* code */
    int *ptr = &a;
    printf("Dia chi: %p\n", ptr);
    printf("Gia tri: %d\n", *ptr);
    return 0;
}
