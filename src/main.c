#include <string.h>

#include "commandParser.h"
#include "memoryMap.h"
#include "state.h"

int main() {
  state MyState = createState();

  memcpy(MyState.vmMemory, &testMemoryMap, (sizeof(char) * sizeof(testMemoryMap)));

  MyState.vmMemory[0x00FF] = 18;
  MyState.vmMemory[0x0100] = 28;
  MyState.vmMemory[0x0101] = 38;
  MyState.vmMemory[0x0102] = 48;

  printf("Unknown region %d\n", MyState.vmMemory[0x1A]);
  // printf("Jump 2 %d\n", MyState.vmMemory[0x22]);
  // printf("Jump 3 %d\n", MyState.vmMemory[0x2D]);

  while(MyState.hasExited != true) {
    //printState(MyState);
    state NewState = parseCommand(MyState);
    MyState = NewState;
  }

  printState(MyState);
  
  unsigned char target[] = {0xFC, 0x7F};
  printf("Memory Target %d\n", *((short unsigned int*)&target) );
  printf("Memory at target %d\n", MyState.vmMemory[*((short unsigned int*)&target)]);

  return 0;
}