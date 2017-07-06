; 20 waarden tussen -5000000.000000 en 5000000.000000
;bewerking '+' 
;
mov r3,#04ah
mov r2,#03ch
mov r1,#070h
mov r0,#0b4h
mov r7,#049h
mov r6,#04fh
mov r5,#08ah
mov r4,#0d1h
;getal 1
;dec = 3087405.000000
;hex = 4a3c70b4
;	sign = 0
;	exponent = 94
;	mantisa = 3c70b4

;getal 2
;dec = 850093.062500
;hex = 494f8ad1
;	sign = 0
;	exponent = 92
;	mantisa = 4f8ad1
;getal 1
;dec = 3937498.000000
;hex = 4a705368
;	sign = 0
;	exponent = 94
;	mantisa = 705368
mov 13h,#04ah
mov 12h,#070h
mov 11h,#053h
mov 10h,#068h
lcall fadd32
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
mov r2,#016h
mov r1,#084h
mov r0,#01h
mov r7,#0cah
mov r6,#046h
mov r5,#0e8h
mov r4,#09ch
;getal 1
;dec = 2466048.250000
;hex = 4a168401
;	sign = 0
;	exponent = 94
;	mantisa = 168401

;getal 2
;dec = -3258919.000000
;hex = ca46e89c
;	sign = 1
;	exponent = 94
;	mantisa = 46e89c
;getal 1
;dec = 5724967.000000
;hex = 4aaeb64e
;	sign = 0
;	exponent = 95
;	mantisa = 2eb64e
mov 13h,#04ah
mov 12h,#0aeh
mov 11h,#0b6h
mov 10h,#04eh
lcall fsub32
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
;dec = 1969664.625000
;hex = 49f07005
;	sign = 0
;	exponent = 93
;	mantisa = 707005
mov 13h,#049h
mov 12h,#0f0h
mov 11h,#070h
mov 10h,#05h
lcall fsub32
;
mov r3,#0cah
mov r2,#094h
mov r1,#03h
mov r0,#0d4h
mov r7,#0cah
mov r6,#079h
mov r5,#063h
mov r4,#04bh
;getal 1
;dec = -4850154.000000
;hex = ca9403d4
;	sign = 1
;	exponent = 95
;	mantisa = 1403d4

;getal 2
;dec = -4085970.750000
;hex = ca79634b
;	sign = 1
;	exponent = 94
;	mantisa = 79634b
;getal 1
;dec = 19817587277824.000000
;hex = 55903122
;	sign = 0
;	exponent = ab
;	mantisa = 103122
mov 13h,#055h
mov 12h,#090h
mov 11h,#031h
mov 10h,#022h
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
mov r3,#0c9h
mov r2,#04h
mov r1,#096h
mov r0,#04eh
mov r7,#0cah
mov r6,#068h
mov r5,#07eh
mov r4,#03fh
;getal 1
;dec = -543076.875000
;hex = c904964e
;	sign = 1
;	exponent = 92
;	mantisa = 4964e

;getal 2
;dec = -3809167.750000
;hex = ca687e3f
;	sign = 1
;	exponent = 94
;	mantisa = 687e3f
;getal 1
;dec = 3266091.000000
;hex = 4a4758ac
;	sign = 0
;	exponent = 94
;	mantisa = 4758ac
mov 13h,#04ah
mov 12h,#047h
mov 11h,#058h
mov 10h,#0ach
lcall fsub32
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
;dec = -3689688.000000
;hex = ca613360
;	sign = 1
;	exponent = 94
;	mantisa = 613360
mov 13h,#0cah
mov 12h,#061h
mov 11h,#033h
mov 10h,#060h
lcall fsub32
;
mov r3,#049h
mov r2,#02dh
mov r1,#0cah
mov r0,#044h
mov r7,#049h
mov r6,#078h
mov r5,#072h
mov r4,#07bh
;getal 1
;dec = 711844.250000
;hex = 492dca44
;	sign = 0
;	exponent = 92
;	mantisa = 2dca44

;getal 2
;dec = 1017639.687500
;hex = 4978727b
;	sign = 0
;	exponent = 92
;	mantisa = 78727b
;getal 1
;dec = 0.699505
;hex = 3f3312c6
;	sign = 0
;	exponent = 7e
;	mantisa = 3312c6
mov 13h,#03fh
mov 12h,#033h
mov 11h,#012h
mov 10h,#0c6h
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
mov r3,#0c9h
mov r2,#0b4h
mov r1,#083h
mov r0,#0b3h
mov r7,#0cah
mov r6,#087h
mov r5,#02eh
mov r4,#052h
;getal 1
;dec = -1478774.375000
;hex = c9b483b3
;	sign = 1
;	exponent = 93
;	mantisa = 3483b3

;getal 2
;dec = -4429609.000000
;hex = ca872e52
;	sign = 1
;	exponent = 95
;	mantisa = 72e52
;getal 1
;dec = -5908383.500000
;hex = cab44f3f
;	sign = 1
;	exponent = 95
;	mantisa = 344f3f
mov 13h,#0cah
mov 12h,#0b4h
mov 11h,#04fh
mov 10h,#03fh
lcall fadd32
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
mov r3,#0c9h
mov r2,#0f1h
mov r1,#0c2h
mov r0,#095h
mov r7,#04ah
mov r6,#065h
mov r5,#079h
mov r4,#0bfh
;getal 1
;dec = -1980498.625000
;hex = c9f1c295
;	sign = 1
;	exponent = 93
;	mantisa = 71c295

