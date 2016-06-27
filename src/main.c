#include <string.h>

#include "commandParser.h"
#include "memoryMap.h"
#include "state.h"

int main() {
  state MyState = createState();

  memcpy(MyState.vmMemory, &testMemoryMap, (sizeof(char) * 19));

  MyState.vmMemory[0x00FF] = 0x34;
  MyState.vmMemory[0x0100] = 0x14;

  while(MyState.hasExited != true) {
    state NewState = parseCommand(MyState);
    MyState = NewState;
  }

  printState(MyState);
  printf("%d\n", *(int*)(MyState.vmMemory + 0x7FFC));

  return 0;
}