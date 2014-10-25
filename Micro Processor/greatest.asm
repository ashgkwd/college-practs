.model small
data segment
  myArray db 00h,12h,74h,05h,07h
  result db(?)
ends

code segment
  assume cs:code,ds:data
  start:
    mov ax,data
    mov ds,ax
    mov di,offset[myArray]
    mov cx,0004h
    mov ax,0000h
    mov al,[ds:di]
  up:
    inc di
    cmp al,[di]
    jnc down
    mov al,[di]
  down:
    loop up
    mov result, al
    int 21h
ends

end start
