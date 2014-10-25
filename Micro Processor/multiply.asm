.model small
  data segment
  a dw 0008H
  b dw 0002H
ends

code segment
  assume cs:code,ds:data
  start:
    mov ax,data
    mov ds,ax
    mov ax,a
    mov bx,b
    mul bx  ;add ax, bx ;div bx ;sub ax,bx
    hlt
ends

end start 
