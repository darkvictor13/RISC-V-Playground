addi x16,x0,1
addi x17, x0,0
addi x18, x0,5
label1:
beq x16, x18, label2
add x17, x17, x16
sub x18,x18, x16
beq x16, x16, label1
label2:
