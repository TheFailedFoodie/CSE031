	.data
n:	.word 25
intro:	.asciiz "Enter a Number: \n"
str1:	.asciiz "Less than\n"
str2:	.asciiz "Less than or equal to\n"
str3:	.asciiz "Greater than\n"
str4:	.asciiz "Greater than or equal to\n"
	
	.text
main:	
	li $v0, 4
	la $a0, intro
	syscall
	
	li $v0, 5
	syscall
	
	move $t1, $v0
	
	la $t0, n
	lw $t0, 0($t0)
	
	slt $t2, $t1, $t0
	beq $t2, $zero, greater
	j lesser
	
fin:	
	li $v0, 10
	syscall
	
greater:
	li $v0, 4
	la $a0, str3
	syscall
	j fin

lesser:
	li $v0, 4
	la $a0, str1
	syscall
	j fin