/* -- myMod.s */

/*
  Program made to perform the modulous function as there is not one in Assemly.

  x%y = mod
  a = x / y
  b = a * y
  mod = x - b
*/

.global main

main:

  mov r1, #69           /* x = 69 */
  mov r2, #15           /* y = 15 */

  udiv r3, r1, r2       /* a = 69 / 15 */

  mul r4, r3, r2        /* b = 4 * 15 */

  sub r0, r1, r4        /* mod = 69 - 60 */

  bx lr