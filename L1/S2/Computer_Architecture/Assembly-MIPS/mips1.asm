.data
array: .word 0 4 7 8 9 
newLine: .asciiz "\n"
message: .asciiz "Found: in index "

.text
main:	#li $t0, 0
	#li $s0, 5
	#la $s1, array
	#j printing
	
	li $a0, 5
	la $a1, array
	li $v0, 5
	syscall
	move $a2, $v0
	jal findPlace
	move $a0, $v0
	li $v0, 1
	syscall
	j exit
		
printing:
	loop: beq $t0, $s0, endLoop
	
	lw $a0, ($s1)
	li $v0, 1
	syscall
	la $a0, newLine
	li $v0, 4
	syscall
	
	add $s1, $s1, 4
	addi $t0, $t0, 1
	j loop 
	
endLoop: li $v0, 10
	 syscall

exit:	li $v0, 10
	syscall

findPlace:
	subu $sp, $sp, 12
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a2, 8($sp)
	sw $ra, 12($sp)
	
	li $t0, 0
	loopFind:
		beq $t0, $a0, endLoop
		lw $t1, ($a1)
		beq $a2, $t1, Found
		addi $a1, $a1, 4
		addi $t0, $t0, 1
	j loopFind
	
	lw $ra, 12($sp)
	lw $a2, 8($sp)
	lw $a1, 4($sp)
	lw $a0, 0($sp)
	addu $sp, $sp, 12
	jr $ra

Found: 
	la $a0, message
	li $v0, 4
	syscall
	move $a0, $t0
	li $v0, 1
	syscall