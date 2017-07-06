;******************************************************************************
;
; f32_asmd_dbg.inc 
; Is een include file voor het gebruik van de 4 basisoperaties (+,-,*,/) 
; op twee floating point getallen in ieee754 32bit voorstellinng
; voor een aduc832 systeem. 
; Deze file bevat dezelfde functionaliteit als f32_asmd.inc met meer commentaar
;
; Beschikbare routines:
; fadd32, fsub32, fmul32, fdiv32
;******************************************************************************
;*******************************************************************************
; fadd32        (131,9us @16.777216MHz)
; Deze routine berekent de optelling van twee floating point getallen (r7-r4 en r3-r0)  in IEEE754 32bit voorstelling 
; met resultaat in r3-r0. 
; Bij overflow/underflow/NaN of een invalid operation wordt deze fouttoestand aangegeven met bijhorende statusvlaggen. 
;              
; Inputbereik getallen:  0x80000001..0x7f7fffff
;							+-1.4E-45..3.4028235E38
;			
;                         
; input:     r3,r2,r1,r0 = acc0 
;            r7,r6,r5,r4 = acc1       
;                
; output:    resultaat in r3,r2,r1,r0
;            
;			 f0=0,cy=1,ov=0	invalid operation
;         		 f0=0,cy=1,ov=1 NaN
;			 f0=0,cy=1,ov=1 overflow (+INF)
;			 f0=0,cy=0,ov=1	underflow (-INF)
;			 f0=1,cy=0,ov=1	niet-genormaliseerd
;			 f0=1,cy=0,ov=0	nul
;			 f0=0,cy=0,ov=0 geen vlags	 
;			 f0=1,cy=1,ov=0 ongebruikt
;                                      
; vernietigt:  niets
;*******************************************************************************
fadd32:
	;operaties om volgende registers op te stack te plaatsen
	;	 r7,r6,r5,r4 
	;        acc,B 
	push	acc
	push	B
	mov	A,r7
	push	acc
	mov	A,r6
	push	acc
	mov	A,r5
	push	acc
	mov	A,r4
	push	acc
	push	psw
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;
	
	;---------------------------
	;lezen
	;
	;	Getal A:
	;		  r3	    r2	      r1      r0
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  
	;	omvormen naar
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM 
	;
	;	Getal B:
	;		   r7	    r6	      r5      r4
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 
	;	omvormen naar
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM 
	;
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;	      0000000S
	;		sign(B)
	;	       0000000S
	;		-top-
	
	;getal A
	clr C
	mov	A,r2
	rlc	A
	
	mov	A,r2
	setb	acc.7 ; 24ste msb implicit op '1' zetten
	mov	r2,A		
	
	mov	A,r3
	rlc	A
	mov	r3,A
	clr	A
	addc	A,#0h
	push	acc ; sign(A)
	
	;getal B
	clr C
	mov	A,r6
	rlc	A
	
	mov	A,r6
	setb	acc.7 ; 24ste msb implicit op '1' zetten
	mov	r6,A		
	
	mov	A,r7
	rlc	A
	mov	r7,A
	clr	A
	addc	A,#0h
	push	acc ; sign(B) op stack zetten	
	;einde lezen
	;---------------------------
	
	;---------------------------
	; Testen op INF/NaN
 	; exp r3 (r7) == #0FFh 
 	cjne	r7,#0FFh,fadd32_inputtest_a
 	cjne	r3,#0FFh,fadd32_infnan_b
	ljmp	fadd32_nan
fadd32_inputtest_a:
	cjne	r3,#0FFh,fadd32_inputtest_end
	ljmp	fadd32_infnan_a
fadd32_inputtest_end:
	ljmp	fadd32_inputvalid	
fadd32_infnan_b:
	;INF/NaN?
	;b mantisse testen op zero
	mov	A,r6 ;combineer mantisse b argument
	orl 	A,r5
	orl 	A,r4
	jnz	fadd32_nan ;niet nul dan NaN	
	;INF
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;		sign(B)
	;		-bottom-	
	pop	acc
	jz	fadd32_infnan_b_p
	pop	acc	;sign(A)
	ljmp	fadd32_infnan_n
fadd32_infnan_b_p:
	pop	acc 	;sign(A)
	ljmp	fadd32_infnan_p	
fadd32_infnan_a:
	;INF/NaN?
	;a mantisse testen op zero
	mov	A,r2 ;combineer mantisse a argument
	orl 	A,r1
	orl 	A,r0
	jnz	fadd32_nan ;niet nul dan NaN
	;INF
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;		sign(B)
	;		-bottom-
	pop	acc
	pop 	acc
	jz	fadd32_infnan_p
fadd32_infnan_n:
	;sign(A) == 1
	; underflow (-INF) 
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	;	 f0=0,cy=0,ov=1	underflow (-INF)
	pop	psw	
	setb 	f0
	clr	C
	setb	OV	
	mov	r3,#0FFh	
	ljmp	fadd32_inf_end
fadd32_infnan_p:
	;sign(A) == 0
	; underflow (+INF) 	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	;	f0=0,cy=1,ov=1 overflow (+INF)	
	pop	psw	
	setb f0
	setb	C
	setb OV		
	;   r3	    r2	      r1      r0
	;Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  	
	;   r3	    r2	      r1      r0
	;0111111 1MMMMMMM MMMMMMMM MMMMMMMM  
	mov	r3,#07Fh	
