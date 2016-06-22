#ifndef _src_commandParser_h_
#define _src_commandParser_h_

#include <stdbool.h>

#include "commands/arithmetic.h"
#include "commands/bitwise.h"
#include "commands/command.h"
#include "commands/flowcontrol.h"
#include "commands/memory.h"

#include "state.h"

#include "commanddef.h"

state parseCommand(state input) {
  state output = input;
  unsigned char commandByte = input.vmMemory[input.programCounter];

  switch(commandByte) {
    case NOOP:
      output.programCounter++;
      break;
    case MOV:
      // Do some mov action
      break;
    case READ:
      break;
    case WRITE:
      break;
    case ADD:
      break;
    case SUB:
      break;
    case AND:
      break;
    case NAND:
      break;
    case OR:
      break;
    case NOR:
      break;
    case XOR:
      break;
    case ROTL:
      break;
    case ROTR:
      break;
    case JMP:
      break;
    case JEZ:
      break;
    case JNZ:
      break;
    case JLZ:
      break;
    case JGZ:
      break;
    case END:
      output.hasExited = true;
      break;
    default:
      break;
  }

  return output;
};

#endif