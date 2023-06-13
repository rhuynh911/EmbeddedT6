#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union
{
  char test1[5]; // 5 byte
  char test2[3]; 
} typeData;

int main()
{
  typeDate data;
  
  strcpy(data.test1, (char*)"Hello");
  data.test1[5] = '\0'; // = NULL
  
  strcpy(data.test2, (char*)"Hi");
  data.test2[2] = '\0'; // = NULL
  
  printf("Test: %s\n", data.test1); // H i   l l o

  return 0;
}
