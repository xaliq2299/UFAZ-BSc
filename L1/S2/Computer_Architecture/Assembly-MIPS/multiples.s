.text
main:
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	li $t2, 1
	
loop:	bgt $t2, $t1, exit	
	rem $t3, $t
	
exit:	li $v0 10
	syscall