fadd32_inf_end:
	mov 	r2,#080h
	mov	r1,#000h	
	mov	r0,#000h	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc	
	ret	
fadd32_nan:
	pop acc ;sign(B)
	pop acc ;sign(A)
	;NaN
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	pop	psw	
	;         f0=0,cy=1,ov=1 NaN
	clr	f0	
	setb	cy
	setb	ov	
	;   r3	    r2	      r1      r0
	;Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  	
	mov	r3,#0FFh ; NaN teruggeven r3=0FFh r2-r0 nonzero 
	mov	r2,#0FFh
	mov	r1,#0FFh
	mov	r0,#0FFh	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc		
	ret		
	;einde input testen
	;---------------------------
	
	;---------------------------
fadd32_inputvalid:
	; getallen en exponenten testen
	;  abs(A)>abs(B)
	;   r3 > r7 ; '>' OK ;  '<' swap ; '==' gelijk
	;   r2 > r6 ; '>' OK ;  '<' swap ; '==' gelijk
	;   r1 > r5 ; '>' OK ;  '<' swap ; '==' gelijk
	;   r0 > r4 ; '>' OK ;  '<' swap ; '==' gelijk
	;
	;     r3,r2,r1,r0 
	;     r7,r6,r5,r4
	;   - -----------
	; [C]   ,  ,  ,A
	;
	clr	C
	mov	A,r0
	subb	A,r4
	mov	A,r1
	subb	A,r5
	mov	A,r2
	subb	A,r6
	mov	A,r3
	subb	A,r7	
	jc	fadd32_swap	; c='1' A<B swap
	; A>=B
	ljmp	fadd32_equalize
fadd32_swap:
	; A en B swappen
	mov	A,r0	;r0<->r4
	xch	A,r4
	mov	r0,A
	
	mov	A,r1	;r1<->r5
	xch	A,r5
	mov	r1,A
	
	mov	A,r2	;r2<->r6
	xch	A,r6
	mov	r2,A
	
	mov	A,r3	;r3<->r7
	xch	A,r7
	mov	r3,A
	
	;sign op stack swappen
	;  STACK:
	;	sign(A) 
	;	sign(B)
	;	-bottom-
	pop	b
	pop	acc
	push	b
	push	acc
	
fadd32_equalize:
	; abs(A)>abs(B)
	; exp(B) inc totdat exp(A)==exp(B)
	; exp(A) ?== exp(B)
	mov	A,r7 ;exp(A) ?== exp(B)
	xrl	A,r3 ;r7 ?== r3
	jz	fadd32_equalize_end ; exp(A) == exp(B)
	inc	r7 ; exp(B) inc
	clr	C
	mov	A,r6 ; mantisse(B) right shift
	rrc	A    ; r6,r5,r4 rrc
	mov	r6,A
	
	mov	A,r5
	rrc	A
	mov	r5,A
	
	mov	A,r4
	rrc	A
	mov	r4,A	
	ljmp	fadd32_equalize			
fadd32_equalize_end:	
	; volgens afrondingsregel: trunceren
fadd32_equalize_end_noround:	
	; einde getallen en exponenten testen
	;---------------------------
	
	;---------------------------	
	; mantisse berekenen
	;  testen op teken
	;   sign(A) == sign(B)?
	
	;  STACK:
	;	sign(A) 
	;	sign(B)
	;	-bottom-	
	pop	acc ; sign(B)
	mov	B,A
	pop	acc ; sign(A)
	
	;sign resultaat op stack plaatsen
	push 	acc ; sign(A)
	;  STACK:
	;	sign(resultaat)
	;	-bottom-
	xrl	A,B
	jz	fadd32_mantisse_add ; sign(A) == sign(B)
	;sign(A) != sign(B)
	;mantisse_subb
	;  r2,r1,r0 
	; -r6,r5,r4
	; ---------
	;  r2,r1,r0
	clr	C
	mov	A,r0
	subb	A,r4
	mov	r0,A
	
	mov	A,r1
	subb	A,r5
	mov	r1,A
	
	mov	A,r2
	subb	A,r6
	mov	r2,A
	ljmp	fadd32_mantisse_end		
fadd32_mantisse_add:
	;      r2,r1,r0 
	;     +r6,r5,r4
	;     ---------
	; [C] r2,r1,r0
	mov	A,r0
	add	A,r4
	mov	r0,A
	
	mov	A,r1
	addc	A,r5
	mov	r1,A
	
	mov	A,r2
	addc	A,r6
	mov	r2,A	
fadd32_mantisse_end:
	; einde mantisse berekenen
	;---------------------------
	
	;---------------------------
	;normaliseren
	;   C = '1' bij overflow fadd32_mantisse_add
	; 	mantisse rrc, exp inc
	jnc	fadd32_normalise_start
	
	mov	A,r3 ; exp inc testen of inc -> INF/NaN 
	xrl	A,#0FEh ; #FF-1 (#FE) 1111 1110 + 1 = 1111 1111 INF/NaN
	jz	fadd32_inf_res
	inc	r3
	
	mov	A,r2 ; mantisse(A) right shift
	rrc	A    ; r2,r1,r0 rrc
	mov	r2,A
	
	mov	A,r1
	rrc	A
	mov	r1,A
	
	mov	A,r0
	rrc	A
	mov	r0,A		
		
	ljmp	fadd32_normalise_start
