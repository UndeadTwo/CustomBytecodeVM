#ifndef _src_commands_memory_h_
#define _src_commands_memory_h_

#include <stdio.h>

#include "command.h"
#include "utilities.h"
#include "../registerdef.h"

state mem_mov(state currentState, vmbyte arga, vmbyte argb) {
  printf("MOV: %d %d\n", arga, argb);
  printf("MOV ext: arga %d\n", getRegisterValue(currentState, arga));
  printf("MOV ext: argb %d\n", getRegisterValue(currentState, argb));
  return setRegisterValue(currentState, argb, getRegisterValue(currentState, arga));
}

state mem_read(state currentState, vmword arga, vmbyte argb) {
  printf("READ: %d %d\n", arga, argb);
  printf("READ ext: memory %d\n", currentState.vmMemory[arga]);
  return setRegisterValue(currentState, argb, currentState.vmMemory[arga]);
}

state mem_write(state currentState, vmbyte arga, vmword argb) {
  printf("WRITE: %d %d\n", arga, argb);
  state newState = currentState;
  newState.vmMemory[argb] = getRegisterValue(currentState, arga);
  return newState;
}

#endif