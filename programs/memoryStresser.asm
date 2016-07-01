read  rega
read  regb
read  regc
read  regd


// Constants
memend1 = 255, memend2 = 0x7F, output1 = 0xFC, output2 = 0x7F, 0x01const, 0x00const

// Variables
membyte1 = 0x00, membyte2 = 0x01, outputtoggle = 0x00, output1 = 0x7F, output2 = 0xFF


// LOOP Work
if(outputtoggle == 0) // jez outputtoggle; read output1; ELSE: read output2
  write output1 membyte1,membyte2


  

// LOOP Control
increment membyte1

if(membyte1 == memend1) // sub membyte memend; jez regacc; add membyte2 0x01const; mov regacc membyte2; mov 0x00const membyte1
  increment membyte2
  membyte1 = 0

if(membyte1 == memend1 && membyte2 == memend2) // sub membyte1 memend; jez regacc; sub membyte2 memend; jez regacc end
  end

// Program assem
JMP SETUPREGS
0xFF, 0x7F, 0xFC, 0x01, 0x00, ;Constants
0x00, 0x01, 0x00,             ;Variables

SETUPREGS:read 0x09 0x00 rega
read 0x0A 0x00 regb
read 0x08 0x00 regc
LOOP:write rega ARG1
write regb ARG2

START:jez regc OUT1

OUT0: read 0x04 0x00 regd ;Set to write first half of pattern
jmp WRITE

OUT1: read 0x05 0x00 regd ;Set to write second half of pattern
jmp WRITE

WRITE: write regd 0x09 0x00

READ memend1 regd
SUB regd memend1
JEZ regacc
READ 1const regd

JMP LOOP

{
  0x0D, 0x0B, 0x00, // Jump to program Entry  //0
  0xFF, 0x7F, 0xFC, 0x01, 0x00, // Constants  //3
  0x00, 0x01, 0x00, // Variables              //8

  // Move initial values to registers
  0x02, 0x09, 0x00, 0x00, // Read 0x0900 rega //11
  0x02, 0x0A, 0x00, 0x01, // Read 0x0A00 regb //15
  0x02, 0x08, 0x00, 0x02, // Read 0x0800 regc //19
                  
  // Entry point for loop
  // Basically a do-while
  0x03, 0x00, 0x09, 0x00, //23
  0x03, 0x01, 0x0A, 0x00, //27

  // Jump if regc is not equal to zero
  0x0F, 0x02,             //31
  // Else read in pattern[0]
  0x02, 0x04, 0x00, 0x03, //35
  0x02, 0x06, 0x00, 0x02, //39
  0x0D, // Jump to write-out

  // Read in pattern[1]
  0x02, 0x05, 0x00, 0x03, //42
  0x02, 0x06, 0x00, 0x02, //46
  0x0D, //Jump to write-out //49

  // Write memory addr to memory location
  0x03, 0x00, //ArgA //53
  0x03, 0x01, //ArgB //57
  0x03, 0x03, 0x00, 0x00 //Write regd to ArgA, ArgB //61
                       
  // Loop control
  0x02, 0x03, 0x00, 0x03, // Read 0x0300 to regd  (value of memory should be 0xFF) //65
  0x05, 0x03, 0x00,       // Sub regd, rega //68
  0x0E, 0x06, 0x5A, 0x00, // Jez //72
  0x02, 0x04, 0x00, 0x03, // Read 0x0400 to regd  (value of memory should be 0x7F) //76
  0x05, 0x03, 0x01,       // Sub regd, regb //79
  0x0F, 0x06, 0x17, 0x00  // Jnz //83
  0xFF,                   // End program if zero //84
                          
  // Increment regb
  0x02, 0x06, 0x00, 0x03, // Read 0x0600 to regd (value of memory should be 0x01) //90
  0x04, 0x03, 0x01,       // Add regd to regb //93
  0x01, 0x06, 0x02,       // Mov regacc to regb //96
  0x0D, 0x17, 0x00,       // Jump to start of program

};