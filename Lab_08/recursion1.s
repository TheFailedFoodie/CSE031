        .data

str1:    .asciiz "Please enter a number: "

        .text
main: 	
	addi $sp, $sp, -4
	
        la $a0, str1
        li $v0, 4
        syscall
		
        li $v0, 5
        syscall
        add $a0, $0, $v0
		
	jal rec
		
	add $a0, $0, $v0
        li $v0, 1
        syscall
	j end


rec:	
	addi $sp, $sp, -12

        sw $ra, 0($sp)
        sw $v0, 4($sp)

	bne $a0, 10, notTen
		
        li $v0, 2
	j end_recur
			
notTen:   
	bne $a0, 11, notEleven
	li $v0, 1
	j end_recur

notEleven:	
	sw $a0, 8($sp)
	addi  $a0, $a0, 2
	add $v0, $a0, $0
		
	jal rec
		
        sw $v0, 4($sp)
		
	lw $a0, 8($sp)
	addi $a0, $a0, 1
		
	jal rec
		
	lw $t0, 8($sp)
	lw $t1, 4($sp)
        add $v0, $t0, $v0
        add $v0, $t1, $v0
		
	j end_recur
		
end_recur:
	lw $ra, 0($sp)
	addi $sp, $sp, 12
	jr $ra

end:	
	addi $sp, $sp 4
	li $v0, 10
	syscall