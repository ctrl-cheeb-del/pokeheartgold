#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.public _02093300
	.public _02093314
	.public _02093348
	.public _0209334C
	.public _02093350
	.public _020933AA
	.public _0209341C
	.public _02093420
	.public _02093424
	.public _02093428
	.public _0209342C
	.public _02093430
	.public _02093434
	.public _02093438
	.public _0209343C
	.public _02093580
	.public _02093584
	.public _02093588
	.public _0209358C
	.public _02093590
	.public _020935B2
	.public _020935D0
	.public _020935D4
	.public _020935D8
	.public _020935DC
	.public _020935F4
	.public _02093602
	.public _02093608
	.public _02093610
	.public _02093618
	.public _02093620
	.public _02093628
	.public _0209362E
	.public _02093674
	.public _0209367A
	.public _02093682
	.public _02093688
	.public _02093694
	.public _0209369C
	.public _020936A8
	.public _020936B0
	.public _020936B8
	.public _020936C0
	.public _020936D8
	.public _020936EE
	.public _020936F6
	.public _02093714
	.public _02093720
	.public _02093722
	.public _0209372C
	.public _0209375A
	.public _0209378A
	.public _020937CE
	.public _020937DC
	.public _020937E4
	.public _020937EC
	.public _02093824
	.public _0209382A
	.public _02093832
	.public _02093850
	.public _02093860
	.public _0209386C
	.public _02093874
	.public _02093878
	.public _0209387C
	.public _02093880
	.public _02093884
	.public _02093888
	.public _0209388C
	.public _02093890
	.public _02093894
	.public _02093898
	.public _020938EC
	.public _020938F6
	.public _02093904
	.public _0209391C
	.public _02093932
	.public _02093964
	.public _02093968
	.public _020939CC
	.public _02093A10
	.public _02093A34
	.public _02093A38
	.public _02093A3C
	.public _02093A4C
	.public _02093A7A
	.public _02093BB8
	.public _02093C0C
	.public _02093C78
	.public _02093C86
	.public _02093CAE
	.public _02093CD0
	.public _02093CD4
	.public _02093CD8
	.public _02093CDC
	.public _02093CE0
	.public _02093D0C
	.public _02093D4E
	.public _02093D90
	.public _02093DA0
	.public _02093DA2
	.public _02093DFA
	.public _02093E10
	.public _02093E50
	.public _02093E5E
	.public _02093E62
	.public _02093E68
	.public _02093E6C
	.public _02093E70
	.public _02093E74
	.public _02093E78
	.public _02093EBE
	.public _02093F60
	.public _02093F6A
	.public _02093F70
	.public _02093F74
	.public _02093F78
	.public _02093F7C
	.public _02093F80
	.public _02093FF4
	.public _02093FF8
	.public _02093FFC
	.public _02094000
	.public _02094048
	.public _020940C0
	.public _0209410C
	.public _0209413C
	.public _02094140
	.public _02094144
	.public _02094148
	.public _0209414C
	.public _02094280
	.public _02094284
	.public _02094288
	.public _020942CC
	.public _020942D8
	.public _0209430C
	.public _0209438E
	.public _020943E8
	.public _020943FA
	.public _02094420
	.public _0209444A
	.public _02094486
	.public _02094494
	.public _020944BA
	.public _02094514
	.public _02094518
	.public _0209451C
	.public _02094520
	.public _02094524
	.public _0209455A
	.public _0209456E
	.public _020945AA
	.public _020945B6
	.public _020945C0
	.public _020945DA
	.public _02094606
	.public _02094654
	.public _02094658
	.public _0209465C
	.public _02094660
	.public _02094664
	.public _02094696
	.public _020946BC
	.public _020946E6
	.public _02094702
	.public _0209472A
	.public _02094740
	.public _02094744
	.public _02094748
	.public _0209474C
	.public _02094750
	.public _02094754
	.public _02094766
	.public _0209478A
	.public _020947E4
	.public _020947F4
	.public _020947FE
	.public _02094816
	.public _0209481A
	.public _02094828
	.public _0209483C
	.public _0209484A
	.public _02094854
	.public _0209485C
	.public _0209488E
	.public _02094890
	.public _020948A0
	.public _020948BA
	.public _020948C0
	.public _020948EE
	.public _020948FC
	.public _02094900
	.public _0209495C
	.public _020949D0
	.public _020949D4
	.public _020949D8
	.public _020949DC
	.public _020949E0
	.public _020949E4
	.public _020949E8
	.public _020949EC
	.public _020949F0
	.public _02094A5E
	.public _02094A64
	.public _02094A68
	.public _02094A6C
	.public _02094A88
	.public _02094A8C
	.public _02094AC0
	.public _02094AE8
	.public _02094B0E
	.public _02094B1A
	.public _02094B48
	.public _02094B5C
	.public _02094BAC
	.public _02094BF0
	.public _02094BF4
	.public _02094BF8
	.public _02094BFC
	.public _02094C00
	.public _02094C04
	.public _02094C64
	.public _02094CB2
	.public _02094CC8
	.public _02094D0C
	.public _02094D10
	.public _02094D14
	.public _02094D18
	.public _02094D78
	.public _02094D90
	.public _02094D94
	.public _02094D98
	.public _02094DF4
	.public _02094EA4
	.public _02094EA8
	.public _02094EAC
	.public _02094EB0
	.public _02094EC4
	.public _02094F00
	.public _02094F08
	.public _02094F12
	.public _02094F58
	.public _02094FBA
	.public _02094FE6
	.public _02095010
	.public _02095014
	.public _02095018
	.public _020950B0
	.public _020950B4
	.public _020950B8
	.public _020950BC
	.public _020950D0
	.public _020950F2
	.public _020950F4
	.public _0209510E
	.public _0209511A
	.public _0209512E
	.public _0209514C
	.public _02095150
	.public _02095154
	.public _02095158
	.public _02095168
	.public _02095172
	.public _02095186
	.public _02095190
	.public _0209519A
	.public _020951A6
	.public _020951B2
	.public _020951BC
	.public _020951C8
	.public _020951D4
	.public _020951E0
	.public _020951EC
	.public _020951FA
	.public _0209520C
	.public _02095216
	.public _0209521E
	.public _02095220
	.public _02095224
	.public _02095228
	.public _0209522C
	.public _02095230
	.public _02095234
	.public _02095268
	.public _02095276
	.public _02095286
	.public _020952B4
	.public _020952C8
	.public _0209531A
	.public _0209531E
	.public _0209532C
	.public _02095342
	.public _02095348
	.public _0209534C
	.public _02095350
	.public _02095380
	.public _0209538E
	.public _0209539A
	.public _0209539C
	.public _020953B4
	.public _02095430
	.public _0209543A
	.public _02095442
	.public _020954A2
	.public _020954AC
	.public _020954B2
	.public _020954B8
	.public _020954BC
	.public _020954C0
	.public _020954C4
	.public _020954C8
	.public _020954F4
	.public _020954FE
	.public _02095532
	.public _02095538
	.public _0209553C
	.public _02095550
	.public _020955BE
	.public _020955DC
	.public _020955E0
	.public _020955E4
	.public _020955E8
	.public _02095604
	.public _0209566E
	.public _0209568C
	.public _02095690
	.public _02095694
	.public _02095698
	.public _020956B0
	.public _020956B4
	.public _020956E2
	.public _020956F0
	.public _0209570C
	.public _02095730
	.public _0209573E
	.public _0209574E
	.public _0209575C
	.public _02095764
	.public _02095768
	.public _0209576C
	.public _02095770
	.public _02095774
	.public _02095778
	.public _0209577C
	.public _0209578C
	.public _02095790
	.public _020957AC
	.public _021083AC
	.public _021083C8
	.public _021083E4
	.public _02108400
	.public sub_020932E0
	.public sub_02093354
	.public sub_02093440
	.public sub_02093594
	.public sub_020935E0
	.public sub_02093630
	.public sub_0209389C
	.public sub_02093908
	.public sub_0209396C
	.public sub_020939B8
	.public sub_02093A40
	.public sub_02093A50
	.public sub_02093B40
	.public sub_02093B84
	.public sub_02093CE4
	.public sub_02093E7C
	.public sub_02093F84
	.public sub_02094004
	.public sub_02094150
	.public sub_0209417C
	.public sub_020941CC
	.public sub_0209428C
	.public sub_020942B0
	.public sub_020943EC
	.public sub_02094400
	.public sub_02094528
	.public sub_02094668
	.public sub_02094758
	.public sub_02094794
	.public sub_020947C0
	.public sub_02094860
	.public sub_02094894
	.public sub_020948C4
	.public sub_020949F4
	.public sub_02094A70
	.public sub_02094A90
	.public sub_02094C08
	.public sub_02094C6C
	.public sub_02094C88
	.public sub_02094D1C
	.public sub_02094D9C
	.public sub_02094DF8
	.public sub_02094EB4
	.public sub_02094F14
	.public sub_02094F5C
	.public sub_0209501C
	.public sub_020950C0
	.public sub_020950D4
	.public sub_020950F8
	.public sub_0209511C
	.public sub_0209515C
	.public sub_02095238
	.public sub_02095354
	.public sub_020954CC
	.public sub_02095540
	.public sub_020955EC
	.public sub_0209569C
	.public sub_020956B8
	.public sub_02095780
	.public sub_02095794
	.include "unk_020932E0.inc"
	.include "global.inc"

	.text
	.public sub_02093594
	.public sub_020935E0
	.public sub_0209389C
	.public sub_02093908
	.public sub_0209396C
	.public sub_020939B8
	.public sub_02093A40
	.public sub_02093B40
	.public sub_02094150
	.public sub_0209417C
	.public sub_0209428C
	.public sub_020943EC
	.public sub_02094758
	.public sub_02094794
	.public sub_02094860
	.public sub_02094894
	.public sub_02094A70
	.public sub_02094C6C
	.public sub_02094D9C
	.public sub_02094DF8
	.public sub_02094EB4
	.public sub_02094F14
	.public sub_020950C0
	.public sub_020950D4
	.public sub_020950F8
	.public sub_0209511C
	.public sub_0209569C
	.public sub_02095780
	.public sub_02095794

	thumb_func_start sub_02093630
