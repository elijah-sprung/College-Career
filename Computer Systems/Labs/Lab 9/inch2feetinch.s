/* inch2feetinch.s */

/*
  Program to convert inches into feet and inches.

  The results for feet are in register 11 and inches in register 12.

  To do this, modulus should be used.
*/

.global main

main:

  mov r1, #69
  mov r2, #12

  udiv r11, r1, r2
  mul r3, r11, r2
  sub r12, r1, r3

  bx lr