#include <stdio.h>

void tong(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a + b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d = %d\n", a, b, a - b);
}

void tich(int a, int b){
    printf("Tich %d va %d = %d\n", a, b, a * b);
}

void thuong(int a, int b){
    //return (double)a/b;
    printf("Thuong %d va %d = %f\n", a, b, (double)a / b);
}

int main(int argc, char const *argv[])
{
    /* code */
    void (*ptr)(int, int);
    //printf("[0] Dia chi fp: %p; Gia tri fp: ", &ptr, *ptr);
    ptr = &tong;
    ptr(71,8);
    //printf("\n[1] Dia chi fp: %p; Gia tri fp: ", &ptr, *ptr);
    ptr = &hieu;
    ptr(19,6);
    ptr = &tich;
    ptr(7,3);
    ptr = &thuong;
    ptr(17,4);

    //double (*ptrD)(int,int) = &thuong;
    //ptrD(17,3);

    return 0;
}
