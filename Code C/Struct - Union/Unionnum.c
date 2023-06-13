#include <stdio.h>
#include <stdint.h>

typedef union
{
  uint8_t test1[6]; 
  uint8_t test2[3];
}typeData;

int main()
{
  typeData data;
  
  for (int i = 0; i < 6; i++)
  {
    data.test1[i] = i;
  }
  
   for (int i = 0; i < 3; i++)
  {
    data.test2[i] = 2 * i;
  }
  
    for (int i = 0; i < 6; i++)
  {
    printf("Test1: %d\n", data.test1[i]);
  }
  return 0;
}
