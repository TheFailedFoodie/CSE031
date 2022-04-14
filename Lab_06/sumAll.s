	.data
str1:	.asciiz  "Enter a Number: "
oSum:	.asciiz  "\nSum of Odd Numbers: \n"
eSum:	.asciiz "Sum of Even Numbers: \n"
	.text
main:
	li $v0, 1	
	
loop:
	beq $v0, $zero, fin
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 5
	syscall
	
	addi $s0, $v0, 0
	rem $t1, $s0, 2
	beq $t1, $zero, even
	bne $t1, $zero, odd
	
fin:
	li $v0, 4
	la $a0, eSum	
	syscall
	
	li $v0, 1
	la $a0, ($t2)
	syscall
	
	li $v0, 4
	la $a0, oSum
	syscall
	
	li $v0, 1
	la $a0, ($t3)
	syscall
	
	li $v0, 10
	syscall
	
even:
	add $t2, $t2, $s0
	j loop
	
odd:
	add $t3, $t3, $s0
	j loop
	