#include <stdio.h>

#pragma pack(1)
struct my_struct{
    int a; //4 bytes
    char b; //1 byte
    int c; //4 byte
};
#pragma pack()

int main(int argc, char const *argv[])
{
    struct my_struct s;

    s.a=10;
    s.b='a';
    s.c=20;

    printf("sizeof(int) is %d bytes\n", sizeof(int));
    printf("sizeof(char) is %d bytes\n", sizeof(char));
    printf("The size of the structure is %zu bytes\n", sizeof(s));

    return 0;
}
