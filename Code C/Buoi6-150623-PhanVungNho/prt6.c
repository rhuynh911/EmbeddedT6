#include <stdio.h>

void swap(int *a, int *b){        //int *a = 0xC1    //0xA1
    int temp = *a;                //int *b = 0xC2    //0xA2
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    int x = 10; //0xC1
    int y = 20; //0xC2

    swap(&x,&y);

    printf("x = %d, y =%d\n",x,y);

    return 0;
}