fadd32_inf_res:
	;!resultaat INF met teken sign(resultaat)
	;  STACK:
	;	 ...
	;	sign(resultaat)
	;	-bottom-
	; underflow (-INF)
	pop	acc
	jz	fadd32_inf_res_p
	ljmp	fadd32_infnan_n
fadd32_inf_res_p:
	ljmp	fadd32_infnan_p
	
fadd32_normalise_start:
    ; testen op normalisatie MSB van mantisse(res) == '1'
	;	 zoniet normaliseren
	mov	A,r2
fadd32_normalise_loop:
	jb	acc.7,fadd32_norm_end ; MSB van mantisse(res) == '1' 
	;  normaliseren
	;   exp dec	
	;   mantisse left shift
	mov	A,r3
	jz	fadd32_norm_end_nnormz ;exp = 0, nul of gedenormaliseerd	
	
	dec	r3 ; exp(res) dec
	
	clr	C ; mantisse(res) left shiften
	mov	A,r0
	rlc	A
	mov	r0,A
	
	mov	A,r1
	rlc	A
	mov	r1,A
	
	mov	A,r2
	rlc	A
	mov	r2,A	
	ljmp fadd32_normalise_loop

fadd32_norm_end_nnormz:
	;testen norm of zero
	; voor mantisse(res) testen jz
	;	 f0=1,cy=0,ov=0	nul
	mov	A,r2
	orl	A,r1
	orl	A,r0
	jnz	fadd32_norm_end_nnorm	
	; nul
	pop	acc
	pop	psw
	setb	f0
	clr	cy
	clr	ov	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc
	ret		
fadd32_norm_end_nnorm:
	; niet genormaliseerd 
	;	 f0=1,cy=0,ov=1	niet-genormaliseerd
	setb	f0
	clr	cy
	setb	ov
	ljmp	fadd32_res

fadd32_norm_end:
	;einde normaliseren
	;	 f0=0,cy=0,ov=0 geen vlags
	clr	f0
	clr	cy	
	clr	ov
	;---------------------------
	
fadd32_res:
	;---------------------------	
	;  STACK:
	;	sign(resultaat)
	;   0000000S
	;	-bottom-
	;
	;	Getal res:
	;		   r3	   r2	    r1	     r0
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM  
	;	omvormen naar
	;		
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 	
	pop	acc 	
	clr	C
	rrc	A ; sign(res) in CY
	
	mov	A,r3
	rrc	A ; lsb(exp)in CY
	mov	r3,A
		
	mov	A,r2
	mov	acc.7,C
	mov	r2,A
	
	pop	psw
	clr	C
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc
	;einde resultaat
	;---------------------------		
	ret   
	
;*******************************************************************************
; fsub32        (133,8us @16.777216MHz)
; Deze routine berekent de subtractie van twee floating point getallen (r7-r4 en r3-r0)  in IEEE754 32bit voorstelling 
; met resultaat in r3-r0. optelli
; Bij overflow/underflow/NaN of een invalid operation wordt deze fouttoestand aangegeven met bijhorende statusvlaggen. 
;              
; Inputbereik getallen:  0x80000001..0x7f7fffff
;							+-1.4E-45..3.4028235E38
;			
;                         
; input:     r3,r2,r1,r0 = acc0 
;            r7,r6,r5,r4 = acc1       
;                
; output:    resultaat in r3,r2,r1,r0
;            
;			 f0=0,cy=1,ov=0	invalid operation
;         		 f0=0,cy=1,ov=1 NaN
;			 f0=0,cy=1,ov=1 overflow (+INF)
;			 f0=0,cy=0,ov=1	underflow (-INF)
;			 f0=1,cy=0,ov=1	niet-genormaliseerd
;			 f0=1,cy=0,ov=0	nul
;			 f0=0,cy=0,ov=0 geen vlags	 
;			 f0=1,cy=1,ov=0 ongebruikt
;                                      
; vernietigt:  niets
;*******************************************************************************
fsub32:
	;tekenbit acc1 (r7,r6,r5,r4) verwisselen en fadd32 oproepen A-B -> A+(-B)
	;	Getal B:
	;		   r7	    r6	      r5      r4
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 
	;	omvormen naar
	;	     (S*)eeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 
	push	acc
	mov	A,r7
	push	acc
	add	A,#80h ;Sign bit inverteren
	mov	r7,A	
	lcall	fadd32 ;
	pop	acc
	mov	A,r7	
	pop	acc
	ret
	
