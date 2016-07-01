#ifndef _src_commands_arithmetic_h_
#define _src_commands_arithmetic_h_

#include "command.h"
#include "utilities.h"

state ari_add(state currentState, vmbyte arga, vmbyte argb) {
  printf("ADD: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);


  vmbyte result = valueb + valuea;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state ari_sub(state currentState, vmbyte arga, vmbyte argb) {
  printf("SUB: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);


  vmbyte result = valueb - valuea;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

#endif