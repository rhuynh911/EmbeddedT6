#include <stdio.h>
#include <stdint.h>

typedef union
{
  uint64_t a; // 8byte
  uint8_t b; // 1byte
  uint32_t c; // 4byte
} typeData;

void display (typeData data)
{
  printf("a: %lu, b: %lu, c: %lu", data.a, data.b, data.c);
}

int main()
{
  
  typeData data;
  
  printf("Address of union: %p\n", &data);
  
  printf("Address of a: %p\n", &data);
  
  printf("Address of b: %p\n", &data);

  printf("Address of c: %p\n", &data);
  
  data.a = 12;
  
  data.b = 27;
  
  data.c = 35;
  
//   typeData data = {12, 17, 27}; 
  
  display(data);
  
  printf("Size: %d\n", sizeof(data));
  
  return 0;
  
}
  
  
