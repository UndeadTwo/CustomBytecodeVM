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
      output = mov(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case READ:
      output = read(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 3]);
      output.programCounter += 4;
      break;
    case WRITE:
      output = write(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 4;
      break;
    case ADD:
      output = add(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case SUB:
      output = sub(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case AND:
      output = bitwiseand(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case NAND:
      output = bitwisenand(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case OR:
      output = bitwiseor(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case NOR:
      output = bitwisenor(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case XOR:
      output = bitwisexor(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case ROTL:
      output = bitwiseleftshift(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case ROTR:
      output = bitwiserightshift(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case JMP:
      output = jump(input, input.vmMemory[input.programCounter + 1]);
      output.programCounter += 3;
      break;
    case JEZ:
      output = jumpequalzero(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case JNZ:
      output = jumpnotzero(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case JLZ:
      output = jumplesserzero(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case JGZ:
      output = jumpgreaterzero(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case END:
      output = end(input);
      output.programCounter += 1;
      break;
    default:
      break;
  }

  return output;
};

#endif