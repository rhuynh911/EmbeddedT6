#include <stdio.h>

int i; //BSS
static int x = 0; //BSS

void tong(){
    static int y; //BSS
}

int main(int argc, char const *argv[])
{
    int a;
    i = 20; //BSS
    printf("i = %d\n", i);
    return 0;
}
