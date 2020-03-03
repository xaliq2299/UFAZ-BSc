.data
hello: .asciiz "hello, world\n" # hello points to the string

.text
main:
la $a0 hello # Put in $a0 the address of the string to print
li $v0 4     # Put in $v0 the syscall code for printing a string
syscall      # Call the system
j exit       # Jump to the end of the program 

exit:
li $v0 10    # Put in $v0 the syscall code to stop the program
syscall      # Call the system
