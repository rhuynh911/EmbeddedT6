#include <stdio.h>
#include <stdint.h>

uint16_t array[] = {1, 2, 3 ,4};

uint16_t *ptr = array;

int main(int argc, char const *argv[])
{
    printf("Dia chi arr: %p\n", array);

    //printf("%d\n", ptr[1]);

    for(int i = 0; i < 4; i++){
        printf("Dia chi array[%d] = %p\n", i, &array[i]);
    }

    return 0;
}
