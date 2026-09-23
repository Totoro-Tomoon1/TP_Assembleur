option casemap:none     ; noms sensibles à la casse (comme en C++)

.data                   ; variables globales initialisées
counter QWORD 0

.const                  ; données en lecture seule
message BYTE "hello", 0

.code                   ; code
asm_add PROC
    lea     rax, [rcx + rdx]
    ret
asm_add ENDP

asm_find PROC

    mov rax, -1
    xor r10, r10
    mov r9d, DWORD PTR [rcx]

check:
    cmp r9, r8
    je same
    inc r10d
    cmp r10, rdx
    je end_branch
    mov r9d, DWORD PTR [rcx + r10 * 8]
    jmp check

same:
    mov rax, r10
    add rax, 1
    jmp end_branch

end_branch:
    ret
asm_find ENDP

END