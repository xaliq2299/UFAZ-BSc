.data
retChar:     .asciiz "\n"
.text
main:
li $a0, 42
jal printInt
j exit
####################################
## printInt funtion
## Print an integer then a newline
## Arguments: $a0: integer to print
##
printInt:
	# Function’s prologue:
	subu $sp $sp 8
	sw $a0 4($sp)
	sw $ra 0($sp)
	# Function’s body:
	li $v0 1
	syscall
	la $a0 retChar
	li $v0 4
	syscall
	# Function’s epilogue:
	lw $a0 4($sp)
	lw $ra 0($sp)
	addu $sp $sp 8
	jr $ra
	####################################
exit:
	li $v0 10
	syscall
