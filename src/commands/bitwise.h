#ifndef _src_commands_bitwise_h_
#define _src_commands_bitwise_h_

#include "./command.h"

state bitwiseand(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb & arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwisenand(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = ~(argb & arga);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwiseor(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb | arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwisenor(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = ~(argb | arga);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwisexor(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb ^ arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwiseleftshift(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb << arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwiserightshift(state currentState, vmbyte arga, vmbyte argb) {
  vmbyte result = argb >> arga;
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

#endif