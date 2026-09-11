#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.public WirelessTradeSelectMon_Exit
	.public WirelessTradeSelectMon_Init
	.public WirelessTradeSelectMon_Main
	.public _0221BF9C
	.public _0221BFA0
	.public _0221BFA4
	.public _0221BFA8
	.public _0221BFAC
	.public _0221BFB0
	.public _0221BFB4
	.public _0221BFB8
	.public _0221C080
	.public _0221C084
	.public _0221C088
	.public _0221C1AC
	.public _0221C1B0
	.public _0221C1B4
	.public _0221C1B8
	.public _0221C1BC
	.public _0221C1C0
	.public _0221C240
	.public _0221C244
	.public _0221C248
	.public _0221C24C
	.public _0221C26E
	.public _0221C270
	.public _0221C284
	.public _0221C28A
	.public _0221C28C
	.public _0221C298
	.public _0221C2A8
	.public _0221C2B0
	.public _0221C2B8
	.public _0221C2D6
	.public _0221C2F4
	.public _0221C330
	.public _0221C380
	.public _0221C39C
	.public _0221C3AA
	.public _0221C3B4
	.public _0221C3CA
	.public _0221C3F0
	.public _0221C412
	.public _0221C430
	.public _0221C466
	.public _0221C482
	.public _0221C48A
	.public _0221C51A
	.public _0221C542
	.public _0221C558
	.public _0221C578
	.public _0221C584
	.public _0221C59C
	.public _0221C5C0
	.public _0221C5C4
	.public _0221C5C8
	.public _0221C5CC
	.public _0221C5D0
	.public _0221C5D4
	.public _0221C5D8
	.public _0221C5DC
	.public _0221C5F2
	.public _0221C5FE
	.public _0221C626
	.public _0221C64A
	.public _0221C678
	.public _0221C686
	.public _0221C68E
	.public _0221C6A4
	.public _0221C6A6
	.public _0221C6CA
	.public _0221C6D8
	.public _0221C6E6
	.public _0221C6FA
	.public _0221C70A
	.public _0221C722
	.public _0221C736
	.public _0221C748
	.public _0221C76C
	.public _0221C774
	.public _0221C77A
	.public _0221C77C
	.public _0221C782
	.public _0221C78E
	.public _0221C796
	.public _0221C7B2
	.public _0221C7D0
	.public _0221C7E4
	.public _0221C804
	.public _0221C812
	.public _0221C82E
	.public _0221C83A
	.public _0221C84C
	.public _0221C87E
	.public _0221C88E
	.public _0221C890
	.public _0221C8CA
	.public _0221C90C
	.public _0221C94C
	.public _0221C99E
	.public _0221C9A4
	.public _0221C9A8
	.public _0221C9AC
	.public _0221C9B0
	.public _0221C9B4
	.public _0221C9B8
	.public _0221C9BC
	.public _0221C9C0
	.public _0221C9C4
	.public _0221C9C8
	.public _0221C9CC
	.public _0221C9D0
	.public _0221C9D4
	.public _0221CA50
	.public _0221CA60
	.public _0221CAA6
	.public _0221CACE
	.public _0221CAD4
	.public _0221CAD8
	.public _0221CB48
	.public _0221CB4C
	.public _0221CB50
	.public _0221CB54
	.public _0221CB58
	.public _0221CBD4
	.public _0221CBEE
	.public _0221CBF0
	.public _0221CBF4
	.public _0221CBF8
	.public _0221CBFC
	.public _0221CC00
	.public _0221CC04
	.public _0221CC08
	.public _0221CC22
	.public _0221CC38
	.public _0221CC40
	.public _0221CC46
	.public _0221CC4C
	.public _0221CC72
	.public _0221CCA8
	.public _0221CCAC
	.public _0221CCE4
	.public _0221CD22
	.public _0221CD38
	.public _0221CD4A
	.public _0221CD60
	.public _0221CD64
	.public _0221CD68
	.public _0221CD6C
	.public _0221CD70
	.public _0221CE14
	.public _0221CE18
	.public _0221CE6C
	.public _0221CE84
	.public _0221CE88
	.public _0221CE8C
	.public _0221CE90
	.public _0221CE94
	.public _0221CEA2
	.public _0221CEB4
	.public _0221CFFC
	.public _0221D0C0
	.public _0221D0C4
	.public _0221D0C8
	.public _0221D0CC
	.public _0221D0D0
	.public _0221D0D4
	.public _0221D0D8
	.public _0221D0DC
	.public _0221D0E0
	.public _0221D0E4
	.public _0221D0E8
	.public _0221D1B0
	.public _0221D1B4
	.public _0221D1B8
	.public _0221D1BC
	.public _0221D1C0
	.public _0221D1C4
	.public _0221D232
	.public _0221D250
	.public _0221D256
	.public _0221D3E4
	.public _0221D424
	.public _0221D5C0
	.public _0221D5F8
	.public _0221D656
	.public _0221D66E
	.public _0221D6D4
	.public _0221D74C
	.public _0221D76A
	.public _0221D78E
	.public _0221D7B0
	.public _0221D836
	.public _0221D842
	.public _0221D8AC
	.public _0221D8B0
	.public _0221D8B4
	.public _0221D8B8
	.public _0221D8BC
	.public _0221D8C0
	.public _0221D92C
	.public _0221D9EC
	.public _0221DA54
	.public _0221DABA
	.public _0221DB0C
	.public _0221DB94
	.public _0221DBE4
	.public _0221DBE8
	.public _0221DBEC
	.public _0221DBF0
	.public _0221DC08
	.public _0221DC12
	.public _0221DC1C
	.public _0221DC26
	.public _0221DC2C
	.public _0221DC30
	.public _0221DC8E
	.public _0221DC96
	.public _0221DCAA
	.public _0221DCAC
	.public _0221DCB0
	.public _0221DCB4
	.public _0221DCB8
	.public _0221DCD2
	.public _0221DD12
	.public _0221DD20
	.public _0221DD28
	.public _0221DD30
	.public _0221DD46
	.public _0221DD78
	.public _0221DD96
	.public _0221DDAC
	.public _0221DDB0
	.public _0221DDB4
	.public _0221DDB8
	.public _0221DDBC
	.public _0221DDFA
	.public _0221DE00
	.public _0221DE08
	.public _0221DE0C
	.public _0221DE3C
	.public _0221DE50
	.public _0221DE54
	.public _0221DE8A
	.public _0221DED8
	.public _0221DF18
	.public _0221DF52
	.public _0221DF82
	.public _0221DF8E
	.public _0221DF9A
	.public _0221DFA0
	.public _0221DFA4
	.public _0221DFA8
	.public _0221DFAC
	.public _0221DFB0
	.public _0221DFB4
	.public _0221DFE4
	.public _0221E008
	.public _0221E014
	.public _0221E030
	.public _0221E034
	.public _0221E038
	.public _0221E03C
	.public _0221E040
	.public _0221E044
	.public _0221E048
	.public _0221E04C
	.public _0221E062
	.public _0221E09C
	.public _0221E0D6
	.public _0221E130
	.public _0221E134
	.public _0221E138
	.public _0221E13C
	.public _0221E140
	.public _0221E188
	.public _0221E18C
	.public _0221E190
	.public _0221E1C6
	.public _0221E1D0
	.public _0221E218
	.public _0221E250
	.public _0221E258
	.public _0221E25C
	.public _0221E260
	.public _0221E264
	.public _0221E268
	.public _0221E26C
	.public _0221E2B4
	.public _0221E2B8
	.public _0221E2BC
	.public _0221E2D8
	.public _0221E316
	.public _0221E31C
	.public _0221E320
	.public _0221E324
	.public _0221E328
	.public _0221E32C
	.public _0221E350
	.public _0221E386
	.public _0221E390
	.public _0221E398
	.public _0221E3A6
	.public _0221E3AC
	.public _0221E3B0
	.public _0221E3B4
	.public _0221E3B8
	.public _0221E3EE
	.public _0221E3F8
	.public _0221E42C
	.public _0221E450
	.public _0221E458
	.public _0221E45C
	.public _0221E460
	.public _0221E464
	.public _0221E468
	.public _0221E46C
	.public _0221E470
	.public _0221E494
	.public _0221E4C0
	.public _0221E506
	.public _0221E530
	.public _0221E534
	.public _0221E538
	.public _0221E53C
	.public _0221E540
	.public _0221E544
	.public _0221E548
	.public _0221E54C
	.public _0221E550
	.public _0221E554
	.public _0221E580
	.public _0221E5AA
	.public _0221E5EC
	.public _0221E5F0
	.public _0221E5F4
	.public _0221E5F8
	.public _0221E5FC
	.public _0221E632
	.public _0221E63C
	.public _0221E644
	.public _0221E668
	.public _0221E670
	.public _0221E674
	.public _0221E678
	.public _0221E67C
	.public _0221E680
	.public _0221E6B6
	.public _0221E6C0
	.public _0221E6CA
	.public _0221E6EA
	.public _0221E6F0
	.public _0221E708
	.public _0221E70E
	.public _0221E714
	.public _0221E718
	.public _0221E71C
	.public _0221E720
	.public _0221E724
	.public _0221E728
	.public _0221E73C
	.public _0221E75A
	.public _0221E770
	.public _0221E77C
	.public _0221E7C2
	.public _0221E7FE
	.public _0221E808
	.public _0221E828
	.public _0221E82E
	.public _0221E838
	.public _0221E83C
	.public _0221E840
	.public _0221E844
	.public _0221E848
	.public _0221E84C
	.public _0221E850
	.public _0221E854
	.public _0221E898
	.public _0221E8CC
	.public _0221E8D0
	.public _0221E8D4
	.public _0221E8D8
	.public _0221E8DC
	.public _0221E8E0
	.public _0221E8E4
	.public _0221E8E8
	.public _0221E908
	.public _0221E90E
	.public _0221E918
	.public _0221E91C
	.public _0221E920
	.public _0221E924
	.public _0221E99C
	.public _0221E9A0
	.public _0221E9A4
	.public _0221EA5C
	.public _0221EA60
	.public _0221EA64
	.public _0221EA68
	.public _0221EA6C
	.public _0221EA70
	.public _0221EA94
	.public _0221EA9E
	.public _0221EAEA
	.public _0221EB32
	.public _0221EB78
	.public _0221EB80
	.public _0221EB84
	.public _0221EB88
	.public _0221EB8C
	.public _0221EB90
	.public _0221EB94
	.public _0221EB98
	.public _0221EBEC
	.public _0221EBF0
	.public _0221EBF4
	.public _0221EC14
	.public _0221EC1A
	.public _0221EC24
	.public _0221EC28
	.public _0221EC2C
	.public _0221EC30
	.public _0221EC46
	.public _0221EC70
	.public _0221EC84
	.public _0221ECBC
	.public _0221ECD0
	.public _0221ED54
	.public _0221ED58
	.public _0221ED5C
	.public _0221ED60
	.public _0221ED64
	.public _0221ED68
	.public _0221ED6C
	.public _0221ED70
	.public _0221ED74
	.public _0221ED78
	.public _0221ED7C
	.public _0221EDF2
	.public _0221EE14
	.public _0221EEE0
	.public _0221EEE8
	.public _0221EEEC
	.public _0221EEF0
	.public _0221EEF4
	.public _0221EEF8
	.public _0221EEFC
	.public _0221EF00
	.public _0221EF04
	.public _0221EF08
	.public _0221EF34
	.public _0221EF80
	.public _0221EFA6
	.public _0221EFB2
	.public _0221F004
	.public _0221F008
	.public _0221F00C
	.public _0221F010
	.public _0221F014
	.public _0221F018
	.public _0221F01C
	.public _0221F020
	.public _0221F024
	.public _0221F0B0
	.public _0221F0B4
	.public _0221F0B8
	.public _0221F0BC
	.public _0221F0C0
	.public _0221F11C
	.public _0221F152
	.public _0221F15C
	.public _0221F17A
	.public _0221F1A4
	.public _0221F1AC
	.public _0221F1C8
	.public _0221F1E4
	.public _0221F1F6
	.public _0221F238
	.public _0221F240
	.public _0221F244
	.public _0221F248
	.public _0221F24C
	.public _0221F250
	.public _0221F254
	.public _0221F29C
	.public _0221F2A0
	.public _0221F2A4
	.public _0221F2DA
	.public _0221F2E4
	.public _0221F2FC
	.public _0221F33E
	.public _0221F344
	.public _0221F348
	.public _0221F34C
	.public _0221F350
	.public _0221F37C
	.public _0221F382
	.public _0221F398
	.public _0221F39C
	.public _0221F3A0
	.public _0221F3A4
	.public _0221F3A8
	.public _0221F3AC
	.public _0221F3E8
	.public _0221F3EC
	.public _0221F3F0
	.public _0221F498
	.public _0221F49C
	.public _0221F4A0
	.public _0221F4A4
	.public _0221F4A8
	.public _0221F4AC
	.public _0221F4CC
	.public _0221F4D0
	.public _0221F4F4
	.public _0221F540
	.public _0221F586
	.public _0221F58C
	.public _0221F590
	.public _0221F594
	.public _0221F598
	.public _0221F59C
	.public _0221F614
	.public _0221F62C
	.public _0221F664
	.public _0221F6BC
	.public _0221F70C
	.public _0221F710
	.public _0221F744
	.public _0221F774
	.public _0221F778
	.public _0221F77C
	.public _0221F796
	.public _0221F798
	.public _0221F7B8
	.public _0221F7C0
	.public _0221F7C8
	.public _0221F7D2
	.public _0221F7D8
	.public _0221F7DC
	.public _0221F7F6
	.public _0221F80E
	.public _0221F814
	.public _0221F826
	.public _0221F83E
	.public _0221F844
	.public _0221F848
	.public _0221F84C
	.public _0221F860
	.public _0221F886
	.public _0221F888
	.public _0221F88C
	.public _0221F8AC
	.public _0221F8B0
	.public _0221F8C8
	.public _0221F8CC
	.public _0221FA3A
	.public _0221FA84
	.public _0221FAD0
	.public _0221FAD4
	.public _0221FAD8
	.public _0221FADC
	.public _0221FAE6
	.public _0221FAF8
	.public _0221FB70
	.public _0221FB8C
	.public _0221FBBA
	.public _0221FBC6
	.public _0221FBFC
	.public _0221FC00
	.public _0221FC04
	.public _0221FC6A
	.public _0221FC7A
	.public _0221FC82
	.public _0221FC9A
	.public _0221FD10
	.public _0221FD14
	.public _0221FD18
	.public _0221FD1C
	.public _0221FD2C
	.public _0221FD30
	.public _0221FD34
	.public ov65_0221BFBC
	.public ov65_0221BFEC
	.public ov65_0221C08C
	.public ov65_0221C1C4
	.public ov65_0221C3DC
	.public ov65_0221C414
	.public ov65_0221C46C
	.public ov65_0221C5E0
	.public ov65_0221C9D8
	.public ov65_0221CA64
	.public ov65_0221CADC
	.public ov65_0221CB5C
	.public ov65_0221CC0C
	.public ov65_0221CCB0
	.public ov65_0221CD0C
	.public ov65_0221CE1C
	.public ov65_0221CE98
	.public ov65_0221CEB8
	.public ov65_0221D0EC
	.public ov65_0221D1C8
	.public ov65_0221D204
	.public ov65_0221D25C
	.public ov65_0221D280
	.public ov65_0221D3B8
	.public ov65_0221D3E8
	.public ov65_0221D57C
	.public ov65_0221D5FC
	.public ov65_0221D648
	.public ov65_0221D674
	.public ov65_0221D8C4
	.public ov65_0221D930
	.public ov65_0221DBF4
	.public ov65_0221DC34
	.public ov65_0221DCBC
	.public ov65_0221DCFC
	.public ov65_0221DD34
	.public ov65_0221DDC0
	.public ov65_0221DE10
	.public ov65_0221DE24
	.public ov65_0221DE58
	.public ov65_0221DE64
	.public ov65_0221DE8C
	.public ov65_0221DEA0
	.public ov65_0221DF0C
	.public ov65_0221DF1C
	.public ov65_0221DFB8
	.public ov65_0221E050
	.public ov65_0221E06C
	.public ov65_0221E144
	.public ov65_0221E194
	.public ov65_0221E270
	.public ov65_0221E2C0
	.public ov65_0221E330
	.public ov65_0221E354
	.public ov65_0221E3BC
	.public ov65_0221E474
	.public ov65_0221E558
	.public ov65_0221E600
	.public ov65_0221E684
	.public ov65_0221E72C
	.public ov65_0221E740
	.public ov65_0221E858
	.public ov65_0221E8EC
	.public ov65_0221E928
	.public ov65_0221E9A8
	.public ov65_0221EA74
	.public ov65_0221EB9C
	.public ov65_0221EBF8
	.public ov65_0221EC34
	.public ov65_0221ED80
	.public ov65_0221ED94
	.public ov65_0221EE18
	.public ov65_0221EF0C
	.public ov65_0221F028
	.public ov65_0221F0C4
	.public ov65_0221F0D8
	.public ov65_0221F120
	.public ov65_0221F258
	.public ov65_0221F2A8
	.public ov65_0221F354
	.public ov65_0221F3B0
	.public ov65_0221F3F4
	.public ov65_0221F4B0
	.public ov65_0221F4D4
	.public ov65_0221F5A0
	.public ov65_0221F714
	.public ov65_0221F748
	.public ov65_0221F760
	.public ov65_0221F780
	.public ov65_0221F79C
	.public ov65_0221F7E0
	.public ov65_0221F850
	.public ov65_0221F864
	.public ov65_0221F890
	.public ov65_0221F8B4
	.public ov65_0221F8D0
	.public ov65_0221FAE0
	.public ov65_0221FB4C
	.public ov65_0221FB90
	.public ov65_0221FC08
	.public ov65_0221FC54
	.public ov65_0221FCA0
	.public ov65_0221FD20
	.public ov65_0221FD3C
	.public ov65_0221FD48
	.public ov65_0221FD58
	.public ov65_0221FD68
	.public ov65_0221FD6C
	.public ov65_0221FD70
	.public ov65_0221FD80
	.public ov65_0221FD9C
	.public ov65_0221FDB8
	.public ov65_0221FDD4
	.public ov65_0221FDF0
	.public ov65_0221FE0C
	.public ov65_0221FE28
	.public ov65_0221FE44
	.public ov65_0221FE6C
	.public ov65_0221FEA4
	.public ov65_0221FEA8
	.public ov65_0221FEEC
	.public ov65_0221FF4C
	.public ov65_0221FF50
	.public ov65_0221FFB4
	.public ov65_022200EC
	.public ov65_0222010C
	.public ov65_02220144
	.include "overlay_65.inc"
	.include "global.inc"

	.text
	.public ov65_0221D25C
	.public ov65_0221D648
	.public ov65_0221DE10
	.public ov65_0221DE58
	.public ov65_0221DE64
	.public ov65_0221DE8C
	.public ov65_0221DF0C
	.public ov65_0221E050
	.public ov65_0221E330
	.public ov65_0221E72C
	.public ov65_0221ED80
	.public ov65_0221F0C4
	.public ov65_0221F4B0
	.public ov65_0221F714
	.public ov65_0221F748
	.public ov65_0221F760
	.public ov65_0221F850
	.public ov65_0221F8B4
	.public ov65_0221FD20

	thumb_func_start ov65_0221E740
