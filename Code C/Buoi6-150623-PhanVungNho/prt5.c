#include <stdio.h>

void swap(int a, int b){        //int a = 10 ; 0x01
    int temp = a;               //int b = 20 ; 0x02
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int x = 10; //0xC1
    int y = 20; //0xC2

    swap(x,y);

    printf("x = %d, y =%d\n",x,y);

    return 0;
}
