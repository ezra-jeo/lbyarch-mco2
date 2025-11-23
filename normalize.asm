section .data
PIXEL_SIZE dq 255.0

section .bss
count resq 1
input resq 1
output resq 1000*1000 ; biggest possible

section .text
 bits 64
 default rel
global imgCvtGrayIntToDouble
imgCvtGrayIntToDouble:
    ; Push non volatile registers
    PUSH RSI 
    PUSH RDI
    
    XOR RAX, RAX
    MOV RAX, RCX ; Row  
    IMUL RDX ; Col
    
    MOV qword [count], RAX ; Store count
    
    MOV qword [input], R8 ; Input image address

    CALL cvtToSDNormalize
   
    LEA RAX, qword [output]
    
    ; Restore values
    POP RSI 
    POP RDI
    RET

cvtToSDNormalize:
    XOR R10, R10
    
    ; Pointer variable
    MOV RSI, qword [input]
    LEA RDI, qword [output]
    
    cvtToSDLoop:
        ; Store to var convert to double float
        CMP R10, qword [count]
        JE cvtToSDEnd
        
        ; Use the temp
        XOR RAX, RAX
        MOV AL, byte [RSI + R10]
        
        ; Convert to double float
        CVTSI2SD XMM1, RAX
        
        ; Divide by 255
        DIVSD XMM1, qword [PIXEL_SIZE]
        
        MOVSD qword [RDI + R10 * 8], XMM1
        
        INC R10
        JMP cvtToSDLoop
        
    cvtToSDEnd:
        RET 
    

 