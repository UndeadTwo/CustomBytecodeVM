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

  //printState(input);

  switch(commandByte) {
    case NOOP:
      output.programCounter++;
      break;
    case MOV:
      output = mem_mov(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case READ:
      output = mem_read(input, *(vmword*)(input.vmMemory + input.programCounter + 1), input.vmMemory[input.programCounter + 3]);
      output.programCounter += 4;
      break;
    case WRITE:
      output = mem_write(input, input.vmMemory[input.programCounter + 1], *(vmword*)(input.vmMemory + input.programCounter + 2));
      output.programCounter += 4;
      break;
    case ADD:
      output = ari_add(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case SUB:
      output = ari_sub(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case AND:
      output = bitwise_and(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case NAND:
      output = bitwise_nand(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case OR:
      output = bitwise_or(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case NOR:
      output = bitwise_nor(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case XOR:
      output = bitwise_xor(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case ROTL:
      output = bitwise_leftshift(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case ROTR:
      output = bitwise_rightshift(input, input.vmMemory[input.programCounter + 1], input.vmMemory[input.programCounter + 2]);
      output.programCounter += 3;
      break;
    case JMP:
      output = flo_jump(input, *(vmword*)(input.vmMemory + input.programCounter + 1));
      break;
    case JEZ:
      output = flo_jumpequalzero(input, input.vmMemory[input.programCounter + 1], *(vmword*)(input.vmMemory + input.programCounter + 2));
      break;
    case JNZ:
      output = flo_jumpnotzero(input, input.vmMemory[input.programCounter + 1], *(vmword*)(input.vmMemory + input.programCounter + 2));
      break;
    case JLZ:
      output = flo_jumplesserzero(input, input.vmMemory[input.programCounter + 1], *(vmword*)(input.vmMemory + input.programCounter + 2));
      break;
    case JGZ:
      output = flo_jumpgreaterzero(input, input.vmMemory[input.programCounter + 1], *(vmword*)(input.vmMemory + input.programCounter + 2));
      break;
    case END:
      output = flo_end(input);
      output.programCounter += 1;
      break;
    default:
      break;
  }

  return output;
};

#endif