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

	thumb_func_start sub_0209515C
sub_0209515C: ; 0x0209515C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r7, #0x66
	mov r6, #0
	add r4, r5, #0
	lsl r7, r7, #2
_02095168:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _02095172
	bl Sprite_Delete
_02095172:
	add r6, r6, #1
	add r4, #0x34
	cmp r6, #0x1e
	blt _02095168
	ldrb r0, [r5, #0xd]
	mov r6, #0
	cmp r0, #0
	ble _0209519A
	ldr r7, _02095220 ; =0x000007E8
	add r4, r5, #0
_02095186:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _02095190
	bl Sprite_Delete
_02095190:
	ldrb r0, [r5, #0xd]
	add r6, r6, #1
	add r4, #0x34
	cmp r6, r0
	blt _02095186
_0209519A:
	mov r6, #0
	cmp r0, #0
	ble _020951BC
	mov r7, #0x8d
	add r4, r6, #0
	lsl r7, r7, #4
_020951A6:
	ldr r0, [r5, r7]
	ldr r0, [r0, r4]
	cmp r0, #0
	beq _020951B2
	bl Sprite_Delete
_020951B2:
	ldrb r0, [r5, #0xd]
	add r6, r6, #1
	add r4, #0xc
	cmp r6, r0
	blt _020951A6
_020951BC:
	ldr r0, _02095224 ; =0x000008B4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _020951C8
	bl Sprite_Delete
_020951C8:
	ldr r0, _02095228 ; =0x000008BC
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _020951D4
	bl Sprite_Delete
_020951D4:
	ldr r0, _0209522C ; =0x000008B8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _020951E0
	bl Sprite_Delete
_020951E0:
	ldr r0, _02095230 ; =0x000008C4
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _020951EC
	bl Sprite_Delete
_020951EC:
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _020951FA
	bl Sprite_Delete
_020951FA:
	ldrb r1, [r5, #0xd]
	mov r0, #3
	mov r4, #0
	sub r0, r0, r1
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	cmp r6, #0
	ble _0209521E
	ldr r7, _02095234 ; =0x000008C8
_0209520C:
	ldr r0, [r5, r7]
	cmp r0, #0
	beq _02095216
	bl Sprite_Delete
_02095216:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r6
	blt _0209520C
_0209521E:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02095220: .word 0x000007E8
_02095224: .word 0x000008B4
_02095228: .word 0x000008BC
_0209522C: .word 0x000008B8
_02095230: .word 0x000008C4
_02095234: .word 0x000008C8
	thumb_func_end sub_0209515C


	thumb_func_start sub_02095238
sub_02095238: ; 0x02095238
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	ldr r0, _02095348 ; =0x000046B8
	mov r5, #0
	ldr r0, [r4, r0]
	bl sub_02095DD8
	add r7, r0, #0
	ldr r0, _02095348 ; =0x000046B8
	ldr r0, [r4, r0]
	bl sub_02095DE8
	add r1, r5, #0
	add r6, r0, #0
	str r1, [sp, #0x14]
	cmp r7, #6
	bhi _0209532C
	add r1, r7, r7
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02095268: ; jump table
	.short _0209532C - _02095268 - 2 ; case 0
	.short _0209531E - _02095268 - 2 ; case 1
	.short _02095286 - _02095268 - 2 ; case 2
	.short _020952B4 - _02095268 - 2 ; case 3
	.short _020952C8 - _02095268 - 2 ; case 4
	.short _02095276 - _02095268 - 2 ; case 5
	.short _02095286 - _02095268 - 2 ; case 6
_02095276:
	mov r0, #5
	lsl r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0x10]
	mov r5, #1
	b _0209532C
_02095286:
	mov r1, #6
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x18
	mul r0, r1
	add r0, #0x14
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	add r0, r6, #0
	mov r1, #6
	bl _s32_div_f
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	mov r0, #0x18
	mul r0, r1
	add r0, #0x28
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	mov r5, #1
	b _0209532C
_020952B4:
	mov r0, #0x35
	lsl r0, r0, #0xe
	str r0, [sp, #0xc]
	add r1, r6, #1
	mov r0, #0x28
	mul r0, r1
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	mov r5, #1
	b _0209532C
_020952C8:
	mov r0, #0x35
	lsl r0, r0, #0xe
	add r1, r6, #1
	str r0, [sp, #0xc]
	mov r0, #0x28
	add r5, r1, #0
	mul r5, r0
	lsl r0, r5, #0xc
	ldr r2, _0209534C ; =0x000046BC
	str r0, [sp, #0x10]
	ldr r0, [r4, r2]
	cmp r0, #0
	beq _0209531A
	add r6, sp, #0xc
	ldmia r6!, {r0, r1}
	add r3, sp, #0
	add r7, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #1
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #4]
	add r0, r2, #0
	sub r2, #0x38
	sub r0, #0x1c
	ldr r2, [r4, r2]
	mov r1, #0x34
	ldr r0, [r4, r0]
	mul r1, r2
	ldr r0, [r0, r1]
	add r1, r7, #0
	bl Sprite_SetMatrix
	ldr r0, _02095350 ; =0x00004694
	mov r1, #0xd4
	str r1, [r4, r0]
	add r0, r0, #4
	str r5, [r4, r0]
_0209531A:
	mov r5, #1
	b _0209532C
_0209531E:
	mov r0, #0xe
	lsl r0, r0, #0x10
	str r0, [sp, #0xc]
	mov r0, #0xb
	lsl r0, r0, #0x10
	str r0, [sp, #0x10]
	mov r5, #1
_0209532C:
	cmp r5, #0
	beq _02095342
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	add r1, sp, #0xc
	bl Sprite_SetMatrix
	add r0, r4, #0
	bl sub_020956B8
_02095342:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02095348: .word 0x000046B8
_0209534C: .word 0x000046BC
_02095350: .word 0x00004694
	thumb_func_end sub_02095238


	thumb_func_start sub_02095354
sub_02095354: ; 0x02095354
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r4, r0, #0
	ldr r0, _020954B8 ; =0x000046B8
	mov r5, #0
	ldr r0, [r4, r0]
	bl sub_02095DD8
	add r6, r0, #0
	ldr r0, _020954B8 ; =0x000046B8
	ldr r0, [r4, r0]
	bl sub_02095DE8
	add r7, r0, #0
	cmp r6, #6
	bhi _0209539A
	add r0, r6, r6
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02095380: ; jump table
	.short _020954B2 - _02095380 - 2 ; case 0
	.short _020954A2 - _02095380 - 2 ; case 1
	.short _0209538E - _02095380 - 2 ; case 2
	.short _02095442 - _02095380 - 2 ; case 3
	.short _020954AC - _02095380 - 2 ; case 4
	.short _020954B2 - _02095380 - 2 ; case 5
	.short _0209538E - _02095380 - 2 ; case 6
_0209538E:
	add r0, r4, #0
	add r1, r7, #0
	bl sub_02094794
	cmp r0, #1
	beq _0209539C
_0209539A:
	b _020954B2
_0209539C:
	add r0, r4, #0
	mov r1, #1
	add r2, r7, #0
	bl sub_020948C4
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	ble _0209543A
	ldr r2, _020954BC ; =0x000046A4
	add r1, r5, #0
	add r6, sp, #0x18
	add r0, r5, #0
_020953B4:
	str r0, [r6]
	str r0, [r6, #4]
	str r0, [r6, #8]
	ldr r3, [r4, r2]
	add r3, r3, r1
	ldr r3, [r3, #4]
	cmp r3, #0
	bne _02095430
	ldr r2, _020954C0 ; =0x00004694
	mov r0, #0xd4
	str r0, [r4, r2]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	add r1, r0, #1
	mov r0, #0x28
	add r3, r1, #0
	mul r3, r0
	add r0, r2, #4
	str r3, [r4, r0]
	ldr r0, [r4, r2]
	add r3, sp, #0xc
	lsl r0, r0, #0xc
	str r0, [sp, #0x18]
	add r0, r2, #4
	ldr r0, [r4, r0]
	add r7, r3, #0
	lsl r0, r0, #0xc
	str r0, [sp, #0x1c]
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	str r0, [r3]
	mov r0, #1
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #0x10]
	add r0, r2, #0
	sub r2, #0x10
	add r0, #0xc
	ldr r2, [r4, r2]
	mov r1, #0x34
	ldr r0, [r4, r0]
	mul r1, r2
	ldr r0, [r0, r1]
	add r1, r7, #0
	bl Sprite_SetMatrix
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	add r1, sp, #0x18
	bl Sprite_SetMatrix
	ldr r0, _020954B8 ; =0x000046B8
	lsl r2, r5, #0x18
	ldr r0, [r4, r0]
	mov r1, #4
	lsr r2, r2, #0x18
	bl sub_02095D40
	b _0209543A
_02095430:
	ldrb r3, [r4, #0xd]
	add r5, r5, #1
	add r1, #8
	cmp r5, r3
	blt _020953B4
_0209543A:
	ldr r0, _020954C4 ; =0x000046BC
	mov r5, #1
	str r5, [r4, r0]
	b _020954B2
_02095442:
	add r0, r4, #0
	add r1, r7, #0
	bl sub_02094860
	cmp r0, #1
	bne _020954B2
	add r0, r4, #0
	mov r1, #2
	add r2, r7, #0
	bl sub_020948C4
	ldr r0, _020954C8 ; =0x000046A0
	ldr r2, [r4, r0]
	sub r0, #0x1c
	ldr r1, [r4, r0]
	mov r0, #0x34
	mul r0, r1
	ldr r0, [r2, r0]
	bl Sprite_GetMatrixPtr
	add r5, r0, #0
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	str r0, [r3]
	mov r0, #1
	ldr r1, [sp, #4]
	lsl r0, r0, #0xe
	sub r0, r1, r0
	str r0, [sp, #4]
	ldr r0, _020954C8 ; =0x000046A0
	ldr r3, [r4, r0]
	sub r0, #0x1c
	ldr r1, [r4, r0]
	mov r0, #0x34
	mul r0, r1
	ldr r0, [r3, r0]
	add r1, r2, #0
	bl Sprite_SetMatrix
	ldr r0, _020954C4 ; =0x000046BC
	mov r5, #1
	str r5, [r4, r0]
	mov r0, #4
	str r0, [r4, #0x14]
	b _020954B2
_020954A2:
	add r0, r4, #0
	bl sub_0209569C
	mov r5, #3
	b _020954B2
_020954AC:
	add r0, r4, #0
	bl sub_02094A70
_020954B2:
	add r0, r5, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_020954B8: .word 0x000046B8
_020954BC: .word 0x000046A4
_020954C0: .word 0x00004694
_020954C4: .word 0x000046BC
_020954C8: .word 0x000046A0
	thumb_func_end sub_02095354


	thumb_func_start sub_020954CC
sub_020954CC: ; 0x020954CC
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _02095538 ; =0x000046B8
	mov r4, #0
	ldr r0, [r5, r0]
	bl sub_02095DD8
	cmp r0, #1
	beq _020954F4
	cmp r0, #4
	bne _020954FE
	ldr r0, _0209553C ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	add r1, r4, #0
	bl sub_02094A90
	b _02095532
_020954F4:
	add r0, r5, #0
	bl sub_0209569C
	mov r4, #3
	b _02095532
_020954FE:
	ldrb r0, [r5, #0x13]
	cmp r0, #0
	beq _02095532
	ldr r0, _02095538 ; =0x000046B8
	mov r1, #1
	ldr r0, [r5, r0]
	add r2, r4, #0
	bl sub_02095D40
	mov r0, #0xe
	lsl r0, r0, #0x10
	str r0, [sp]
	mov r0, #0xb
	lsl r0, r0, #0x10
	str r0, [sp, #4]
	add r0, r4, #0
	str r0, [sp, #8]
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, sp, #0
	bl Sprite_SetMatrix
	ldr r0, _0209553C ; =0x000005DC
	bl PlaySE
_02095532:
	add r0, r4, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_02095538: .word 0x000046B8
_0209553C: .word 0x000005DC
	thumb_func_end sub_020954CC


	thumb_func_start sub_02095540
sub_02095540: ; 0x02095540
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _02095550
	ldrb r0, [r5, #0x10]
	b _02095550
_02095550:
	sub r0, r0, #1
	strb r0, [r5, #0xf]
	ldr r0, _020955E0 ; =0x000008BC
	mov r1, #1
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	add r0, r5, #0
	bl sub_020943EC
	ldr r0, _020955E4 ; =0x000005DC
	bl PlaySE
	ldrb r0, [r5, #0xf]
	cmp r0, #0x12
	ldr r0, _020955E8 ; =0x000046B8
	bne _020955BE
	ldr r0, [r5, r0]
	bl sub_02095DD8
	cmp r0, #2
	bne _020955DC
	ldr r0, _020955E8 ; =0x000046B8
	ldr r0, [r5, r0]
	bl sub_02095DE8
	mov r1, #6
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	ldr r0, _020955E8 ; =0x000046B8
	mov r1, #6
	ldr r0, [r5, r0]
	add r2, r4, #0
	bl sub_02095D40
	mov r0, #0x18
	mul r0, r4
	add r0, #0x14
	lsl r0, r0, #0xc
	str r0, [sp]
	mov r0, #0xa
	lsl r0, r0, #0xe
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, sp, #0
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {r4, r5, pc}
_020955BE:
	ldr r0, [r5, r0]
	bl sub_02095DD8
	cmp r0, #6
	bne _020955DC
	ldr r0, _020955E8 ; =0x000046B8
	ldr r0, [r5, r0]
	bl sub_02095DE8
	add r2, r0, #0
	ldr r0, _020955E8 ; =0x000046B8
	mov r1, #2
	ldr r0, [r5, r0]
	bl sub_02095D40
_020955DC:
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_020955E0: .word 0x000008BC
_020955E4: .word 0x000005DC
_020955E8: .word 0x000046B8
	thumb_func_end sub_02095540


	thumb_func_start sub_020955EC
sub_020955EC: ; 0x020955EC
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldrb r0, [r5, #0xf]
	add r0, r0, #1
	strb r0, [r5, #0xf]
	ldrb r1, [r5, #0xf]
	ldrb r0, [r5, #0x10]
	cmp r1, r0
	bne _02095604
	mov r0, #0
	strb r0, [r5, #0xf]
_02095604:
	ldr r0, _02095690 ; =0x000008B8
	mov r1, #3
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	add r0, r5, #0
	bl sub_020943EC
	ldr r0, _02095694 ; =0x000005DC
	bl PlaySE
	ldrb r0, [r5, #0xf]
	cmp r0, #0x12
	ldr r0, _02095698 ; =0x000046B8
	bne _0209566E
	ldr r0, [r5, r0]
	bl sub_02095DD8
	cmp r0, #2
	bne _0209568C
	ldr r0, _02095698 ; =0x000046B8
	ldr r0, [r5, r0]
	bl sub_02095DE8
	mov r1, #6
	bl _s32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	ldr r0, _02095698 ; =0x000046B8
	mov r1, #6
	ldr r0, [r5, r0]
	add r2, r4, #0
	bl sub_02095D40
	mov r0, #0x18
	mul r0, r4
	add r0, #0x14
	lsl r0, r0, #0xc
	str r0, [sp]
	mov r0, #0xa
	lsl r0, r0, #0xe
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #0x23
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, sp, #0
	bl Sprite_SetMatrix
	add sp, #0xc
	pop {r4, r5, pc}
_0209566E:
	ldr r0, [r5, r0]
	bl sub_02095DD8
	cmp r0, #6
	bne _0209568C
	ldr r0, _02095698 ; =0x000046B8
	ldr r0, [r5, r0]
	bl sub_02095DE8
	add r2, r0, #0
	ldr r0, _02095698 ; =0x000046B8
	mov r1, #2
	ldr r0, [r5, r0]
	bl sub_02095D40
_0209568C:
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
_02095690: .word 0x000008B8
_02095694: .word 0x000005DC
_02095698: .word 0x000046B8
	thumb_func_end sub_020955EC
