; 20 waarden tussen -5000000.000000 en 5000000.000000
;bewerking 'x' 
;
mov r3,#0cah
mov r2,#098h
mov r1,#034h
mov r0,#0bfh
mov r7,#049h
mov r6,#01bh
mov r5,#03ch
mov r4,#0d2h
;getal 1
;dec = -4987487.500000
;hex = ca9834bf
;	sign = 1
;	exponent = 95
;	mantisa = 1834bf

;getal 2
;dec = 635853.125000
;hex = 491b3cd2
;	sign = 0
;	exponent = 92
;	mantisa = 1b3cd2
;getal 1
;dec = -3171309584384.000000
;hex = d4389832
;	sign = 1
;	exponent = a8
;	mantisa = 389832
mov 13h,#0d4h
mov 12h,#038h
mov 11h,#098h
mov 10h,#032h
lcall fmul32
;
mov r3,#0cah
mov r2,#03bh
mov r1,#031h
mov r0,#036h
mov r7,#04ah
mov r6,#03ch
mov r5,#070h
mov r4,#0b4h
;getal 1
;dec = -3066957.500000
;hex = ca3b3136
;	sign = 1
;	exponent = 94
;	mantisa = 3b3136

;getal 2
;dec = 3087405.000000
;hex = 4a3c70b4
;	sign = 0
;	exponent = 94
;	mantisa = 3c70b4
;getal 1
;dec = -9468940124160.000000
;hex = d509ca8d
;	sign = 1
;	exponent = aa
;	mantisa = 9ca8d
mov 13h,#0d5h
mov 12h,#09h
mov 11h,#0cah
mov 10h,#08dh
lcall fmul32
;
mov r3,#049h
mov r2,#04fh
mov r1,#08ah
mov r0,#0d1h
mov r7,#0c8h
mov r6,#044h
mov r5,#08dh
mov r4,#064h
;getal 1
;dec = 850093.062500
;hex = 494f8ad1
;	sign = 0
;	exponent = 92
;	mantisa = 4f8ad1

;getal 2
;dec = -201269.562500
;hex = c8448d64
;	sign = 1
;	exponent = 90
;	mantisa = 448d64
;getal 1
;dec = -171097866240.000000
;hex = d21f58e9
;	sign = 1
;	exponent = a4
;	mantisa = 1f58e9
mov 13h,#0d2h
mov 12h,#01fh
mov 11h,#058h
mov 10h,#0e9h
lcall fmul32
;
mov r3,#0c9h
mov r2,#0b6h
mov r1,#0bfh
mov r0,#0ech
mov r7,#04ah
mov r6,#071h
mov r5,#0adh
mov r4,#020h
;getal 1
;dec = -1497085.500000
;hex = c9b6bfec
;	sign = 1
;	exponent = 93
;	mantisa = 36bfec

;getal 2
;dec = 3959624.000000
;hex = 4a71ad20
;	sign = 0
;	exponent = 94
;	mantisa = 71ad20
;getal 1
;dec = -5927895826432.000000
;hex = d4ac8644
;	sign = 1
;	exponent = a9
;	mantisa = 2c8644
mov 13h,#0d4h
mov 12h,#0ach
mov 11h,#086h
mov 10h,#044h
lcall fmul32
;
mov r3,#04ah
mov r2,#045h
mov r1,#0bh
mov r0,#0c2h
mov r7,#04ah
mov r6,#016h
mov r5,#084h
mov r4,#01h
;getal 1
;dec = 3228400.500000
;hex = 4a450bc2
;	sign = 0
;	exponent = 94
;	mantisa = 450bc2

