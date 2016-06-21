#ifndef _src_commandParser_h_
#define _src_commandParser_h_

#include "commandList.h"
#include "state.h"

typedef enum {
  NOOP = 0x00,
  MOV = 0x01,
  READ = 0x02,
  WRITE = 0x03,
  ADD = 0x04,
  SUB = 0x05,
  AND = 0x06,
  NAND = 0x07,
  OR = 0x08,
  NOR = 0x09,
  XOR = 0x0A,
  ROTL = 0x0B,
  ROTR = 0x0C,
  JMP = 0x0D,
  JEZ = 0x0E,
  JNZ = 0x0F,
  JLZ = 0x10,
  JGZ = 0x11,
  END = 0xFF,
} command;

#endif