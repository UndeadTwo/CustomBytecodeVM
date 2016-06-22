#include "commandParser.h"
#include "memoryMap.h"
#include "state.h"

int main() {
  state MyState = createState();

  while(MyState.hasExited != true) {
    state NewState = parseCommand(MyState);
    
  }

  return 0;
}