sub_02093630: ; 0x02093630
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r4, #0
	add r5, r0, #0
	str r4, [sp]
	bl System_GetTouchHeld
	cmp r0, #0
	bne _02093714
	ldr r0, _02093874 ; =0x000046C0
	ldr r1, [r5, r0]
	cmp r1, #0
	bne _02093714
	ldr r1, _02093878 ; =gSystem
	ldr r4, [r1, #0x48]
	cmp r4, #0
	beq _02093714
	sub r0, #8
	ldr r0, [r5, r0]
	mov r7, #0
	add r6, r7, #0
	bl sub_02095DD8
	cmp r4, #0x20
	bgt _0209367A
	bge _02093688
	cmp r4, #2
	bgt _02093674
	cmp r4, #1
	blt _020936EE
	beq _020936C0
	cmp r4, #2
	beq _020936D8
	b _020936EE
_02093674:
	cmp r4, #0x10
	beq _0209369C
	b _020936EE
_0209367A:
	cmp r4, #0x40
	bgt _02093682
	beq _020936B0
	b _020936EE
_02093682:
	cmp r4, #0x80
	beq _020936B8
	b _020936EE
_02093688:
	cmp r0, #5
	bne _02093694
	add r0, r5, #0
	bl sub_02095540
	b _020936EE
_02093694:
	sub r0, r7, #1
	lsl r0, r0, #0x18
	asr r7, r0, #0x18
	b _020936EE
_0209369C:
	cmp r0, #5
	bne _020936A8
	add r0, r5, #0
	bl sub_020955EC
	b _020936EE
_020936A8:
	add r0, r7, #1
	lsl r0, r0, #0x18
	asr r7, r0, #0x18
	b _020936EE
_020936B0:
	sub r0, r6, #1
	lsl r0, r0, #0x18
	asr r6, r0, #0x18
	b _020936EE
_020936B8:
	add r0, r6, #1
	lsl r0, r0, #0x18
	asr r6, r0, #0x18
	b _020936EE
_020936C0:
	add r0, r5, #0
	bl sub_02095354
	str r0, [sp]
	cmp r0, #0
	beq _020936EE
	cmp r0, #3
	beq _020936EE
	ldr r0, _0209387C ; =0x000005DD
	bl PlaySE
	b _020936EE
_020936D8:
	add r0, r5, #0
	bl sub_020954CC
	str r0, [sp]
	cmp r0, #0
	beq _020936EE
	cmp r0, #3
	beq _020936EE
	ldr r0, _0209387C ; =0x000005DD
	bl PlaySE
_020936EE:
	cmp r7, #0
	bne _020936F6
	cmp r6, #0
	beq _02093714
_020936F6:
	ldr r0, _02093880 ; =0x000046B8
	add r1, r7, #0
	ldr r0, [r5, r0]
	add r2, r6, #0
	bl sub_02095D88
	add r6, r0, #0
	add r0, r5, #0
	bl sub_02095238
	cmp r6, #0
	beq _02093714
	ldr r0, _02093884 ; =0x000005DC
	bl PlaySE
_02093714:
	cmp r4, #0
	bne _02093720
	ldr r0, _02093888 ; =0x000046BC
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02093722
_02093720:
	b _02093860
_02093722:
	bl System_GetTouchNew
	cmp r0, #0
	bne _0209372C
	b _02093832
_0209372C:
	ldr r0, _0209388C ; =0x00004680
	ldr r1, [r5, r0]
	cmp r1, #0
	bne _02093832
	mov r1, #1
	add r0, #0x44
	str r1, [r5, r0]
	ldr r0, _02093890 ; =0x000007E4
	ldr r0, [r5, r0]
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _0209382A
	cmp r4, #0x1e
	bge _0209378A
	ldrb r0, [r5, #0xf]
	cmp r0, #0x12
	bne _0209375A
	cmp r4, #6
	bge _02093824
_0209375A:
	ldr r0, _02093880 ; =0x000046B8
	lsl r2, r4, #0x18
	ldr r0, [r5, r0]
	mov r1, #2
	lsr r2, r2, #0x18
	bl sub_02095D40
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02094794
	cmp r0, #1
	bne _02093824
	ldr r0, _02093894 ; =0x000005EB
	bl PlaySE
	add r0, r5, #0
	mov r1, #1
	add r2, r4, #0
	bl sub_020948C4
	mov r0, #1
	str r0, [sp]
	b _02093824
_0209378A:
	cmp r4, #0x21
	blt _020937CE
	ldrb r0, [r5, #0xd]
	add r0, #0x21
	cmp r4, r0
	bge _020937CE
	ldr r0, _02093880 ; =0x000046B8
	add r2, r4, #0
	sub r2, #0x21
	lsl r2, r2, #0x18
	ldr r0, [r5, r0]
	mov r1, #3
	lsr r2, r2, #0x18
	bl sub_02095D40
	add r1, r4, #0
	add r0, r5, #0
	sub r1, #0x21
	bl sub_02094860
	cmp r0, #1
	bne _02093824
	ldr r0, _02093894 ; =0x000005EB
	bl PlaySE
	sub r4, #0x21
	add r0, r5, #0
	mov r1, #2
	add r2, r4, #0
	bl sub_020948C4
	mov r0, #1
	str r0, [sp]
	b _02093824
_020937CE:
	cmp r4, #0x1e
	beq _020937EC
	cmp r4, #0x1f
	beq _020937DC
	cmp r4, #0x20
	beq _020937E4
	b _02093824
_020937DC:
	add r0, r5, #0
	bl sub_02095540
	b _02093824
_020937E4:
	add r0, r5, #0
	bl sub_020955EC
	b _02093824
_020937EC:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _02093824
	mov r0, #0xe
	lsl r0, r0, #0x10
	str r0, [sp, #4]
	mov r0, #0xb
	lsl r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, sp, #4
	bl Sprite_SetMatrix
	ldr r0, _02093880 ; =0x000046B8
	mov r1, #1
	ldr r0, [r5, r0]
	mov r2, #0
	bl sub_02095D40
	add r0, r5, #0
	bl sub_0209569C
	mov r0, #3
	str r0, [sp]
_02093824:
	add r0, r5, #0
	bl sub_020956B8
_0209382A:
	ldr r0, _02093874 ; =0x000046C0
	mov r1, #1
	str r1, [r5, r0]
	b _02093860
_02093832:
	bl System_GetTouchHeld
	cmp r0, #0
	beq _02093850
	ldr r0, _02093898 ; =0x000046C4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02093850
	add r0, r5, #0
	bl sub_020949F4
	ldr r0, _02093874 ; =0x000046C0
	mov r1, #1
	str r1, [r5, r0]
	b _02093860
_02093850:
	add r0, r5, #0
	bl sub_02094A70
	ldr r0, _02093874 ; =0x000046C0
	mov r1, #0
	str r1, [r5, r0]
	add r0, r0, #4
	str r1, [r5, r0]
_02093860:
	ldrb r1, [r5, #0xe]
	ldrb r0, [r5, #0xd]
	cmp r1, r0
	bne _0209386C
	mov r0, #1
	str r0, [r5, #0x14]
_0209386C:
	ldr r0, [sp]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02093874: .word 0x000046C0
_02093878: .word gSystem
_0209387C: .word 0x000005DD
_02093880: .word 0x000046B8
_02093884: .word 0x000005DC
_02093888: .word 0x000046BC
_0209388C: .word 0x00004680
_02093890: .word 0x000007E4
_02093894: .word 0x000005EB
_02093898: .word 0x000046C4
	thumb_func_end sub_02093630
