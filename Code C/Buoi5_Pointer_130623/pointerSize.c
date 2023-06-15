#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int *i;
    double **dd;

    void (*pp)(int, int);

    printf("size: %lu\n", sizeof(i));
    printf("size: %lu\n", sizeof(dd));
    printf("size: %lu\n", sizeof(pp));


    return 0;
}
