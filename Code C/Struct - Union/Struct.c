#include <stdio.h>
#include <stdint.h>

struct typeDate
{
    uint16_t arr1[7]; // 2*4 + 2*3 = 14 (dư 2)   
    uint64_t arr4[5]; // 8 * 5 = 40
    uint8_t arr2[3]; // 2*3 = 6 (dư 2) 
    uint32_t ar3[5]; // 2*4 + 2*4 + 4 = 20 "trừ 4 dư ở trên" = 16 => Tổng 80;  
};

int main()
{
    printf("size: %lu\n",sizeof(struct typeDate));
}
