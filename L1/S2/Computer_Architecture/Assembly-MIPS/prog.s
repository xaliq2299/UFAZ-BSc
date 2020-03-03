.data
number: .word 42
string: .asciiz "UFAZ is the best"

.text
main:
li $v0, 1 #loads a value inside a register
lw $a0, number #load word 
syscall

li $v0, 4
la $a0, string
syscall