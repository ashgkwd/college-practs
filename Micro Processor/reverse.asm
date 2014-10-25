.model small
data segment
  mystr db 'sonia'
ends

code segment
  assume cs:code,ds:data
  start:
    mov ax,data
    mov ds,ax
    mov ax,0000h
    mov bx,0000h
    mov cx,0002h
    lea si,mystr
    lea di,mystr+3
  up:
    mov al,[si]
    mov bl,[di]
    xchg al,bl
    mov [si],al
    mov [di],bl
    inc si
    dec di
    loop up
ends

end start
