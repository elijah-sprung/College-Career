/*
evenSum.s
Elijah Sprung
*/

.global main

main:

        mov r0, #0
        mov r1, #0
        mov r2, #22
        mov r3, #0
        mov r4, #1
        mov r5, #2
        mov r6, #0

        b while_loop

while_loop:

        while_condition:

                cmp r3, r2
                bgt end_loop

                udiv r7, r3, r5
                mul r8, r7, r5
                sub r9, r3, r8

                cmp r9, r6
                beq sum

                add r3, r3, r4
                b while_condition

end_loop:

        bx lr

sum:

        add r0, r0, r3
        add r3, r3, r4
        b while_loop