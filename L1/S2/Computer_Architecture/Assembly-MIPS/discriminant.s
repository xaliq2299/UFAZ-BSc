.data
a: .word 2
b: .word 5
c: .word -2
d: .word 15656

.text
main:
lw $t0, a
lw $t1, b
lw $t2, c
mul $t1, $t1, $t1 
mul $t0, $t0, $t2
mul $t0, $t0, 4
sub $v0, $t1, $t0

sw $v0, d #copy address from register to memory
addi $a0, $v0, 0 #adds and automatically write to the memory
move $a0,$v0 #copy address from register to register

li $v0, 1
syscall
