.data
message1: .asciiz "Enter first integer: "
message2: .asciiz "Enter second integer: "
result:   .asciiz "Sum: "

.text
main:
	la $a0, message1
	li $v0, 4
	syscall
	jal read_int
	move $a1, $v0
		
	la $a0, message2
	li $v0, 4
	syscall
	jal read_int
	move $a2, $v0
	
	jal print_string
	addu $a0, $a1, $a2 #always write $a0 to be able to print
	jal print_sum
	j exit
	
print_string:
	la $a0, result
	li $v0, 4
	syscall
	jr $ra	

read_int:
	li $v0, 5
	syscall
	jr $ra
				
print_sum:
	li $v0, 1
	syscall
	jr $ra

exit: 
	li $v0, 10
	syscall