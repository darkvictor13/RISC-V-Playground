addi x16,x0,1
addi x17, x0,0
addi x18, x0,5
beq x16, x18, 12
add x17, x17, x16
sub x18,x18, x16
beq x16, x16, -16
