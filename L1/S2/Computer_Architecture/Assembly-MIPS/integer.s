.data
message: .asciiz "Enter an integer: "

.text
main:
	la $a0, message
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	move $a0, $v0
	
	li $v0, 1
	syscall