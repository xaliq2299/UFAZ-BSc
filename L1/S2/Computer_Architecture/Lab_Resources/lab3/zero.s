.data
message: .asciiz "This integer is zero\n"

.text
main:
	 # ... 
	 beq $t0 $0 zero # If $t0 == $0 go to zero
         j exit
zero:
	 la $a0 message
	 li $v0 4
	 syscall
exit:
         li $v0 10
	 syscall
