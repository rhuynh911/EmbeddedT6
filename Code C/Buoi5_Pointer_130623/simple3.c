#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 10;
    char c = 'A';
    double d = 10.4;

    void *ptr;
    ptr = &i;
    printf("Dia chi i: %p, gia tri: %d\n", ptr, *(int *)ptr);
    ptr = &c;
    printf("Dia chi c: %p, gia tri: %c\n", ptr, *(char *)ptr);
    ptr = &d;
    printf("Dia chi d: %p, gia tri: %f\n", ptr, *(double *)ptr);

    return 0;
}
