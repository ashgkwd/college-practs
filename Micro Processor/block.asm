.model small
data segment
  block1 db 10h,20h,30h,40h
  block2 db 4(?)
ends

code segment
  assume cs:code,ds:data
  start:
    mov ax,data
    mov ds,ax
    lea si,block1
    xor si,si
    lea di,block2
    xor di,di
    mov cx,0004h
    mov bx,0000h
  up:
    mov bl,[si]
    mov [di],bl
    inc si
    inc di
    loop up
    int 21h
ends

end start
