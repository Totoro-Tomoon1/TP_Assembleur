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

asm_calc PROC
    
    cmp rcx, 0
    je br_add
    cmp rcx, 1
    je br_sub
    cmp rcx, 2
    je br_mul
    cmp rcx, 3
    je br_div

br_add:
    mov rax, rdx
    add rax, r8
    ret

br_sub:
    mov rax, rdx
    sub rax, r8
    ret

br_mul:
    mov rax, rdx
    imul rax, r8
    ret

br_div:
    mov rax, rdx
    cqo
    idiv r8
    ret

asm_calc ENDP

asm_calc_f PROC
    
    cmp rax, 0
    je br_add
    cmp rcx, 1
    je br_sub
    cmp rcx, 2
    je br_mul
    cmp rcx, 3
    je br_div

br_add:
    movsd xmm0, xmm1
    addsd xmm0, xmm2
    ret

br_sub:
    movsd xmm0, xmm1
    subsd xmm0, xmm2
    ret

br_mul:
    movsd xmm0, xmm1
    mulsd xmm0, xmm2
    ret

br_div:
    movsd xmm0, xmm1
    divsd xmm0, xmm2
    ret

asm_calc_f ENDP

END