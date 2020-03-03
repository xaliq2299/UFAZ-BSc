.data
retChar: .asciiz "\n"
spaceChar: .asciiz " "
array: .word 0, 11, 2, 13, 4, 15, 6, 17, 8, 19
size: .word 10

.text
main:
#try to print first ans second element of the array
	#lw $t2, size
	#la $t0, array
	#li $t1, 0
	li $a0, 10
	la $a1, array
	li $a2, 11

loop:   bgt $t1, $t2, exit
	lw $a0, 0($t0) #without 0? 6 bits, 5bits, 5bits
	li $v0, 1
	syscall
	la $a0, spaceChar
	li $v0, 4
	syscall
	addi $t1, $t1, 1
	addi $t0, $t0, 4 #4 here is offset (means adding smth to an address)
	j loop

exit:   li $v0 10
        syscall
        
findPlace: 
	subu $sp $sp 16
	sw $a0 12($sp)
	sw $a1 8($sp)
	sw $a2 4($sp)
	sw $ra 0($sp)
	
	mul $a0, $a0, 4
	li $t0, 0

loopFind: 
	bge $t0, $a0, endFind  
	add $t1, $a1, $t0 
	lw $t2, 0($t1)
	blt $a2, $t2, endFind
	addi $t0, $t0, 4
	j loopFind

endFind: li $v0, 10
	syscall
			
	lw $a2 12 ($sp)
	lw $a1 8($sp)
	lw $a0 4($sp)
	lw $ra 0($sp)
	addu $sp $sp 16
	jr $ra

		
