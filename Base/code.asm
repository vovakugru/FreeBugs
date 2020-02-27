main:
    mov eax, x
    mov result, eax
    imul a// a^3
    mov a3, eax
    imul a2
    add result, eax
    mov eax, a3
    add result, eax
    end