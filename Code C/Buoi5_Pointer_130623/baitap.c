#include <stdio.h>
#include<string.h>

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
    printf("Thuong %d va %d = %f\n", a, b, (double)a / b);
}

void toanHoc(void (*ptr)(int, int), int a, int b){
    printf("Chuong trinh tinh toan\n");
    ptr(a, b);
}


int main(int argc, char const *argv[])
{
    //toanHoc(&tong,4,7);
    //toanHoc(&hieu,24,7);

    //void *ptr = &tong;
    //((void (*)(int,int))ptr)(8,9);

    //int *ptr = NULL;
    //int **ptp = &ptr;

    //printf("Dia chi: %p, gia tri: %p\n", &ptr, ptr);
    //printf("Dia chi: %p, gia tri: %p\n", &ptp, ptp);

    double d = 10.3;
    char string[] = "Hello";

    void *array[] = {&toanHoc, &d, string}; //void **array

    //Gia tri tong
    printf("Gia tri tong a & b: \n");
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&tong,10,10);

    // Gia tri hieu
    printf("Gia tri hieu a & b: \n");
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&hieu,10,10);

    // Gia tri tich
    printf("Gia tri tich a & b: \n");
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&tich,2,5);

    // Gia tri thuong
    printf("Gia tri thuong a & b: \n");
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&thuong,2,5);

    //Gia tri d
    printf("Gia tri d: %f\n", *(double*)(array[1]));

    //Gia tri string
    //cach 1: printf("%s", (char*)array[2]);

    //cach 2

    for(int i=0; i < strlen(string); i++){
        printf("%c", *((char*)array[2]+i));
    }

    return 0;
}