;*******************************************************************************
; fmul32        (746us @16.777216MHz)
; Deze routine berekent de vermenigvuldiging van twee floating point getallen (r7-r4 en r3-r0)  in IEEE754 32bit voorstelling 
; met resultaat in r3-r0. 
; Bij overflow/underflow/NaN of een invalid operation wordt deze fouttoestand aangegeven met bijhorende statusvlaggen. 
;              
; Inputbereik getallen:  0x80000001..0x7f7fffff
;							-1.4E-45..3.4028235E38
;			
;                         
; input:     r3,r2,r1,r0 = acc0 
;            r7,r6,r5,r4 = acc1       
;                
; output:    resultaat in r3,r2,r1,r0
;            
;			 f0=0,cy=1,ov=0	invalid operation
;         		 f0=0,cy=1,ov=1 NaN
;			 f0=0,cy=1,ov=1 overflow (+INF)
;			 f0=0,cy=0,ov=1	underflow (-INF)
;			 f0=1,cy=0,ov=1	niet-genormaliseerd
;			 f0=1,cy=0,ov=0	nul
;			 f0=0,cy=0,ov=0 geen vlags	 
;			 f0=1,cy=1,ov=0 ongebruikt
;                                      
; vernietigt:  niets
;*******************************************************************************
fmul32:
	;operaties om volgende registers op te stack te plaatsen
	;	 r7,r6,r5,r4 
	;        acc,B 
	push	acc
	push	B
	mov	A,r7
	push	acc
	mov	A,r6
	push	acc
	mov	A,r5
	push	acc
	mov	A,r4
	push	acc
	push	psw
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;
	
	;---------------------------
	;lezen
	;
	;	Getal A:
	;		  r3	    r2	      r1      r0
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  
	;	omvormen naar
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM 
	;
	;	Getal B:
	;		   r7	    r6	      r5      r4
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 
	;	omvormen naar
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM 
	;
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;	      0000000S
	;		sign(B)
	;	       0000000S
	;		-bottom-
	
	;getal A
	mov	A,r2
	rlc	A
	
	mov	A,r2
	setb	acc.7 ; 24ste msb implicit op '1' zetten
	mov	r2,A		
	
	mov	A,r3
	rlc	A
	mov	r3,A
	clr	A
	addc	A,#00h
	push	acc ; sign(A)
	
	;getal B
	mov	A,r6
	rlc	A
	
	mov	A,r6
	setb	acc.7 ; 24ste msb implicit op '1' zetten
	mov	r6,A		
	
	mov	A,r7
	rlc	A
	mov	r7,A
	clr	A
	addc	A,#00h
	push	acc ; sign(B) op stack zetten	
	;einde lezen
	;---------------------------
	
	;---------------------------
	; Testen op 0
	mov	A,r7
	anl	A,r3
	jnz	fmul32_inputtest
	;res=0
	pop	acc
	pop	acc
	mov	r3,#000h	
	mov 	r2,#000h
	mov	r1,#000h	
	mov	r0,#000h	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc	
	ret
fmul32_inputtest:
	; Testen op INF/NaN
 	; exp r3 (r7) == #0FFh 
 	cjne	r7,#0FFh,fmul32_inputtest_a
 	cjne	r3,#0FFh,fmul32_infnan_b
	ljmp	fmul32_nan
fmul32_inputtest_a:
	cjne	r3,#0FFh,fmul32_inputtest_end
	ljmp	fmul32_infnan_a
fmul32_inputtest_end:
	ljmp	fmul32_inputvalid	
fmul32_infnan_b:
	;INF/NaN?
	;b mantisse testen op zero
	mov	A,r6 ;combineer mantisse b argument
	orl 	A,r5
	orl 	A,r4
	jnz	fmul32_nan ;niet nul dan NaN	
	;INF
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;		sign(B)
	;		-bottom-	
	pop	acc
	jz	fmul32_infnan_b_p
	pop	acc	;sign(A)
	ljmp	fmul32_infnan_n
fmul32_infnan_b_p:
	pop	acc 	;sign(A)
	ljmp	fmul32_infnan_p	
fmul32_infnan_a:
	;INF/NaN?
	;a mantisse testen op zero
	mov	A,r2 ;combineer mantisse a argument
	orl 	A,r1
	orl 	A,r0
	jnz	fmul32_nan ;niet nul dan NaN
	;INF
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;		sign(B)
	;		-bottom-
	pop	acc
	pop 	acc
	jz	fmul32_infnan_p
fmul32_infnan_n:
	;sign(A) == 1
	; underflow (-INF) 
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	;	 f0=0,cy=0,ov=1	underflow (-INF)
	pop	psw	
	setb 	f0
	clr	C
	setb	OV	
	mov	r3,#0FFh	
	ljmp	fmul32_inf_end
fmul32_infnan_p:
	;sign(A) == 0
	; underflow (+INF) 	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	;	f0=0,cy=1,ov=1 overflow (+INF)	
	pop	psw	
	setb f0
	setb	C
	setb OV		
	;   r3	    r2	      r1      r0
	;Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  	
	;   r3	    r2	      r1      r0
	;0111111 1MMMMMMM MMMMMMMM MMMMMMMM  
	mov	r3,#07Fh	
fmul32_inf_end:
	mov 	r2,#080h
	mov	r1,#000h	
	mov	r0,#000h	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc	
	ret
	
fmul32_nan:
	pop acc ;sign(B)
	pop acc ;sign(A)
	;NaN
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	pop	psw	
	;         f0=0,cy=1,ov=1 NaN
	clr	f0	
	setb	cy
	setb	ov	
	;   r3	    r2	      r1      r0
	;Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  	
	mov	r3,#0FFh ; NaN teruggeven r3=0FFh r2-r0 nonzero 
	mov	r2,#0FFh
	mov	r1,#0FFh
	mov	r0,#0FFh
	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc		
	ret		
	;einde input testen
	;---------------------------
	
	
	;---------------------------
