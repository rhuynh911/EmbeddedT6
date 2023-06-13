#include <stdio.h>

#define MAX 10
#define SUM(a,b) a+b
#define CREATE_FUNC(ten_ham, noi_dung)       \
void ten_ham(){
    printf("%s\n", noi_dung);
}
CREATE_FUNC(test, "this is test");
CREATE_FUNC(abc, "this is abc");

int main(int argc, char const *argv[])
{

    printf("MAX : %d\n", MAX);
    
    int a = MAX + 5;

    printf("tong a va b : %d\n", SUM(4,7));
    printf("tong a va b : %d\n", SUM(1,4));

    test();

    return 0;
}
