.data

name: .asciiz "Anson"
age: .word 20

.text
li $t1, 1
li $t2, 2
add $t3, $t1, $t2

addi $sp, $sp, -4
sw $t3, 0($sp)
