#include <stdio.h>

int i = 10;
static int x = 5;

void tong(){
    static int y = 10;
    y = 5;
}

int main(int argc, char const *argv[])
{
    int a;
    i = 20;
    printf("i = %d\n", i);
    return 0;
}