;getal 2
;dec = 2466048.250000
;hex = 4a168401
;	sign = 0
;	exponent = 94
;	mantisa = 168401
;getal 1
;dec = 7961391398912.000000
;hex = 54e7b4fd
;	sign = 0
;	exponent = a9
;	mantisa = 67b4fd
mov 13h,#054h
mov 12h,#0e7h
mov 11h,#0b4h
mov 10h,#0fdh
lcall fmul32
;
mov r3,#0cah
mov r2,#046h
mov r1,#0e8h
mov r0,#09ch
mov r7,#04ah
mov r6,#05bh
mov r5,#014h
mov r4,#0eah
;getal 1
;dec = -3258919.000000
;hex = ca46e89c
;	sign = 1
;	exponent = 94
;	mantisa = 46e89c

;getal 2
;dec = 3589434.500000
;hex = 4a5b14ea
;	sign = 0
;	exponent = 94
;	mantisa = 5b14ea
;getal 1
;dec = -11697675829248.000000
;hex = d52a393d
;	sign = 1
;	exponent = aa
;	mantisa = 2a393d
mov 13h,#0d5h
mov 12h,#02ah
mov 11h,#039h
mov 10h,#03dh
lcall fmul32
;
mov r3,#04ah
mov r2,#00h
mov r1,#07ah
mov r0,#0d9h
mov r7,#048h
mov r6,#04h
mov r5,#02dh
mov r4,#066h
;getal 1
;dec = 2105014.250000
;hex = 4a007ad9
;	sign = 0
;	exponent = 94
;	mantisa = 7ad9

;getal 2
;dec = 135349.593750
;hex = 48042d66
;	sign = 0
;	exponent = 90
;	mantisa = 42d66
;getal 1
;dec = 284912812032.000000
;hex = 5284ac41
;	sign = 0
;	exponent = a5
;	mantisa = 4ac41
mov 13h,#052h
mov 12h,#084h
mov 11h,#0ach
mov 10h,#041h
lcall fmul32
;
mov r3,#0c9h
mov r2,#0efh
mov r1,#043h
mov r0,#09ah
mov r7,#0cah
mov r6,#094h
mov r5,#03h
mov r4,#0d4h
;getal 1
;dec = -1960051.250000
;hex = c9ef439a
;	sign = 1
;	exponent = 93
;	mantisa = 6f439a

;getal 2
;dec = -4850154.000000
;hex = ca9403d4
;	sign = 1
;	exponent = 95
;	mantisa = 1403d4
;getal 1
;dec = 9506550448128.000000
;hex = 550a56a9
;	sign = 0
;	exponent = aa
;	mantisa = a56a9
mov 13h,#055h
mov 12h,#0ah
mov 11h,#056h
mov 10h,#0a9h
lcall fmul32
;
mov r3,#0cah
mov r2,#079h
mov r1,#063h
mov r0,#04bh
mov r7,#0c9h
mov r6,#0a5h
mov r5,#076h
mov r4,#0bdh
;getal 1
;dec = -4085970.750000
;hex = ca79634b
;	sign = 1
;	exponent = 94
;	mantisa = 79634b

;getal 2
;dec = -1355479.625000
;hex = c9a576bd
;	sign = 1
;	exponent = 93
;	mantisa = 2576bd
;getal 1
;dec = 5538449981440.000000
;hex = 54a130ab
;	sign = 0
;	exponent = a9
;	mantisa = 2130ab
mov 13h,#054h
mov 12h,#0a1h
mov 11h,#030h
mov 10h,#0abh
lcall fmul32
;
mov r3,#0cah
mov r2,#057h
mov r1,#043h
mov r0,#05eh
mov r7,#0cah
mov r6,#04bh
mov r5,#0ebh
mov r4,#057h
;getal 1
;dec = -3526871.500000
;hex = ca57435e
;	sign = 1
;	exponent = 94
;	mantisa = 57435e

