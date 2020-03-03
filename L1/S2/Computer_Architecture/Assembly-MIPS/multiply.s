main:
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 5
	syscall
	move $t1, $v0
	li $t2, 0
	
loop:   beq $t2, $t1, exit
	addu $t2, $t2, $t0
	j loop

	move $t2, $a0
	li $v0 1
	syscall

exit:   li $v0 10
	syscall