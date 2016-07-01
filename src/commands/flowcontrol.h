#ifndef _src_commands_flowcontrol_h_
#define _src_commands_flowcontrol_h_

#include "command.h"
#include "utilities.h"

state flo_jump(state currentState, vmword arga) {
  printf("JMP: %d\n", arga);
  state newState = currentState;
  newState.programCounter = arga;
  return newState;
}

state flo_jumpequalzero(state currentState, vmbyte arga, vmword argb) {
  printf("JEZ: %d %d\n", arga, argb);
  state newState = currentState;
  vmword result = 0;

  if(getRegisterValue(currentState, arga) == 0)
    result = argb;
  else
    result = newState.programCounter + 4;

  newState.programCounter = result;
  return newState;
}

state flo_jumpnotzero(state currentState, vmbyte arga, vmword argb) {
  printf("JNZ: %d %d\n", arga, argb);
  state newState = currentState;
  vmword result = 0;

  if(getRegisterValue(currentState, arga) != 0)
    result = argb;
  else
    result = newState.programCounter + 4;

  newState.programCounter = result;
  return newState;
}

state flo_jumpgreaterzero(state currentState, vmbyte arga, vmword argb) {
  printf("JGZ: %d %d\n", arga, argb);
  state newState = currentState;
  vmword result = 0;

  if(getRegisterValue(currentState, arga) > 0)
    result = argb;
  else
    result = newState.programCounter + 4;

  newState.programCounter = result;
  return newState;
}

state flo_jumplesserzero(state currentState, vmbyte arga, vmword argb) {
  printf("JLZ: %d %d\n", arga, argb);
  state newState = currentState;
  vmword result = 0;

  if(getRegisterValue(currentState, arga) < 0)
    result = argb;
  else
    result = newState.programCounter + 4;

  newState.programCounter = result;
  return newState;
}

state flo_end(state currentState) {
  printf("END\n");
  state newState = currentState;

  newState.hasExited = true;

  return newState;
}

#endif