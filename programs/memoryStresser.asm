read  rega
read  regb
read  regc
read  regd


// Constants
memend = 255, output1 = 0xFC, output2 = 0x7F

// Variables
membyte1 = 0x00, membyte2 = 0x01, outputtoggle = 0x00, output1 = 0x7F, output2 = 0xFF


// LOOP Work
if(outputtoggle == 0)
  write membyte1,membyte2 output1
  

// LOOP Control
increment membyte1

if(membyte1 == memend)
  increment membyte2
  membyte1 = 0

if(membyte2 == memend)
  end
