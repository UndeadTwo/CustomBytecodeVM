;0x00FF - 0x010F are jumps

mov 0xff00 rega
mov 0xff01 regb
mov 0xff02 regc
mov 0xff03 regd
jmp 0x1700
end
end
end
end
write rega 0xfc7f
jmp 0x2200
end
end
end
end
write regb 0xfcf7
jmp 0x2C //38
end
end
end
end
write regc 0xfcf7
jmp 0x33 //51
end
end
end
end
write regd 0xfcf7 //51
end

rega = 19
regb = 29
regc = 39
regd = 49

{
0x01, 0xFF, 0x00, 0x00,
0x01, 0x00, 0x01, 0x01,
0x01, 0x01, 0x01, 0x02,
0x01, 0x02, 0x01, 0x03,
0x01, 0xFE, 0x00, 0x04,
0x0D, 0x17, 0x00,
0xFF,
0xFF,
0xFF,
0xFF,
0x03, 0x01, 0xFC, 0x7F,
0x0D, 0x2C, 0x00,
0xFF,
0xFF,
0xFF,
0xFF,
0x03, 0x02, 0xFC, 0x7F,
0x0D, 0x33, 0x00,
0xFF,
0xFF,
0xFF,
0xFF,
0x03, 0x03, 0xFC, 0x7F,
0xFF
}