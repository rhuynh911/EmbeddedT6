#include <stdio.h>

int tong(int a, int b){ //stack (a,b,c)
    int c;
    c = a + b;
    return c;
}


int main(int argc, char const *argv[])
{
    int x = tong(5, 7); // int a = 5; //0x01
                        // int b = 7; //0x02
                        // int c;     //0x03
                        // c = a + b;
                        // return c
    tong(7,8);          // int a = 7;   //0xC1 
                        // int b = 8;
    return 0;
}
