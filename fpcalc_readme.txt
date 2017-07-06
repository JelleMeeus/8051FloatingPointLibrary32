gebruik van fpcalc gaat als volgt:

fpcalc
geeft 4 operaties weer

fpcalc getal1 getal2 [+,-,*,/]
berekent getal1 operatie getal2 en geeft resultaat weer
voorbeeld:
fpcalc -10.0 8.0 +

fpcalc lowerbound upperbound [+,-,*,/] X amount
genereert amount aantal testfuncties 
met random getallen tussen lowerbound en upperbound
voor de operatie aangegeven [+,-,*,/]
voorbeeld:
fpcalc -5e6 5e6 + p 10>f32_asm_add_test.inc
genereert 10 testfuncties met random 32b getallen tussen
-5*10^6 en +5*10^6 om fadd32 te testen

fpcalc lowerbound upperbound X a amount
genereert amount aantal testfuncties 
met random getallen tussen lowerbound en upperbound
voor random operaties [+,-,*,/]
voorbeeld:
fpcalc -5e3 5e3 + a 10>f32_asm_test.inc
genereert 10 testfuncties met random 32b getallen tussen
-5*10^3 en +5*10^3 om fadd32 te testen


