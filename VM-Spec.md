```
;System details
;4 program addressable registers
0x00 REGA
0x01 REGB
0x02 REGC
0x03 REGD
;Carry register
0x04 CARRY
;Program Counter
0x05 PC
;Program Accumulator
0x06 ACC

;System
0x00 NOOP

;Memory
;Memory commands take either a register 0x00 0xXX or a memory address word 0xXX 0xXX
;COMMAND_BYTE REGISTER_BYTE REGISTER_BYTE
;Copy contents of one register to another
0x01 MOV
;COMMAND_BYTE MEMORY_ADDRESS_WORD REGISTER_BYTE
;Read contents of memory to a register
0x02 READ
;COMMAND_BYTE REGISTER_BYTE MEMORY_ADDRESS_WORD
;Write register contents to a memory region
0x03 WRITE

;Arithmetic
;COMMAND_BYTE REGISTER_BYTE REGISTER_BYTE
0x04 ADD
0x05 SUB

;Bit arithmetic
;COMMAND_BYTE REGISTER_BYTE REGISTER_BYTE
0x06 AND
0x07 NAND
0x08 OR
0x09 NOR
0x0A XOR
;COMMAND_BYTE REGISTER_BYTE
;Outputs to carry register
0x0B ROTL
0x0C ROTR

;Arbitrary flow control
;COMMAND_BYTE NEW_PROGRAM_COUNTER(16bit)
0x0D JMP
;COMMAND_BYTE REGISTER_BYTE NEW_PROGRAM_COUNTER(16bit)
0x0E JEZ
0x0F JNZ
0x10 JLZ
0x11 JGZ

;End of Program
0xFF END

;example bytecode: 0x01 0x00 0x00 0x00 0x01;MOV REGA REGB; Move's content of register a to register b
;example bytecode: 0x01 0x01 0x00 0x01 0x01;MOV MEMORY 0x0100 0x0101; Move's content of address 0x0100 to 0x0101
```