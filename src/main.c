#include <string.h>

#include "commandParser.h"
#include "memoryMap.h"
#include "state.h"

int main() {
  state MyState = createState();

  memcpy(MyState.vmMemory, &testMemoryMap, (sizeof(char) * sizeof(testMemoryMap)));

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