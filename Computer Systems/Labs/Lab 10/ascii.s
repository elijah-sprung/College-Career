/*
        Elijah Sprung
        Find the numerical digit of an ascii code stored in r0 if 30 <= n <= 39, put the numebrical digit vlaue
        back in r0 or if it is a non-number ascii code, change the ascii code to 50 and put it in r0.
*/

.global main

main:

        mov     r1, #31

        cmp     r1, #30
        blt     invalid

        cmp     r1, #39
        bgt     invalid

        b       valid

valid:

        sub     r2, r1, #30
        mov     r0, r2
        b       end

invalid:

        mov     r0, #50
        b       end

end:

        bx lr