;getal 2
;dec = -3341013.750000
;hex = ca4beb57
;	sign = 1
;	exponent = 94
;	mantisa = 4beb57
;getal 1
;dec = 11783326662656.000000
;hex = 552b7850
;	sign = 0
;	exponent = aa
;	mantisa = 2b7850
mov 13h,#055h
mov 12h,#02bh
mov 11h,#078h
mov 10h,#050h
lcall fmul32
;
mov r3,#04ah
mov r2,#095h
mov r1,#016h
mov r0,#05h
mov r7,#0c9h
mov r6,#04h
mov r5,#096h
mov r4,#04eh
;getal 1
;dec = 4885250.500000
;hex = 4a951605
;	sign = 0
;	exponent = 95
;	mantisa = 151605

;getal 2
;dec = -543076.875000
;hex = c904964e
;	sign = 1
;	exponent = 92
;	mantisa = 4964e
;getal 1
;dec = -2653066625024.000000
;hex = d41a6dc6
;	sign = 1
;	exponent = a8
;	mantisa = 1a6dc6
mov 13h,#0d4h
mov 12h,#01ah
mov 11h,#06dh
mov 10h,#0c6h
lcall fmul32
;
mov r3,#0cah
mov r2,#068h
mov r1,#07eh
mov r0,#03fh
mov r7,#0cah
mov r6,#097h
mov r5,#029h
mov r4,#0b5h
;getal 1
;dec = -3809167.750000
;hex = ca687e3f
;	sign = 1
;	exponent = 94
;	mantisa = 687e3f

;getal 2
;dec = -4953306.500000
;hex = ca9729b5
;	sign = 1
;	exponent = 95
;	mantisa = 1729b5
;getal 1
;dec = 18867975880704.000000
;hex = 55894858
;	sign = 0
;	exponent = ab
;	mantisa = 94858
mov 13h,#055h
mov 12h,#089h
mov 11h,#048h
mov 10h,#058h
lcall fmul32
;
mov r3,#0cah
mov r2,#095h
mov r1,#0deh
mov r0,#04ch
mov r7,#0c9h
mov r6,#095h
mov r5,#012h
mov r4,#071h
;getal 1
;dec = -4910886.000000
;hex = ca95de4c
;	sign = 1
;	exponent = 95
;	mantisa = 15de4c

;getal 2
;dec = -1221198.125000
;hex = c9951271
;	sign = 1
;	exponent = 93
;	mantisa = 151271
;getal 1
;dec = 5997164756992.000000
;hex = 54ae8a5c
;	sign = 0
;	exponent = a9
;	mantisa = 2e8a5c
mov 13h,#054h
mov 12h,#0aeh
mov 11h,#08ah
mov 10h,#05ch
lcall fmul32
;
mov r3,#048h
mov r2,#09ah
mov r1,#09ah
mov r0,#0b1h
mov r7,#049h
mov r6,#02dh
mov r5,#0cah
mov r4,#044h
;getal 1
;dec = 316629.531250
;hex = 489a9ab1
;	sign = 0
;	exponent = 91
;	mantisa = 1a9ab1

;getal 2
;dec = 711844.250000
;hex = 492dca44
;	sign = 0
;	exponent = 92
;	mantisa = 2dca44
;getal 1
;dec = 225390903296.000000
;hex = 5251e961
;	sign = 0
;	exponent = a4
;	mantisa = 51e961
mov 13h,#052h
mov 12h,#051h
mov 11h,#0e9h
mov 10h,#061h
lcall fmul32
;
mov r3,#049h
mov r2,#078h
mov r1,#072h
mov r0,#07bh
mov r7,#049h
mov r6,#082h
mov r5,#0d1h
mov r4,#04ch
;getal 1
;dec = 1017639.687500
;hex = 4978727b
;	sign = 0
;	exponent = 92
;	mantisa = 78727b

;getal 2
;dec = 1071657.500000
;hex = 4982d14c
;	sign = 0
;	exponent = 93
;	mantisa = 2d14c
;getal 1
;dec = 1090561179648.000000
;hex = 537dea83
;	sign = 0
;	exponent = a6
;	mantisa = 7dea83
mov 13h,#053h
mov 12h,#07dh
mov 11h,#0eah
mov 10h,#083h
lcall fmul32
;
mov r3,#0cah
mov r2,#04bh
mov r1,#0b6h
mov r0,#0e3h
mov r7,#049h
mov r6,#0c7h
mov r5,#07h
mov r4,#09bh
;getal 1
;dec = -3337656.750000
;hex = ca4bb6e3
;	sign = 1
;	exponent = 94
;	mantisa = 4bb6e3

