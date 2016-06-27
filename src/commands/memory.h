#ifndef _src_commands_memory_h_
#define _src_commands_memory_h_

#include "command.h"
#include "../registerdef.h"

state mov(state currentState, vmbyte arga, vmbyte argb) {
  state newState = currentState;

  vmbyte register1;

  switch(arga) {
    case REGA:
      register1 = newState.registera;
      break;
    case REGB:
      register1 = newState.registerb;
      break;
    case REGC:
      register1 = newState.registerc;
      break;
    case REGD:
      register1 = newState.registerd;
      break;
    case REGACCUM:
      register1 = newState.registerAccumulator;
      break;
    case REGCARRY:
      register1 = newState.registerCarry;
      break;
  }

  switch(argb) {
    case REGA:
      newState.registera = register1;
      break;
    case REGB:
      newState.registerb = register1;
      break;
    case REGC:
      newState.registerc = register1;
      break;
    case REGD:
      newState.registerd = register1;
      break;
    default:
      break;
  }

  return newState;
}

state read(state currentState, vmword arga, vmbyte argb) {
  state newState = currentState;

  switch(argb) {
    case REGA:
      newState.registera = newState.vmMemory[arga];
      break;
    case REGB:
      newState.registerb = newState.vmMemory[arga];
      break;
    case REGC:
      newState.registerc = newState.vmMemory[arga];
      break;
    case REGD:
      newState.registerd = newState.vmMemory[arga];
      break;
    default:
      break;
  }

  return newState;
}

state write(state currentState, vmbyte arga, vmword argb) {
  state newState = currentState;

  vmbyte register1;

  switch(arga) {
    case REGA:
      register1 = newState.registera;
      break;
    case REGB:
      register1 = newState.registerb;
      break;
    case REGC:
      register1 = newState.registerc;
      break;
    case REGD:
      register1 = newState.registerd;
      break;
    case REGACCUM:
      register1 = newState.registerAccumulator;
      break;
    case REGCARRY:
      register1 = newState.registerCarry;
      break;
  }

  newState.vmMemory[argb] = register1;

  return newState;
}

#endif