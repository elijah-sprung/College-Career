/*
        Elijah Sprung
        Returns the smaller of 2 numbers in r1 and r2.
*/

.global main

main:

        mov     r1, #69
        mov     r2, #15

        cmp r1, r2

        bgt     one_large
        blt     two large
        beq     both_same

one_large:

        mov     r0, r2
        b       end

two_large:

        move    r0, r1
        b       end

are_equal:

        mov     r0, r1
        b       end

end:

        bx lr