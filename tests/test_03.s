addi x16,x0,1
addi x17, x0,0
addi x18, x0,10
label:
or x17, x17, x16
sub x18, x18,x16
bne x18, x16, label
beq x18,x18, label
