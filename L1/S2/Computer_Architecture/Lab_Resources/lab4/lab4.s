.data 
retChar:      .asciiz "\n"
msgArray:     .asciiz "Array of size: "
msgAtAddress: .asciiz "at address: "
msgAddress:   .asciiz "Address of the first array entry: "
msgPlace:     .asciiz "Place of the integer in the array: "

.text
main:

li   $s0 0          # Number of integers in $s0 (saved by functions)
move $a0 $s0
li   $a1 0
jal  createArray
move $s1 $v0        # $s1: address of the first byte in the array

##################### Print the address of the array
la   $a0 msgAddress
li   $v0 4
syscall
move $a0 $s1
jal  printInteger
##################### Print the content of the array

move $a0 $s0
move $a1 $s1
jal  printArray

##################### Test function findPlace with a sorted array
la   $a0 msgPlace
li   $v0 4
syscall
move $a0 $s0
move $a1 $s1
li   $a2 5
jal  findPlace
move $a0 $v0
jal  printInteger
la   $a0 retChar
li   $v0 4
syscall
#####################

##################### Test function findPlaceRec with a sorted array
la   $a0 msgPlace
li   $v0 4
syscall
move $a0 $s0
move $a1 $s1
li   $a2 5
jal  findPlaceRec
move $a0 $v0
jal  printInteger
la   $a0 retChar
li   $v0 4
syscall
#####################

##################### Test function rightShift
move $a0 $s0
move $a1 $s1
jal  rightShift

move $a0 $s0
move $a1 $s1
jal  printArray
#####################

##################### Test function insert
move $a0 $s0
move $a1 $s1
li   $a2 5
jal  insert

move $a0 $s0
move $a1 $s1
jal  printArray
#####################

##################### Test function sort
move $a0 $s0
move $a1 $s1
jal  sort

move $a0 $s0
move $a1 $s1
jal  printArray
#####################

j exit

exit: 
li   $v0 10
syscall

#########################################################
## createArray function
## Allocate memory in the heap to store an array of integers whose size is
## specified as parameter $a0, and initialize it according to a parameter $a1
## to be either sorted with increasing number, sorted with decreasing numbers
## of initialized randomly.
## Arguments:
## - $a0: size of the array
## - $a1: 0: increasingly, 1: decreasingly, 2: randomly
## - $a2: the integer to be placed in the array
## Result values:
## - $v0: address of the first entry of the allocated array
## Pre-conditions:
## - $a0 >= 0
## Post-conditions:
## - if $a0 == 0, then $v0 = 0x00000000
## - Temporary registers $si are restored if used in the function
##
createArray:
# Prologue TODO

# Function's Body TODO

# Epilogue TODO

jr   $ra
#########################################################

#########################################################
## findPlace function
## find the place in a sorted array (i.e., its index in the array)
## where to store an integer for the array to remain sorted
## Arguments:
## - $a0: size of the array
## - $a1: address of the first entry of a sorted array
## - $a2: the integer to be placed in the array
## Result values:
## - $v0: the index where to store $a2 in the array
## Pre-conditions:
## - $a0 >= 0
## - The array is sorted
## Post-conditions:
## - if $a0 == 0, then $v0 = 0
## - Temporary registers $si are restored if used in the function
##
findPlace:
# Prologue TODO

# Function's Body TODO

# Epilogue TODO

jr   $ra
#########################################################

#########################################################
## findPlaceRec function
## find the place in a sorted array (i.e., its index in the array)
## where to store an integer for the array to remain sorted
## Arguments:
## - $a0: size of the array
## - $a1: address of the first entry of a sorted array
## - $a2: the integer to be placed in the array
## Result values:
## - $v0: the index where to store $a2 in the array
## Pre-conditions:
## - $a0 >= 0
## - The array is sorted
## Post-conditions:
## - if $a0 == 0, then $v0 = 0
## - Temporary registers $si are restored if used in the function
##
findPlaceRec:
# Prologue TODO

