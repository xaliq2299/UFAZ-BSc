.data 
	msg1: .asciiz "Enter number: "   
	msg2: .asciiz "Enter another number: "
	msg3: .asciiz "The second number is greater\n"
	msg4: .asciiz "The first number is greater\n"

.text
main:
	li $v0 4
	la $a0 msg1
	syscall
	
	li $v0 5
	syscall
	move $t0, $v0
	
	li $v0 4
	la $a0 msg2
	syscall
	
	li $v0 5
	syscall
	move $t1, $v0
	
	bgt $t1, $t0 greater
	j exit
	
greater:
	li $v0, 4
	la $a0, msg3
	syscall
	li $v0, 10
	syscall

exit: 
	li $v0, 4
	la $a0, msg4
	syscall
	li $v0, 10
	syscall
