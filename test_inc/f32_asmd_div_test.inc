; 20 waarden tussen -5000000.000000 en 5000000.000000
;bewerking '/' 
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
;dec = -7.843773
;hex = c0fb0030
;	sign = 1
;	exponent = 81
;	mantisa = 7b0030
mov 13h,#0c0h
mov 12h,#0fbh
mov 11h,#00h
mov 10h,#030h
lcall fdiv32
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
;dec = -0.993377
;hex = bf7e4df7
;	sign = 1
;	exponent = 7e
;	mantisa = 7e4df7
mov 13h,#0bfh
mov 12h,#07eh
mov 11h,#04dh
mov 10h,#0f7h
lcall fdiv32
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
;dec = -4.223654
;hex = c087282d
;	sign = 1
;	exponent = 81
;	mantisa = 7282d
mov 13h,#0c0h
mov 12h,#087h
mov 11h,#028h
mov 10h,#02dh
lcall fdiv32
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
;dec = -0.378088
;hex = bec194b9
;	sign = 1
;	exponent = 7d
;	mantisa = 4194b9
mov 13h,#0beh
mov 12h,#0c1h
mov 11h,#094h
mov 10h,#0b9h
lcall fdiv32
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
;dec = 1.309139
;hex = 3fa791e0
;	sign = 0
;	exponent = 7f
;	mantisa = 2791e0
mov 13h,#03fh
mov 12h,#0a7h
mov 11h,#091h
mov 10h,#0e0h
lcall fdiv32
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
;dec = -0.907920
;hex = bf686d70
;	sign = 1
;	exponent = 7e
;	mantisa = 686d70
mov 13h,#0bfh
mov 12h,#068h
mov 11h,#06dh
mov 10h,#070h
lcall fdiv32
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
;dec = 15.552423
;hex = 4178d6ba
;	sign = 0
;	exponent = 82
;	mantisa = 78d6ba
mov 13h,#041h
mov 12h,#078h
mov 11h,#0d6h
mov 10h,#0bah
lcall fdiv32
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
;dec = 0.404121
;hex = 3ecee902
;	sign = 0
;	exponent = 7d
;	mantisa = 4ee902
mov 13h,#03eh
mov 12h,#0ceh
mov 11h,#0e9h
mov 10h,#02h
lcall fdiv32
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
;dec = 3.014410
;hex = 4040ec16
;	sign = 0
;	exponent = 80
;	mantisa = 40ec16
mov 13h,#040h
mov 12h,#040h
mov 11h,#0ech
mov 10h,#016h
lcall fdiv32
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
;dec = 1.055629
;hex = 3f871edb
;	sign = 0
;	exponent = 7f
;	mantisa = 71edb
mov 13h,#03fh
mov 12h,#087h
mov 11h,#01eh
mov 10h,#0dbh
lcall fdiv32
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
;dec = -8.995504
;hex = c10fed96
;	sign = 1
;	exponent = 82
;	mantisa = fed96
mov 13h,#0c1h
mov 12h,#0fh
mov 11h,#0edh
mov 10h,#096h
lcall fdiv32
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
;dec = 0.769015
;hex = 3f44de2d
;	sign = 0
;	exponent = 7e
;	mantisa = 44de2d
mov 13h,#03fh
mov 12h,#044h
mov 11h,#0deh
mov 10h,#02dh
lcall fdiv32
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
;dec = 4.021367
;hex = 4080af0a
;	sign = 0
;	exponent = 81
;	mantisa = af0a
mov 13h,#040h
mov 12h,#080h
mov 11h,#0afh
mov 10h,#0ah
lcall fdiv32
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
;dec = 0.444802
;hex = 3ee3bd0c
;	sign = 0
;	exponent = 7d
;	mantisa = 63bd0c
mov 13h,#03eh
mov 12h,#0e3h
mov 11h,#0bdh
mov 10h,#0ch
lcall fdiv32
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
;dec = 0.949594
;hex = 3f73189a
;	sign = 0
;	exponent = 7e
;	mantisa = 73189a
mov 13h,#03fh
mov 12h,#073h
mov 11h,#018h
mov 10h,#09ah
lcall fdiv32
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
;dec = -2.047075
;hex = c0030348
;	sign = 1
;	exponent = 80
;	mantisa = 30348
mov 13h,#0c0h
mov 12h,#03h
mov 11h,#03h
mov 10h,#048h
lcall fdiv32
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
;dec = 0.332783
;hex = 3eaa6288
;	sign = 0
;	exponent = 7d
;	mantisa = 2a6288
mov 13h,#03eh
mov 12h,#0aah
mov 11h,#062h
mov 10h,#088h
lcall fdiv32
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
;dec = -4.113504
;hex = c083a1d4
;	sign = 1
;	exponent = 81
;	mantisa = 3a1d4
mov 13h,#0c0h
mov 12h,#083h
mov 11h,#0a1h
mov 10h,#0d4h
lcall fdiv32
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
;dec = 0.936261
;hex = 3f6faed4
;	sign = 0
;	exponent = 7e
;	mantisa = 6faed4
mov 13h,#03fh
mov 12h,#06fh
mov 11h,#0aeh
mov 10h,#0d4h
lcall fdiv32
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
;dec = -0.100393
;hex = bdcd9ad1
;	sign = 1
;	exponent = 7b
;	mantisa = 4d9ad1
mov 13h,#0bdh
mov 12h,#0cdh
mov 11h,#09ah
mov 10h,#0d1h
lcall fdiv32
