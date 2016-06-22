#ifndef _src_commands_arithmetic_h_
#define _src_commands_arithmetic_h_

#include "./command.h"

state add(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb + arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state sub(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb - arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

#endif