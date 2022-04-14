.data
	x:	.word 2
	y:	.word 3
	z:	.word 4
.text
MAIN:
	# set x, y, and z into s0, s1, and s2 respectively
	la $t0 x
	lw $s0 0($t0)
	la $t0 y
	lw $s1 0($t0)
	la $t0 z
	lw $s2 0($t0)
	
	#set s0, s1, and s2 as input arguments
	add $a0 $zero $s0
	add $a1 $zero $s1
	add $a2 $zero $s2
	
	#jumps and links to main
	jal FOO
	
	#jump to the end
	j END
	
FOO:
	#saves jump location and values so that the nested function can work correctly
	addi $sp $sp -16
	sw $ra 0($sp)
	sw $a0 4($sp)
	sw $a1 8($sp)
	sw $a2 12($sp)
	
	#sets the input values for BAR
	add $a0 $a0 $a1
	add $a1 $a1 $a2
	add $a2 $a2 $a0
	
	#jumps to BAR0 for p and places the link in $ra
	jal BAR0
	
	#jumps to BAR1 for q and places the link in $ra
	jal BAR1
	
	#adds up the results from BAR0 and BAR1 to find the correct return value
	add
	
	#replaces the jump location and values so that the function leads to the right place and has previous values to work with
	lw $ra 0($sp)
	lw $a0 4($sp)
	lw $a1 8($sp)
	lw $a2 12($sp)
	addi $sp $sp 16
	jr $ra

BAR0:
	mult
	jr $ra
	
BAR1:
	

END:
	li $v0 10
	syscall