fmul32_inputvalid:
	;---------------------------
	;exponent berekenen

	; einde exponent berekenen
	;---------------------------
	clr	C
	mov	a,r7
  	subb	a,#126
        add	a,r3
        mov	r3,a ;exponent resultaat
        jnc	fmul32_sign
        ; (+,-) overflow
        ;  STACK:
	;	sign(A) 
	;	sign(B)
	;	-bottom-	
        pop	acc ; sign(B)
        mov	B,A
        pop	acc ; sign(A)
        xrl	A,B
        jz	fmul32_infnan_p	; sign(A) == sign(B) -> +INF
        ljmp	fmul32_infnan_n ; sign(A) != sign(B) -> -INF        
        
 fmul32_sign:	
	;sign berekenen
	;  STACK:
	;	sign(A) 
	;	sign(B)
	;	-bottom-	
	pop	acc ; sign(B)
	mov	B,A
	pop	acc ; sign(A)
	xrl	A,B ; sign(A) == sign(B) -> #00h == res (+)
	push	acc ;sign(A) != sign(B) -> #01h == res (-)
	;  STACK:
	;	sign(resultaat)
	;	-bottom-
	
	lcall	fmul32_mantisse
	ljmp	fmul32_normalise
	
fmul32_mantisse:
	; mul 24 x 24 bit getallen
	;  [r2,r1,r0]
	;  [r6,r5,r4]
	; x-----------
	;  [r2,r1,r0]
	; bewaart 24 MSB van het resultaat in MUL (@r0+2, @r0+1, @r0)	
	mov	B,#024d
	;3 plaatsen op stack reserveren
	mov	A,sp
	mov	dph,A ;originele stackpointer bewaren in dph
	mov	A,sp
	add	A,#03h ;3 plaatsen op de stack reserveren
	mov	sp,A
		
	mov	a,r0 ;r0 op stack bewaren
	push	acc
	
	mov	A,dph ;berekenen pointer naar LSB tussenresultaat (MUL)
	inc	A
	mov	r0,A ;sp+1 bewaren in dpl, startplaats LSB (MUL)
			
fmul32_loop:
	; rrc (A)
	mov	A,r4
	rrc	A
	jnc	fmul32_shift 
	;add
	; (MUL) = (MUL) + (B) 
	clr	C
	pop	acc ; LSB b_arg in acc stoppen
	push	acc ; LSB b_arg bewaren op stack
	add	A,@r0
	mov	@r0,A
	
	inc	r0
	mov	A,@r0
	addc	A,r1
	mov	@r0,A
	
	inc	r0
	mov	A,@r0
	addc	A,r2
	mov	@r0,A	
	dec	r0
	dec	r0		
	
fmul32_shift:	
	;shift (MUL)
	;clr	C
	inc	r0
	inc	r0
	mov	A,@r0
	rrc	A
	mov	@r0,A
	
	dec	r0
	mov	A,@r0
	rrc	A
	mov	@r0,A
	
	dec	r0
	mov	A,@r0
	rrc	A
	mov	@r0,A
	
	;shift (A)
	clr	C
	mov	A,r6
	rrc	A
	mov	r6,A
	
	mov	A,r5
	rrc	A
	mov	r5,A
	
	mov	A,r4
	rrc	A
	mov	r4,A	
	
	djnz	B,fmul32_loop
	
	;tussenresultaat van de stack halen
	; (MUL) naar (r2,r1,r0)
	pop	acc ;originele r0 niet meer nodig 
	mov	A,@r0
	push	acc
	inc	r0
	mov	A,@r0
	mov	r1,A
	inc	r0
	mov	A,@r0
	mov	r2,A		
	pop	acc ;LSB (MUL) van stack halen
	mov	r0,A
	; resultaat is getrunceerd
fmul32_shift_noround:	
	;stack pointer herstellen	
	mov	sp,dph
	ret
	; einde mantisse berekenen
	;---------------------------
	
fmul32_normalise:
	;---------------------------
   	; testen op normalisatie MSB van mantisse(res) == '1'
	;	 zoniet normaliseren
	mov	A,r2
fmul32_normalise_loop:
	jb	acc.7,fmul32_norm_end ; MSB van mantisse(res) == '1' 
	;  normaliseren
	;   exp dec	
	;   mantisse left shift
	mov	A,r3
	jz	fmul32_norm_end_nnormz ;exp = 0, nul of gedenormaliseerd	
	
	dec	r3 ; exp(res) dec
	
	clr	C ; mantisse(res) left shiften
	mov	A,r0
	rlc	A
	mov	r0,A
	
	mov	A,r1
	rlc	A
	mov	r1,A
	
	mov	A,r2
	rlc	A
	mov	r2,A	
	ljmp fmul32_normalise_loop

fmul32_norm_end_nnormz:
	;testen norm of zero
	; voor mantisse(res) testen jz
	;	 f0=1,cy=0,ov=0	nul
	mov	A,r2
	orl	A,r1
	orl	A,r0
	jnz	fmul32_norm_end_nnorm	
	; nul
	pop	acc
	pop	psw
	setb	f0
	clr	cy
	clr	ov	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc
	ret		
fmul32_norm_end_nnorm:
	; niet genormaliseerd 
	;	 f0=1,cy=0,ov=1	niet-genormaliseerd
	setb	f0
	clr	cy
	setb	ov
	ljmp	fmul32_res

