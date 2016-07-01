#ifndef _src_commands_bitwise_h_
#define _src_commands_bitwise_h_

#include "command.h"
#include "utilities.h"

state bitwise_and(state currentState, vmbyte arga, vmbyte argb) {
  printf("AND: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = (valueb & valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwise_nand(state currentState, vmbyte arga, vmbyte argb) {
  printf("NAND: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = ~(valueb & valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwise_or(state currentState, vmbyte arga, vmbyte argb) {
  printf("OR: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = (valueb | valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwise_nor(state currentState, vmbyte arga, vmbyte argb) {
  printf("NOR: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = ~(valueb | valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwise_xor(state currentState, vmbyte arga, vmbyte argb) {
  printf("XOR: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = (valueb ^ valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwise_leftshift(state currentState, vmbyte arga, vmbyte argb) {
  printf("ROTL: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = (valueb << valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

state bitwise_rightshift(state currentState, vmbyte arga, vmbyte argb) {
  printf("ROTR: %d %d\n", arga, argb);
  vmbyte valuea = getRegisterValue(currentState, arga);
  vmbyte valueb = getRegisterValue(currentState, argb);

  vmbyte result = (valueb >> valuea);
  state newState = currentState;
  newState.registerAccumulator = result;
  return newState;
}

#endif