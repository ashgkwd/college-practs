.model small
data segment
  dvd dd 00000028h
  dvr dw 0002h
  quot dw 0000h
  rem dw 0000h
ends ;same as "data ends"

code segment
  assume cs:code, ds:data
  start:
    mov ax,data
    mov ds,ax
    mov ax,word Ptr[dvd]
    mov dx,word Ptr[dvd+2]
    mov cx,dvr
    div cx
    mov quot,ax
    mov rem,dx
    int 21h  ;hlt
ends

end start  ;set entry point and stop the assembler