fmul32_norm_end:
	;einde normaliseren
	;	 f0=0,cy=0,ov=0 geen vlags
	clr	f0
	clr	cy	
	clr	ov
	;---------------------------
	
fmul32_res:
	;---------------------------	
	;  STACK:
	;	sign(resultaat)
	;   0000000S
	;	-bottom-
	;
	;	Getal res:
	;		   r3	   r2	    r1	     r0
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM  
	;	omvormen naar
	;		
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 	
fmul32_dbg:
	;ljmp	fmul32_dbg
	pop	acc 	
	clr	C
	rrc	A ; sign(res) in CY
	
	mov	A,r3
	rrc	A ; lsb(exp)in CY
	mov	r3,A
		
	mov	A,r2
	mov	acc.7,C
	mov	r2,A
	
	pop	psw
	clr	C
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc
	;einde resultaat
	;---------------------------		
	ret   
	
;*******************************************************************************
; fdiv32        (1254us @16.777216MHz)
; Deze routine berekent de deling van twee floating point getallen (r7-r4 en r3-r0)  in IEEE754 32bit voorstelling 
; met resultaat in r3-r0. 
; Bij overflow/underflow/NaN of een invalid operation wordt deze fouttoestand aangegeven met bijhorende statusvlaggen. 
;              
; Inputbereik getallen:  0x80000001..0x7f7fffff
;							-1.701412E38..3.4028235E38
;							-1.4E-45..3.4028235E38
;			
;                         
; input:     r3,r2,r1,r0 = acc0 
;            r7,r6,r5,r4 = acc1       
;                
; output:    resultaat in r3,r2,r1,r0
;            
;			 f0=0,cy=1,ov=0	invalid operation
;         		 f0=0,cy=1,ov=1 NaN
;			 f0=0,cy=1,ov=1 overflow (+INF)
;			 f0=0,cy=0,ov=1	underflow (-INF)
;			 f0=1,cy=0,ov=1	niet-genormaliseerd
;			 f0=1,cy=0,ov=0	nul
;			 f0=0,cy=0,ov=0 geen vlags	 
;			 f0=1,cy=1,ov=0 ongebruikt
;                                      
; vernietigt:  niets
;*******************************************************************************
fdiv32:
	;operaties om volgende registers op te stack te plaatsen
	;	 r7,r6,r5,r4 
	;        acc,B 
	push	dph
	push	dpl
	push	acc
	push	B
	mov	A,r7
	push	acc
	mov	A,r6
	push	acc
	mov	A,r5
	push	acc
	mov	A,r4
	push	acc
	push	psw
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-top-
	;
	
	;---------------------------
	;lezen
	;
	;	Getal A:
	;		  r3	    r2	      r1      r0
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  
	;	omvormen naar
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM 
	;
	;	Getal B:
	;		   r7	    r6	      r5      r4
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 
	;	omvormen naar
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM 
	;
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;	      0000000S
	;		sign(B)
	;	       0000000S
	;		-bottom-
	
	;getal A
	mov	A,r2
	rlc	A
	
	mov	A,r2
	setb	acc.7 ; 24ste msb implicit op '1' zetten
	mov	r2,A		
	
	mov	A,r3
	rlc	A
	mov	r3,A
	clr	A
	addc	A,#00h
	push	acc ; sign(A)
	
	;getal B
	mov	A,r6
	rlc	A
	
	mov	A,r6
	setb	acc.7 ; 24ste msb implicit op '1' zetten
	mov	r6,A		
	
	mov	A,r7
	rlc	A
	mov	r7,A
	clr	A
	addc	A,#00h
	push	acc ; sign(B) op stack zetten	
	;einde lezen
	;---------------------------
	
	;---------------------------
	; Testen op deling door 0
	mov	A,r7
	jnz	fdiv32_inputtest
	;deling door nul
	pop	acc
	pop	acc
	pop	psw	
	clr 	f0 	;f0=0,cy=1,ov=0	invalid operation
	setb	C
	clr	OV	
	
	mov	r3,#0FFh ; NaN teruggeven r3=0FFh r2-r0 nonzero 
	mov	r2,#0FFh
	mov	r1,#0FFh
	mov	r0,#0FFh
	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc	
	pop		dpl
	pop		dph
	ret
fdiv32_inputtest:
	; Testen op INF/NaN
 	; exp r3 (r7) == #0FFh 
 	cjne	r7,#0FFh,fdiv32_inputtest_a
 	cjne	r3,#0FFh,fdiv32_infnan_b
	ljmp	fdiv32_nan
fdiv32_inputtest_a:
	cjne	r3,#0FFh,fdiv32_inputtest_end
	ljmp	fdiv32_infnan_a
fdiv32_inputtest_end:
	ljmp	fdiv32_inputvalid	
fdiv32_infnan_b:
	;INF/NaN?
	;b mantisse testen op zero
	mov	A,r6 ;combineer mantisse b argument
	orl 	A,r5
	orl 	A,r4
	jnz	fdiv32_nan ;niet nul dan NaN	
	;INF
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;		sign(B)
	;		-bottom-	
	pop	acc
	jz	fdiv32_infnan_b_p
	pop	acc	;sign(A)
	ljmp	fdiv32_infnan_n
fdiv32_infnan_b_p:
	pop	acc 	;sign(A)
	ljmp	fdiv32_infnan_p	
