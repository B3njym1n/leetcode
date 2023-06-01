#include <stdio.h>
#include <stdint.h>

int 
main(void)
{
  struct 
  Node1
  {
    uint8_t num1;
    char padding[7]; // padding
    uint64_t num2;
    uint8_t num3;
    char padding2[7]; // padding
  } node1;
  printf("Sizeof node1 : %zu\n", sizeof(node1));
  return 0;
}
