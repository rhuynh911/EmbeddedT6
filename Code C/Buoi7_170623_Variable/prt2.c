#include <stdio.h>

void count(){
    static int temp = 0;        //0xC1
    printf("temp: %d\n", temp);
    temp++;
}

int main(int argc, char const *argv[])
{
    count();
    count();
    count();

    return 0;
}
