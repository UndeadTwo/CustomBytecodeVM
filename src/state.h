#ifndef _src_state_h
#define _src_state_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  char registera,
    registerb,
    registerc,
    registerd,
    registerAccumulator,
    registerCarry;

  int programCounter;

  char* vmMemory;

  bool hasExited;
} state;

state createState() {
  state newState;

  newState.registera = 0;
  newState.registerb = 0;
  newState.registerc = 0;
  newState.registerd = 0;

  newState.registerAccumulator = 0;
  newState.registerCarry = 0;

  newState.programCounter = 0;

  newState.vmMemory = (char*)calloc(1024 * 32, sizeof(char));

  newState.hasExited = false;

  return newState;
}

void freeState(state stateToFree) {
  free(stateToFree.vmMemory);
}

void printState(state mState) {
  printf("Registers: %d %d %d %d\n", mState.registera, mState.registerb, mState.registerc, mState.registerd);
  printf("Accumulator: %d\n", mState.registerAccumulator);
  printf("Carry: %d\n", mState.registerCarry);
  printf("Program Counter: %d\n", mState.programCounter);
}

#endif