.data
ask: .asciiz "Enter an integer: "

.text
main:
li $v0, 4
la $a0, ask
syscall

li $v0, 5
syscall
move $t0, $v0
li $t1, 1

loop: bgt $t1 $t0 end
      move $a0, $t1
      li, $v0, 1 
      syscall
      addi $t1, $t1, 1
	j loop

end: li $v0, 10
	syscall
