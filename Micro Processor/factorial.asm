.model small
data segment
  a dw 0005H
ends ;same as "data ends"

code segment
  assume cs:code,ds:data
  start:
    mov ax,data
    mov ds,ax
    mov ax,0001H
    mov bx,a
  factorial:
    mul bx
    dec bx
    jnz factorial
    hlt
ends

end start ;set entry point and stop the assembler