fdiv32_infnan_a:
	;INF/NaN?
	;a mantisse testen op zero
	mov	A,r2 ;combineer mantisse a argument
	orl 	A,r1
	orl 	A,r0
	jnz	fdiv32_nan ;niet nul dan NaN
	;INF
	;	sign op stack	
	; 	 STACK:
	;		sign(A) 
	;		sign(B)
	;		-bottom-
	pop	acc
	pop 	acc
	jz	fdiv32_infnan_p
fdiv32_infnan_n:
	;sign(A) == 1
	; underflow (-INF) 
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	;	 f0=0,cy=0,ov=1	underflow (-INF)
	pop	psw	
	setb 	f0
	clr	C
	setb	OV	
	mov	r3,#0FFh	
	ljmp	fdiv32_inf_end
fdiv32_infnan_p:
	;sign(A) == 0
	; underflow (+INF) 	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	;	f0=0,cy=1,ov=1 overflow (+INF)	
	pop	psw	
	setb f0
	setb	C
	setb OV		
	;   r3	    r2	      r1      r0
	;Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  	
	;   r3	    r2	      r1      r0
	;0111111 1MMMMMMM MMMMMMMM MMMMMMMM  
	mov	r3,#07Fh	
fdiv32_inf_end:
	mov 	r2,#080h
	mov	r1,#000h	
	mov	r0,#000h	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc	
	pop		dpl
	pop		dph
	ret
	
fdiv32_nan:
	pop acc ;sign(B)
	pop acc ;sign(A)
	;NaN
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		psw
	;		-bottom-
	;	
	pop	psw	
	;         f0=0,cy=1,ov=1 NaN
	clr	f0	
	setb	cy
	setb	ov	
	;   r3	    r2	      r1      r0
	;Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM  	
	mov	r3,#0FFh ; NaN teruggeven r3=0FFh r2-r0 nonzero 
	mov	r2,#0FFh
	mov	r1,#0FFh
	mov	r0,#0FFh
	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc		
	pop		dpl
	pop		dph
	ret		
	;einde input testen
	;---------------------------
	
	
	;---------------------------
fdiv32_inputvalid:        
 fdiv32_sign:	
	;sign berekenen
	;  STACK:
	;	sign(A) 
	;	sign(B)
	;	-bottom-	
	pop	acc ; sign(B)
	mov	B,A
	pop	acc ; sign(A)
	xrl	A,B ; sign(A) == sign(B) -> #00h == res (+)
	push	acc ;sign(A) != sign(B) -> #01h == res (-)
	;  STACK:
	;	sign(resultaat)
	;	-bottom-
	
	;lcall	fdiv32_mantisse
	;ljmp	fdiv32_normalise
	
fdiv32_mantisse:
	;---------------------------
	; begin mantisse berekenen
	; div 24 x 24 bit getallen
	;  [r2,r1,r0]
	;  [r6,r5,r4]
	; /-----------
	;  [r2,r1,r0]
	; bewaart 24 MSB van het resultaat in MUL (@r0+2, @r0+1, @r0)		
	fdiv32_t:	
	; mantisse(A) ?< mantisse(B)
	clr	C
	mov	A,r0
	subb	A,r4
	
	mov	A,r1
	subb	A,r5
	
	mov	A,r2
	subb	A,r6
	mov	B,#00	;B clearen
	jc	fdiv32_2
	; mantisse(A) > mantisse(B)
	;aligneren zodat mantisse(A) < mantisse(B)
	
	clr	C
	mov	A,r2
	rrc	A
	mov	r2,A
	
	mov	A,r1
	rrc	A
	mov	r1,A
	
	mov	A,r0
	rrc	A
	mov	r0,A	
	
	mov	A,B
	rrc	A	;LSB in Aext2 shiften
	mov	B,A 	;tijdelijk bewaren in B (nog niet gealloceerd)
	
	mov	A,r3
	inc	A 	;! testen of A niet #FF is
	mov	r3,A
fdiv32_2:
	; resultaat exponent berekenen
	clr	C
	mov	A,r3
	subb	A,r7
	add	a,#126
	mov	r3,A 	
	
fdiv32_2b:	
	mov	A,sp
	mov	dph,A 	; originele stackpointer bewaren
	add	A,#05d 	; 5 geheugenplaatsen alloceren
	mov	sp,A
	
	mov	A,r1 	; r1,r0 op stack plaatsen
	push	acc
	mov	A,r0
	push	acc
	
	mov	A,dph
	inc	A
	mov	r0,A	;sp+1 pointer LSB Quotient
	add	A,#03d
	mov	r1,A	;pointer Aext
	
	;bytes op de stack initialiseren op #00
	mov	@r0,#00
	inc	r0
	mov	@r0,#00
	inc	r0
	mov	@r0,#00
	inc	r0
	mov	@r0,#00 ;
	inc	r0
	mov	@r0,#00
	mov	r0,dph	;pointer r0 naar LSB Quotient herstellen
	inc	r0		
	inc	r1
	mov	@r1,B 	;tijdelijke waarde uit B naar Aext2 op stack verplaatsen
	dec	r1
	mov	r7,#24d	;teller in r7		
	
