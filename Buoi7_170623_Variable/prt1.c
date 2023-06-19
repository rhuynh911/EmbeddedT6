#include <stdio.h>

void count(){
    int temp = 0;
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
