#include "commandParser.h"
#include "memoryMap.h"
#include "state.h"

int main() {
  state MyState = createState();

  printState(MyState);

  return 0;
}