fdiv32_3:
	; STACK:
	;	r1
	;	r0
	;	--top--
	;Aext,[r2,r1,r0],Aext2 rlc	
	clr	C
	inc	r1	;berekenen Aext2 pointer
	mov	A,@r1 	;Aext2
	rlc	A
	mov	@r1,A
	dec	r1	
	
	pop	acc 	;r0
	rlc	A
	mov	B,A 	;r0 tijdelijk opslaan in B
	
	pop	acc 	;r1
	rlc	A
	push	acc	;r1
	push	b	;r0
	
	mov	A,r2
	rlc	A
	mov	r2,A
	
	mov	A,@r1	;Aext
	rlc	A
	mov	@r1,A
	
	;Testen subtractie mogelijk
	;   [r2,r1,r0]
	;   [r6,r5,r4] 
	; - --------
	;[C]
	clr	C
	pop	b 	;r0
	mov	A,B
	subb	A,r4	
	pop	acc	 ;r1
	push	acc
	subb	A,r5
	push	b	;r0
	mov	A,r2
	subb	A,r6
	mov	A,@r1
	subb	A,#0
	jc	fdiv32_3b ;jump indien subtractie onmogelijk
	;subtractie mogelijk
	;   [r2,r1,r0]
	;   [r6,r5,r4] 
	; - --------
	;[C][r2,r1,r0]
	clr	C
	pop	acc 	;r0
	subb	A,r4
	mov	B,A
	pop	acc	;r1
	subb	A,r5
	push	acc	;r1
	push	b	;r0
	mov	A,r2
	subb	A,r6
	mov	r2,A
	mov	A,@r1
	subb	A,#0
	mov	@r1,A	
fdiv32_3b:
	cpl	C
	mov	A,@r0 ;LSB Quotient
	rlc	A
	mov	@r0,A
	inc	r0
	
	mov	A,@r0 ;
	rlc	A
	mov	@r0,A
	inc	r0
	
	mov	A,@r0 ;MSB Quotient
	rlc	A
	mov	@r0,A
	dec	r0
	dec	r0
	
	djnz	r7,fdiv32_3
	;quotient naar [r2,r1,r0]
	;pointer bereken MSB 
	inc	r0
	inc	r0
	mov	A,@r0
	mov	r2,A	;MSB (A)
	dec	r0	
	mov	A,@r0
	mov	r1,A
	dec	r0	
	mov	A,@r0
	mov	r0,A 	;LSB (A)	  
  	    
  	mov     sp,dph	; originele stackpointer herstellen	
	;ret
	; einde mantisse berekenen
	;---------------------------
	
fdiv32_normalise:
	;---------------------------
   	; testen op normalisatie MSB van mantisse(res) == '1'
	;	 zoniet normaliseren
	mov	A,r2
fdiv32_normalise_loop:
	jb	acc.7,fdiv32_norm_end ; MSB van mantisse(res) == '1' 
	;  normaliseren
	;   exp dec	
	;   mantisse left shift
	mov	A,r3
	jz	fdiv32_norm_end_nnormz ;exp = 0, nul of gedenormaliseerd	
	
	dec	r3 ; exp(res) dec
	
	clr	C ; mantisse(res) left shiften
	mov	A,r0
	rlc	A
	mov	r0,A
	
	mov	A,r1
	rlc	A
	mov	r1,A
	
	mov	A,r2
	rlc	A
	mov	r2,A	
	ljmp fdiv32_normalise_loop

fdiv32_norm_end_nnormz:
	;testen norm of zero
	; voor mantisse(res) testen jz
	;	 f0=1,cy=0,ov=0	nul
	mov	A,r2
	orl	A,r1
	orl	A,r0
	jnz	fdiv32_norm_end_nnorm	
	; nul
	pop	acc
	pop	psw
	setb	f0
	clr	cy
	clr	ov	
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc
		pop		dpl
	pop		dph
	ret		
fdiv32_norm_end_nnorm:
	; niet genormaliseerd 
	;	 f0=1,cy=0,ov=1	niet-genormaliseerd
	setb	f0
	clr	cy
	setb	ov
	ljmp	fdiv32_res

fdiv32_norm_end:
	;einde normaliseren
	;	 f0=0,cy=0,ov=0 geen vlags
	clr	f0
	clr	cy	
	clr	ov
	;---------------------------
	
fdiv32_res:
	;---------------------------	
	;  STACK:
	;	sign(resultaat)
	;   0000000S
	;	-bottom-
	;
	;	Getal res:
	;		   r3	   r2	    r1	     r0
	;		eeeeeeee 1MMMMMMM MMMMMMMM MMMMMMMM  
	;	omvormen naar
	;		
	;		Seeeeeee eMMMMMMM MMMMMMMM MMMMMMMM 	
	;
	pop	acc 	
	clr	C
	rrc	A ; sign(res) in CY
	
	mov	A,r3
	rrc	A ; lsb(exp)in CY
	mov	r3,A
		
	mov	A,r2
	mov	acc.7,C
	mov	r2,A
	
	pop	psw
	clr	C
	; 	 STACK:
	;		acc
	;	      	B
	;		r7
	;		r6
	;		r5
	;		r4
	;		-bottom-
	;	
	pop	acc
	mov	r4,A
	pop	acc
	mov	r5,A
	pop	acc
	mov	r6,A
	pop	acc
	mov	r7,A	
	pop	B
	pop	acc
	;einde resultaat
	;---------------------------
	pop		dpl
	pop		dph
	ret    