# Function's Body TODO

# Epilogue TODO

jr   $ra
#########################################################

#########################################################
## rightShift function
## achieves a 4-byte right-shift of a whole array
## Arguments:
## - $a0: size of the array
## - $a1: address of the first entry of the array
## Result values:
## - N/A
## Pre-conditions:
## - $a0 >= 0
## - The 4 bytes after the array may be written
## Post-conditions:
## - Array is shifted 4 bytes on the rigth
## - Temporary registers $si are restored if used in the function
##
rightShift:
# Prologue TODO

# Function's Body TODO

# Epilogue TODO

jr   $ra
#########################################################

#########################################################
## insert function
## insert an integer n a sorted array in such a way that it remains sorted
## Arguments:
## - $a0: size of the array
## - $a1: address of the first entry of the array
## - $a2: integer to be inserted in the array
## Result values:
## - N/A
## Pre-conditions:
## - $a0 >= 0
## - The array of size $a0 starting at $a1 is sorted
## - The 4 bytes after the array may be written
## Post-conditions:
## - The array of size ($a0 + 1) starting at $a1 is sorted
## - Temporary registers $si are restored if used in the function
##
insert:
# Prologue TODO

# Function's Body TODO

# Epilogue TODO

jr   $ra
#########################################################

#########################################################
## sort function
## sort an array of integer
## Arguments:
## - $a0: size of the array
## - $a1: address of the first entry of the array
## Result values:
## - N/A
## Pre-conditions:
## - $a0 >= 0
## Post-conditions:
## - The array of size $a0 starting at $a1 is sorted
## - Temporary registers $si are restored if used in the function
##
sort:
# Prologue TODO

# Function's Body TODO

# Epilogue TODO

jr   $ra
#########################################################

#########################################################
## printArray function
## print the content of an array
## Arguments:
## - $a0: size of the array
## - $a1: address of the first entry of the array
## Result values:
## - N/A
## Pre-conditions:
## - $a0 >= 0
## Post-conditions:
## - Temporary registers $si are restored if used in the function
##
printArray:
# Prologue
subu $sp $sp 24
sw   $s0 20($sp)
sw   $s1 16($sp)
sw   $s2 12($sp)
sw   $a0 8($sp)
sw   $a1 4($sp)
sw   $ra 0($sp)

# Function's Body
la   $a0 msgArray
li   $v0 4
syscall
lw   $a0 8($sp)
jal  printInteger
la   $a0 msgAtAddress
li   $v0 4
syscall
lw   $a0 4($sp)
jal  printInteger

lw   $a0 8($sp)
lw   $a1 4($sp)

li   $s0 4
mul  $s2 $a0 $s0    # $a0: array's number of bytes
li   $s1 0          # $s1: offset
printLoop:
bge  $s1 $s2 endPrintLoop
lw   $a1 4($sp)
add  $t0 $a1 $s1    # Integer's address = array's address + offset
lw   $a0 0($t0)
jal  printInteger
addi $s1 $s1 4      # Increment the offset
j    printLoop

endPrintLoop:
la   $a0 retChar
li   $v0 4
syscall

# Epilogue
lw   $s0 20($sp)
lw   $s1 16($sp)
lw   $s2 12($sp)
lw   $a0 8($sp)
lw   $a1 4($sp)
lw   $ra 0($sp)
addu $sp $sp 24
jr   $ra
#########################################################

#########################################################
## printInteger function
## print an integer
## Arguments:
## - $a0: integer to print
## Result values:
## - N/A
## Pre-conditions:
## - N/A
## Post-conditions:
## - Temporary registers $si are restored if used in the function
##
printInteger:
# Prologue
subu $sp $sp 8
sw   $a0 4($sp)
sw   $ra 0($sp)

# Function's Body
li   $v0 1
syscall
la   $a0 retChar
li   $v0 4
syscall

# Epilogue
lw   $a0 4($sp)
lw   $ra 0($sp)
addu $sp $sp 8
jr   $ra
#########################################################
