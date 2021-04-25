addi x5,x0,3
addi x6,x0,10
addi x10,x0,20
sw  x5,0(x10)
sw x6,4(x10)
lw x11, 0(x10)
lw x12,4(x10)
add x14, x11, x12
sub x15, x12, x11
sub x16, x11, x12
and x17, x12,x11
or x18, x11, x12