;getal 2
;dec = 1630451.375000
;hex = 49c7079b
;	sign = 0
;	exponent = 93
;	mantisa = 47079b
;getal 1
;dec = -5441887141888.000000
;hex = d49e6138
;	sign = 1
;	exponent = a9
;	mantisa = 1e6138
mov 13h,#0d4h
mov 12h,#09eh
mov 11h,#061h
mov 10h,#038h
lcall fmul32
;
mov r3,#0c8h
mov r2,#0f0h
mov r1,#049h
mov r0,#0dfh
mov r7,#0c9h
mov r6,#0b4h
mov r5,#083h
mov r4,#0b3h
;getal 1
;dec = -492110.968750
;hex = c8f049df
;	sign = 1
;	exponent = 91
;	mantisa = 7049df

;getal 2
;dec = -1478774.375000
;hex = c9b483b3
;	sign = 1
;	exponent = 93
;	mantisa = 3483b3
;getal 1
;dec = 727721115648.000000
;hex = 53296f8f
;	sign = 0
;	exponent = a6
;	mantisa = 296f8f
mov 13h,#053h
mov 12h,#029h
mov 11h,#06fh
mov 10h,#08fh
lcall fmul32
;
mov r3,#0cah
mov r2,#087h
mov r1,#02eh
mov r0,#052h
mov r7,#049h
mov r6,#083h
mov r5,#073h
mov r4,#06dh
;getal 1
;dec = -4429609.000000
;hex = ca872e52
;	sign = 1
;	exponent = 95
;	mantisa = 72e52

;getal 2
;dec = 1076845.625000
;hex = 4983736d
;	sign = 0
;	exponent = 93
;	mantisa = 3736d
;getal 1
;dec = -4770005254144.000000
;hex = d48ad34f
;	sign = 1
;	exponent = a9
;	mantisa = ad34f
mov 13h,#0d4h
mov 12h,#08ah
mov 11h,#0d3h
mov 10h,#04fh
lcall fmul32
;
mov r3,#04ah
mov r2,#02ch
mov r1,#0ech
mov r0,#087h
mov r7,#04ah
mov r6,#038h
mov r5,#0b2h
mov r4,#03bh
;getal 1
;dec = 2833185.750000
;hex = 4a2cec87
;	sign = 0
;	exponent = 94
;	mantisa = 2cec87

;getal 2
;dec = 3026062.750000
;hex = 4a38b23b
;	sign = 0
;	exponent = 94
;	mantisa = 38b23b
;getal 1
;dec = 8573398024192.000000
;hex = 54f984cb
;	sign = 0
;	exponent = a9
;	mantisa = 7984cb
mov 13h,#054h
mov 12h,#0f9h
mov 11h,#084h
mov 10h,#0cbh
lcall fmul32
;
mov r3,#048h
mov r2,#042h
mov r1,#02bh
mov r0,#06h
mov r7,#0c9h
mov r6,#0f1h
mov r5,#0c2h
mov r4,#095h
;getal 1
;dec = 198828.093750
;hex = 48422b06
;	sign = 0
;	exponent = 90
;	mantisa = 422b06

;getal 2
;dec = -1980498.625000
;hex = c9f1c295
;	sign = 1
;	exponent = 93
;	mantisa = 71c295
;getal 1
;dec = -393778757632.000000
;hex = d2b75e16
;	sign = 1
;	exponent = a5
;	mantisa = 375e16
mov 13h,#0d2h
mov 12h,#0b7h
mov 11h,#05eh
mov 10h,#016h
lcall fmul32
