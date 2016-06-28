#ifndef _src_commands_utilities_h_
#define _src_commands_utilities_h_

#include <stdio.h>
#include <assert.h>

#include "command.h"
#include "../registerdef.h"

vmbyte getRegisterValue(state myState, vmbyte registerAddr) {
  switch(registerAddr) {
    case REGA:
      return myState.registera;
    case REGB:
      return myState.registerb;
    case REGC:
      return myState.registerc;
    case REGD:
      return myState.registerd;
    case REGACCUM:
      return myState.registerAccumulator;
    case REGCARRY:
      return myState.registerCarry;
    default:
      return 0;
  }
}

state setRegisterValue(state myState, vmbyte registerAddr, vmbyte registerVal) {
  state newState = myState;

  switch(registerAddr) {
    case REGA:
      newState.registera = registerVal;
      break;
    case REGB:
      newState.registerb = registerVal;
      break;
    case REGC:
      newState.registerc = registerVal;
      break;
    case REGD:
      newState.registerd = registerVal;
      break;
    case REGCARRY:
      newState.registerCarry = registerVal;
      break;
    default:
      printf("Invalid registerAddr in program %d\n", registerAddr);
      assert(false);
      break;
  }
  
  // Intentional fall through

  return newState;
}

#endif