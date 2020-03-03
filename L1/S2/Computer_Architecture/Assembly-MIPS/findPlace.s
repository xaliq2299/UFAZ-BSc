.data
array: .word 1 2 3 4 5 6 7 8 9 10
size:  .word 10
message1:.asciiz "Enter an integer: "

.text
main:
	la $a0, message1
	li $v0, 4
	syscall
	lw $a0, size
	la $a1, array
	li $v0, 5
	syscall
	move $a2, $v0
	jal findPlace

findPlace:
	li $t0, 0
	loop:
	bgt $t0, $a0, end
	beq $a2, $a1, find
		addi $a1, $a1, 4
		addi $t0, $t0, 1
	j loop
	
	jr $ra

find:
	move $a0, $t0
	li $v0, 1
	syscall
	
end:	
	li $v0, 10
	syscall