;getal 2
;dec = 3759727.750000
;hex = 4a6579bf
;	sign = 0
;	exponent = 94
;	mantisa = 6579bf
;getal 1
;dec = -0.526766
;hex = bf06da2b
;	sign = 1
;	exponent = 7e
;	mantisa = 6da2b
mov 13h,#0bfh
mov 12h,#06h
mov 11h,#0dah
mov 10h,#02bh
lcall fdiv32
;
mov r3,#04ah
mov r2,#08bh
mov r1,#021h
mov r0,#03fh
mov r7,#04ah
mov r6,#081h
mov r5,#0ebh
mov r4,#037h
;getal 1
;dec = 4559007.500000
;hex = 4a8b213f
;	sign = 0
;	exponent = 95
;	mantisa = b213f

;getal 2
;dec = 4257179.500000
;hex = 4a81eb37
;	sign = 0
;	exponent = 95
;	mantisa = 1eb37
;getal 1
;dec = 301828.000000
;hex = 48936080
;	sign = 0
;	exponent = 91
;	mantisa = 136080
mov 13h,#048h
mov 12h,#093h
mov 11h,#060h
mov 10h,#080h
lcall fsub32
;
mov r3,#0cah
mov r2,#05ah
mov r1,#04ch
mov r0,#0a3h
mov r7,#0c8h
mov r6,#0b9h
mov r5,#027h
mov r4,#0fh
;getal 1
;dec = -3576616.750000
;hex = ca5a4ca3
;	sign = 1
;	exponent = 94
;	mantisa = 5a4ca3

;getal 2
;dec = -379192.468750
;hex = c8b9270f
;	sign = 1
;	exponent = 91
;	mantisa = 39270f
;getal 1
;dec = 9.432194
;hex = 4116ea44
;	sign = 0
;	exponent = 82
;	mantisa = 16ea44
mov 13h,#041h
mov 12h,#016h
mov 11h,#0eah
mov 10h,#044h
lcall fdiv32
;
mov r3,#04ah
mov r2,#05dh
mov r1,#017h
mov r0,#0eah
mov r7,#0cah
mov r6,#031h
mov r5,#03eh
mov r4,#0d3h
;getal 1
;dec = 3622394.500000
;hex = 4a5d17ea
;	sign = 0
;	exponent = 94
;	mantisa = 5d17ea

;getal 2
;dec = -2903988.750000
;hex = ca313ed3
;	sign = 1
;	exponent = 94
;	mantisa = 313ed3
;getal 1
;dec = -1.247386
;hex = bf9faa57
;	sign = 1
;	exponent = 7f
;	mantisa = 1faa57
mov 13h,#0bfh
mov 12h,#09fh
mov 11h,#0aah
mov 10h,#057h
lcall fdiv32
;
mov r3,#04ah
mov r2,#051h
mov r1,#0bfh
mov r0,#0e3h
mov r7,#04ah
mov r6,#097h
mov r5,#09ch
mov r4,#027h
;getal 1
;dec = 3436536.750000
;hex = 4a51bfe3
;	sign = 0
;	exponent = 94
;	mantisa = 51bfe3

;getal 2
;dec = 4967955.500000
;hex = 4a979c27
;	sign = 0
;	exponent = 95
;	mantisa = 179c27
;getal 1
;dec = -1531418.750000
;hex = c9baf0d6
;	sign = 1
;	exponent = 93
;	mantisa = 3af0d6
mov 13h,#0c9h
mov 12h,#0bah
mov 11h,#0f0h
mov 10h,#0d6h
lcall fsub32
;
mov r3,#049h
mov r2,#088h
mov r1,#01bh
mov r0,#08eh
mov r7,#0c9h
mov r6,#083h
mov r5,#04dh
mov r4,#047h
;getal 1
;dec = 1114993.750000
;hex = 49881b8e
;	sign = 0
;	exponent = 93
;	mantisa = 81b8e

;getal 2
;dec = -1075624.875000
;hex = c9834d47
;	sign = 1
;	exponent = 93
;	mantisa = 34d47
;getal 1
;dec = -1.036601
;hex = bf84af57
;	sign = 1
;	exponent = 7f
;	mantisa = 4af57
mov 13h,#0bfh
mov 12h,#084h
mov 11h,#0afh
mov 10h,#057h
lcall fdiv32
;
mov r3,#0c9h
mov r2,#0f7h
mov r1,#075h
mov r0,#0c0h
mov r7,#04ah
mov r6,#04fh
mov r5,#09bh
mov r4,#082h
;getal 1
;dec = -2027192.000000
;hex = c9f775c0
;	sign = 1
;	exponent = 93
;	mantisa = 7775c0

;getal 2
;dec = 3401440.500000
;hex = 4a4f9b82
;	sign = 0
;	exponent = 94
;	mantisa = 4f9b82
;getal 1
;dec = -6895372861440.000000
;hex = d4c8ae88
;	sign = 1
;	exponent = a9
;	mantisa = 48ae88
mov 13h,#0d4h
mov 12h,#0c8h
mov 11h,#0aeh
mov 10h,#088h
lcall fmul32

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
;dec = -3171309584380.000000
;hex = d4389830
;	sign = 1
;	exponent = a8
;	mantisa = 389832
mov 13h,#0d4h
mov 12h,#038h
mov 11h,#098h
mov 10h,#030h
lcall fmul32
;
