#a MIPS program about returning a value by function
Add:
	jal New
	li $s1, 42
	add $s1, $s1, $v0
	move $a0, $s1
	li $v0, 1
	syscall
	j exit 
New: 
	li $v0, 5
	syscall
	jr $ra

exit: li $v0, 10
	syscall
