.model small
data segment
  myString db "kira"
  toSearch db "r"
  pos dw ?
ends

code segment
  assume cs:code,ds:data
  start:
    mov ax,data
    mov ds,ax
    mov ah,toSearch
    mov al,00h
    mov bx,0000h
    mov cx,0003h
    lea si,myString
  up:
    mov al,[si]
    cmp ah,al
    jne nxt
    inc bx  ;last occurence of toSearch
  nxt:
    inc si
    loop up
    mov pos,bx
    int 21h  ;hlt
code ends
end start