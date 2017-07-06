$NOLIST
$nomod51
$INCLUDE (c:/reg832.pdf)
$LIST
stack_init	equ 07fh
; testprogramma om een bewerking [+,-,*,/] van 2 floating point 32b ieee754 te berekenen met functies uit f32_asmd.inc
;	gebruik fpcalc.exe (zie fpcalc_readme.txt voor uitleg) om een f32_asm_test.inc te generen
	org 0000h
	ljmp start	
start:	
	mov	sp,#stack_init ;stack pointer init	
		
;-------------------------------------------------------
$INCLUDE (C:\bach\test_inc\f32_asmd_test.inc)
;-------------------------------------------------------	
lus: 		
	ljmp 	lus               
$INCLUDE (C:\bach\f32_asmd.inc)
end