ov65_0221E740: ; 0x0221E740
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r1, #0
	ldr r0, _0221E838 ; =0x00003678
	mvn r1, r1
	str r1, [r5, r0]
	mov r6, #0
	bl sub_02037454
	cmp r0, #0
	ble _0221E77C
	ldr r7, _0221E83C ; =0x000035F8
	add r4, r5, #0
_0221E75A:
	ldr r0, [r4, r7]
	cmp r0, #2
	bne _0221E770
	ldr r0, _0221E838 ; =0x00003678
	lsl r1, r6, #2
	str r6, [r5, r0]
	mov r2, #0
	add r1, r5, r1
	sub r0, #0x80
	str r2, [r1, r0]
	b _0221E77C
_0221E770:
	add r4, r4, #4
	add r6, r6, #1
	bl sub_02037454
	cmp r6, r0
	blt _0221E75A
_0221E77C:
	ldr r0, _0221E838 ; =0x00003678
	mov r1, #0
	ldr r2, [r5, r0]
	mvn r1, r1
	cmp r2, r1
	bne _0221E7C2
	add r0, #0xc
	ldr r0, [r5, r0]
	bl DestroyMsgData
	mov r0, #0xda
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl MessageFormat_Delete
	mov r0, #0x13
	bl sub_02037AC0
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r5, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221E840 ; =0x000005B4
	ldr r3, [r5, r3]
	add r0, r5, r0
	mov r1, #0x1c
	mov r2, #1
	bl ov65_0221FB90
	ldr r1, _0221E844 ; =ov65_0221E72C
	ldr r0, _0221E848 ; =0x00002220
	str r1, [r5, r0]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0221E7C2:
	ldr r0, [r5, #4]
	bl Save_Bag_Get
	ldr r1, _0221E84C ; =0x000001B5
	mov r2, #1
	mov r3, #0x1a
	bl Bag_HasItem
	cmp r0, #1
	bne _0221E7FE
	ldr r0, _0221E838 ; =0x00003678
	ldr r0, [r5, r0]
	bl sub_02034818
	add r2, r0, #0
	mov r0, #0xda
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #0
	bl BufferPlayersName
	add r0, r5, #0
	mov r1, #0x3e
	bl ov65_0221E330
	ldr r1, _0221E850 ; =ov65_0221E684
	ldr r0, _0221E848 ; =0x00002220
	str r1, [r5, r0]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0221E7FE:
	ldr r0, [r5, #4]
	bl sub_0202C6F4
	add r6, r0, #0
	mov r4, #0
_0221E808:
	add r0, r6, #0
	add r1, r4, #0
	bl sub_0202C2DC
	cmp r0, #0
	bne _0221E828
	mov r0, #0
	str r0, [sp]
	ldr r1, _0221E838 ; =0x00003678
	ldr r0, [r5, #4]
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0x1a
	bl sub_0203A280
	b _0221E82E
_0221E828:
	add r4, r4, #1
	cmp r4, #0x20
	blt _0221E808
_0221E82E:
	ldr r1, _0221E854 ; =ov65_0221E740
	ldr r0, _0221E848 ; =0x00002220
	str r1, [r5, r0]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E838: .word 0x00003678
_0221E83C: .word 0x000035F8
_0221E840: .word 0x000005B4
_0221E844: .word ov65_0221E72C
_0221E848: .word 0x00002220
_0221E84C: .word 0x000001B5
_0221E850: .word ov65_0221E684
_0221E854: .word ov65_0221E740
	thumb_func_end ov65_0221E740


	thumb_func_start ov65_0221E858
ov65_0221E858: ; 0x0221E858
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r1, _0221E8CC ; =0x000035F8
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0x1a
	bl sub_0203A1C4
	cmp r0, #0
	bne _0221E898
	mov r0, #0x13
	bl sub_02037AC0
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221E8D0 ; =0x000005B4
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0x1c
	mov r2, #1
	bl ov65_0221FB90
	ldr r1, _0221E8D4 ; =ov65_0221E72C
	ldr r0, _0221E8D8 ; =0x00002220
	add sp, #4
	str r1, [r4, r0]
	mov r0, #0
	pop {r3, r4, pc}
_0221E898:
	mov r0, #0x1a
	bl MessageFormat_New
	mov r1, #0xda
	lsl r1, r1, #6
	str r0, [r4, r1]
	ldr r2, _0221E8DC ; =0x0000030B
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x1a
	bl NewMsgDataFromNarc
	ldr r1, _0221E8E0 ; =0x00003684
	str r0, [r4, r1]
	ldr r0, [r4, #4]
	bl sub_0202C6F4
	ldr r1, _0221E8E4 ; =0x000036A0
	str r0, [r4, r1]
	ldr r1, _0221E8E8 ; =ov65_0221E740
	ldr r0, _0221E8D8 ; =0x00002220
	str r1, [r4, r0]
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_0221E8CC: .word 0x000035F8
_0221E8D0: .word 0x000005B4
_0221E8D4: .word ov65_0221E72C
_0221E8D8: .word 0x00002220
_0221E8DC: .word 0x0000030B
_0221E8E0: .word 0x00003684
_0221E8E4: .word 0x000036A0
_0221E8E8: .word ov65_0221E740
	thumb_func_end ov65_0221E858


	thumb_func_start ov65_0221E8EC
ov65_0221E8EC: ; 0x0221E8EC
	ldr r2, [r0, #0x6c]
	cmp r2, #0
	beq _0221E918
	ldr r1, [r0, #0x70]
	cmp r1, #0
	beq _0221E918
	cmp r2, #1
	bne _0221E908
	cmp r1, #1
	bne _0221E908
	ldr r2, _0221E91C ; =ov65_0221E858
	ldr r1, _0221E920 ; =0x00002220
	str r2, [r0, r1]
	b _0221E90E
_0221E908:
	ldr r2, _0221E924 ; =ov65_0221E270
	ldr r1, _0221E920 ; =0x00002220
	str r2, [r0, r1]
_0221E90E:
	mov r1, #0
	str r1, [r0, #0x6c]
	str r1, [r0, #0x70]
	mov r1, #0x1d
	str r1, [r0, #0x74]
_0221E918:
	mov r0, #0
	bx lr
	.balign 4, 0
_0221E91C: .word ov65_0221E858
_0221E920: .word 0x00002220
_0221E924: .word ov65_0221E270
	thumb_func_end ov65_0221E8EC


	thumb_func_start ov65_0221E928
ov65_0221E928: ; 0x0221E928
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0x1a
	mov r1, #0
	add r6, r2, #0
	bl TouchscreenListMenuSpawner_Create
	ldr r1, _0221E99C ; =0x000036C4
	mov r2, #0x18
	str r0, [r5, r1]
	add r0, sp, #0xc
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, _0221E9A0 ; =ov65_0221FD3C
	add r2, sp, #0xc
	ldrh r3, [r0]
	add r1, sp, #0xc
	strh r3, [r2]
	ldrh r3, [r0, #2]
	strh r3, [r2, #2]
	ldrh r3, [r0, #4]
	strh r3, [r2, #4]
	ldrh r3, [r0, #6]
	strh r3, [r2, #6]
	ldrh r3, [r0, #8]
	ldrh r0, [r0, #0xa]
	strh r3, [r2, #8]
	strh r0, [r2, #0xa]
	ldr r0, _0221E9A4 ; =0x00000668
	mov r3, #0x11
	ldr r0, [r5, r0]
	str r0, [sp, #0x18]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	str r0, [sp, #0x1c]
	lsl r0, r6, #0x18
	strb r4, [r2, #0x14]
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xd
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, _0221E99C ; =0x000036C4
	str r2, [sp, #8]
	ldr r0, [r5, r0]
	bl TouchscreenListMenu_Create
	add r4, r0, #0
	bl ov65_0221F890
	add r0, r4, #0
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	nop
_0221E99C: .word 0x000036C4
_0221E9A0: .word ov65_0221FD3C
_0221E9A4: .word 0x00000668
	thumb_func_end ov65_0221E928


	thumb_func_start ov65_0221E9A8
ov65_0221E9A8: ; 0x0221E9A8
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r0, _0221EA5C ; =0x00002224
	add r1, r4, #0
	add r1, #0x94
	ldr r0, [r4, r0]
	ldr r1, [r1]
	bl Party_GetMonByIndex
	bl Mon_GetBoxMon
	add r2, r0, #0
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl BufferBoxMonNickname
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl FillBgTilemapRect
	mov r3, #0x62
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #8
	str r0, [sp]
	ldr r0, _0221EA60 ; =0x000005A4
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0x10
	mov r2, #1
	bl ov65_0221FB90
	mov r0, #3
	mov r1, #0x1a
	bl ListMenuItems_New
	ldr r1, _0221EA64 ; =0x00000668
	mov r2, #0x11
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	mov r3, #0
	bl ListMenuItems_AppendFromMsgData
	ldr r0, _0221EA64 ; =0x00000668
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r2, #0x12
	mov r3, #1
	bl ListMenuItems_AppendFromMsgData
	ldr r0, _0221EA64 ; =0x00000668
	mov r1, #0x19
	lsl r1, r1, #4
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	mov r2, #0x13
	mov r3, #2
	bl ListMenuItems_AppendFromMsgData
	add r0, r4, #0
	mov r1, #3
	mov r2, #9
	bl ov65_0221E928
	ldr r1, _0221EA68 ; =0x000036C8
	str r0, [r4, r1]
	ldr r1, _0221EA6C ; =ov65_0221EA74
	ldr r0, _0221EA70 ; =0x00002220
	str r1, [r4, r0]
	mov r0, #0
	add sp, #0x10
	pop {r4, pc}
	nop
_0221EA5C: .word 0x00002224
_0221EA60: .word 0x000005A4
_0221EA64: .word 0x00000668
_0221EA68: .word 0x000036C8
_0221EA6C: .word ov65_0221EA74
_0221EA70: .word 0x00002220
	thumb_func_end ov65_0221E9A8


	thumb_func_start ov65_0221EA74
ov65_0221EA74: ; 0x0221EA74
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r0, _0221EB80 ; =0x000036C8
	ldr r0, [r4, r0]
	bl TouchscreenListMenu_HandleInput
	cmp r0, #2
	bhi _0221EA94
	cmp r0, #0
	beq _0221EA9E
	cmp r0, #1
	beq _0221EAEA
	cmp r0, #2
	beq _0221EB32
	b _0221EB78
_0221EA94:
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _0221EB32
	b _0221EB78
_0221EA9E:
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl FillBgTilemapRect
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221EB84 ; =0x00000594
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0xf
	mov r2, #1
	bl ov65_0221FB90
	add r0, r4, #0
	bl ov65_0221F4B0
	ldr r0, _0221EB88 ; =0x00000668
	ldr r0, [r4, r0]
	bl ListMenuItems_Delete
	ldr r1, _0221EB8C ; =ov65_0221E050
	ldr r0, _0221EB90 ; =0x00002220
	add sp, #0x10
	str r1, [r4, r0]
	mov r0, #3
	pop {r4, pc}
_0221EAEA:
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl FillBgTilemapRect
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221EB94 ; =0x000005B4
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0x14
	mov r2, #1
	bl ov65_0221FB90
	add r0, r4, #0
	bl ov65_0221F4B0
	ldr r0, _0221EB88 ; =0x00000668
	ldr r0, [r4, r0]
	bl ListMenuItems_Delete
	ldr r1, _0221EB98 ; =ov65_0221EB9C
	ldr r0, _0221EB90 ; =0x00002220
	str r1, [r4, r0]
	b _0221EB78
_0221EB32:
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl FillBgTilemapRect
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221EB84 ; =0x00000594
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0xf
	mov r2, #1
	bl ov65_0221FB90
	add r0, r4, #0
	bl ov65_0221F4B0
	ldr r0, _0221EB88 ; =0x00000668
	ldr r0, [r4, r0]
	bl ListMenuItems_Delete
	ldr r1, _0221EB8C ; =ov65_0221E050
	ldr r0, _0221EB90 ; =0x00002220
	str r1, [r4, r0]
_0221EB78:
	mov r0, #0
	add sp, #0x10
	pop {r4, pc}
	nop
_0221EB80: .word 0x000036C8
_0221EB84: .word 0x00000594
_0221EB88: .word 0x00000668
_0221EB8C: .word ov65_0221E050
_0221EB90: .word 0x00002220
_0221EB94: .word 0x000005B4
_0221EB98: .word ov65_0221EB9C
	thumb_func_end ov65_0221EA74


	thumb_func_start ov65_0221EB9C
ov65_0221EB9C: ; 0x0221EB9C
	push {r4, lr}
	sub sp, #0x10
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl FillBgTilemapRect
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221EBEC ; =0x000005B4
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0x14
	mov r2, #1
	bl ov65_0221FB90
	add r0, r4, #0
	mov r1, #0x18
	mov r2, #2
	bl ov65_0221DE24
	ldr r1, _0221EBF0 ; =ov65_0221EBF8
	ldr r0, _0221EBF4 ; =0x00002220
	str r1, [r4, r0]
	mov r0, #0
	add sp, #0x10
	pop {r4, pc}
	nop
_0221EBEC: .word 0x000005B4
_0221EBF0: .word ov65_0221EBF8
_0221EBF4: .word 0x00002220
	thumb_func_end ov65_0221EB9C


	thumb_func_start ov65_0221EBF8
ov65_0221EBF8: ; 0x0221EBF8
	ldr r2, [r0, #0x6c]
	cmp r2, #0
	beq _0221EC24
	ldr r1, [r0, #0x70]
	cmp r1, #0
	beq _0221EC24
	cmp r2, #2
	bne _0221EC14
	cmp r1, #2
	bne _0221EC14
	ldr r2, _0221EC28 ; =ov65_0221EC34
	ldr r1, _0221EC2C ; =0x00002220
	str r2, [r0, r1]
	b _0221EC1A
_0221EC14:
	ldr r2, _0221EC30 ; =ov65_0221E270
	ldr r1, _0221EC2C ; =0x00002220
	str r2, [r0, r1]
_0221EC1A:
	mov r1, #0x18
	str r1, [r0, #0x74]
	mov r1, #0
	str r1, [r0, #0x6c]
	str r1, [r0, #0x70]
_0221EC24:
	mov r0, #0
	bx lr
	.balign 4, 0
_0221EC28: .word ov65_0221EC34
_0221EC2C: .word 0x00002220
_0221EC30: .word ov65_0221E270
	thumb_func_end ov65_0221EBF8


	thumb_func_start ov65_0221EC34
ov65_0221EC34: ; 0x0221EC34
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	ldr r0, _0221ED54 ; =0x00000444
	mov r6, #0
	add r0, r7, r0
	add r4, r7, #0
	add r5, r7, #0
	str r0, [sp, #4]
_0221EC46:
	add r0, r7, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r6, r0
	beq _0221EC84
	mov r0, #0xdf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0221ED58 ; =0x0000069E
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _0221EC70
	mov r0, #0xeb
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0221EC70:
	ldr r0, _0221ED5C ; =0x000006A8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0221EC84
	mov r0, #0xf7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0221EC84:
	add r0, r6, #7
	lsl r1, r0, #4
	ldr r0, [sp, #4]
	add r0, r0, r1
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r7, #0
	add r0, #0x98
	ldr r0, [r0]
	sub r0, r0, #6
	cmp r6, r0
	beq _0221ECD0
	mov r0, #0xe5
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0221ED60 ; =0x000006FE
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _0221ECBC
	mov r0, #0xf1
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0221ECBC:
	ldr r0, _0221ED64 ; =0x00000708
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0221ECD0
	mov r0, #0xfd
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0221ECD0:
	add r0, r6, #0
	add r0, #0xd
	lsl r1, r0, #4
	ldr r0, [sp, #4]
	add r0, r0, r1
	bl ClearWindowTilemapAndScheduleTransfer
	add r6, r6, #1
	add r4, r4, #4
	add r5, #0x10
	cmp r6, #6
	blt _0221EC46
	mov r0, #0xd1
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xd2
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r0, r7, #0
	add r0, #0x94
	ldr r0, [r0]
	ldr r1, _0221ED68 ; =ov65_0221FF4C
	lsl r2, r0, #3
	mov r0, #0x20
	str r0, [sp]
	ldr r0, _0221ED6C ; =0x000022D0
	ldr r1, [r1, r2]
	ldr r3, _0221ED70 ; =ov65_0221FF50
	add r0, r7, r0
	ldr r2, [r3, r2]
	add r1, #0x10
	sub r2, r2, #6
	mov r3, #0x30
	bl ov65_0221ED80
	add r0, r7, #0
	add r0, #0x98
	ldr r0, [r0]
	ldr r1, _0221ED68 ; =ov65_0221FF4C
	lsl r2, r0, #3
	mov r0, #0x20
	str r0, [sp]
	ldr r0, _0221ED74 ; =0x000022E8
	ldr r1, [r1, r2]
	ldr r3, _0221ED70 ; =ov65_0221FF50
	add r0, r7, r0
	ldr r2, [r3, r2]
	add r1, #0x10
	sub r2, r2, #6
	mov r3, #0xb0
	bl ov65_0221ED80
	ldr r1, _0221ED78 ; =0x000022C8
	mov r0, #0
	str r0, [r7, r1]
	ldr r2, _0221ED7C ; =ov65_0221EE18
	sub r1, #0xa8
	str r2, [r7, r1]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221ED54: .word 0x00000444
_0221ED58: .word 0x0000069E
_0221ED5C: .word 0x000006A8
_0221ED60: .word 0x000006FE
_0221ED64: .word 0x00000708
_0221ED68: .word ov65_0221FF4C
_0221ED6C: .word 0x000022D0
_0221ED70: .word ov65_0221FF50
_0221ED74: .word 0x000022E8
_0221ED78: .word 0x000022C8
_0221ED7C: .word ov65_0221EE18
	thumb_func_end ov65_0221EC34
