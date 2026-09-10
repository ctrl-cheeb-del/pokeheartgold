#include "config.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_12_022378C0.inc"
	.include "global.inc"

	.text
	.public _0226BFD8
	.public ov12_02237D00
	.public ov12_02237ED0
	.public ov12_02237F18
	.public ov12_02238358
	.public ov12_0223843C
	.public ov12_022387AC
	.public ov12_022389B8
	.public ov12_02238A68
	.public ov12_02239664
	.public ov12_02239730
	.public ov12_022397E4
	.public ov12_02239854
	.public ov12_022399D4
	.public ov12_02239C28
	.public ov12_0223A0D4
	.public ov12_0223A260
	.public ov12_0223A3F0
	.public ov12_0223A664
	.public ov12_0226BFDC
	.public ov12_0226BFE0
	.public ov12_0226BFE8
	.public ov12_0226BFF8
	.public ov12_0226C008
	.public ov12_0226C018
	.public ov12_0226C02C
	.public ov12_0226C044
	.public ov12_0226C060
	.public ov12_0226C080
	.public ov12_0226C0A8
	.public ov12_0226C0D0
	.public ov12_0226C0F8
	.public ov12_0226C120
	.public ov12_0226C174
	.public ov12_0226C1C8
	.public ov12_0226C2DC

	.public ov12_02238A30
	.public ov12_02238A64
	.public ov12_022395BC
	.public ov12_02239644
	.public ov12_022396E8
	.public ov12_022396F0
	.public ov12_02239810
	.public ov12_0223998C
	.public ov12_022399BC
	.public ov12_0223A088
	.public ov12_0223A218
	.public ov12_0223A3A8
	.public ov12_0223A5E4
	.public ov12_0223A620
	.public ov12_0223A7A0

	thumb_func_start ov12_02238A68
ov12_02238A68: ; 0x02238A68
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r4, r0, #0
	ldr r0, [r1]
	str r1, [sp, #4]
	str r0, [r4, #0x2c]
	mov r7, #0
	add r6, r4, #0
	add r5, r1, #0
_02238A7A:
	mov r0, #5
	bl PlayerProfile_New
	add r1, r0, #0
	add r0, r5, #0
	str r1, [r6, #0x48]
	add r0, #0xf8
	ldr r0, [r0]
	bl PlayerProfile_Copy
	mov r0, #0x46
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r7, r7, #1
	str r0, [r6, #0x78]
	add r6, r6, #4
	add r5, r5, #4
	cmp r7, #4
	blt _02238A7A
	mov r1, #0x1b
	ldr r0, [sp, #4]
	lsl r1, r1, #4
	ldrh r1, [r0, r1]
	ldr r0, _02238D44 ; =0x00002446
	ldr r3, [sp, #4]
	strh r1, [r4, r0]
	mov r0, #0x1a
	ldr r1, _02238D48 ; =0x00002468
	mov r6, #0
	add r5, r4, #0
	lsl r0, r0, #4
_02238AB8:
	ldr r2, [r3, r0]
	add r6, r6, #1
	str r2, [r5, r1]
	add r3, r3, #4
	add r5, r5, #4
	cmp r6, #4
	blt _02238AB8
	bl GetLCRNGSeed
	ldr r1, _02238D4C ; =0x00002434
	ldr r2, [sp, #4]
	str r0, [r4, r1]
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r3, [r2, r0]
	add r2, r1, #0
	add r2, #0x14
	str r3, [r4, r2]
	ldr r2, [sp, #4]
	ldr r3, [r2, r0]
	add r2, r1, #0
	add r2, #0x18
	str r3, [r4, r2]
	ldr r2, [sp, #4]
	sub r0, #0x10
	ldr r0, [r2, r0]
	sub r1, #0x28
	str r0, [r4, r1]
	mov r0, #5
	bl Save_Bag_New
	str r0, [r4, #0x58]
	mov r1, #0x42
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	ldr r1, [r4, #0x58]
	bl Save_Bag_Copy
	mov r0, #5
	bl Pokedex_New
	str r0, [r4, #0x60]
	mov r1, #0x11
	ldr r0, [sp, #4]
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	ldr r1, [r4, #0x60]
	bl Pokedex_Copy
	mov r1, #0x45
	lsl r1, r1, #2
	ldr r0, [sp, #4]
	add r2, r1, #0
	ldr r0, [r0, r1]
	add r3, r1, #0
	str r0, [r4, #0x64]
	ldr r0, [sp, #4]
	add r2, #0x1c
	ldr r2, [r0, r2]
	add r0, r1, #0
	add r0, #0xa0
	str r2, [r4, r0]
	add r2, r1, #0
	ldr r0, [sp, #4]
	add r2, #0x34
	ldr r2, [r0, r2]
	add r0, r1, #0
	add r0, #0xa4
	str r2, [r4, r0]
	add r2, r1, #0
	ldr r0, [sp, #4]
	sub r2, #8
	ldr r0, [r0, r2]
	add r2, r1, #0
	str r0, [r4, #0x5c]
	ldr r0, [sp, #4]
	add r2, #0xa4
	ldr r2, [r0, r2]
	add r0, r1, #0
	add r0, #0xac
	str r2, [r4, r0]
	add r2, r1, #0
	ldr r0, [sp, #4]
	add r2, #0x14
	ldr r2, [r0, r2]
	add r0, r4, #0
	add r0, #0x98
	str r2, [r0]
	add r2, r1, #0
	add r5, r1, #0
	ldr r0, [sp, #4]
	add r2, #0x4c
	ldr r2, [r0, r2]
	ldr r0, _02238D50 ; =0x00002424
	add r3, #0x20
	str r2, [r4, r0]
	ldr r2, [sp, #4]
	add r5, #0x58
	ldr r3, [r2, r3]
	add r2, r4, #0
	add r2, #0x9c
	str r3, [r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x7c
	ldr r3, [r2, r3]
	add r2, r0, #0
	sub r2, #0x10
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x3c
	ldr r3, [r2, r3]
	add r2, r0, #0
	sub r2, #0x24
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x38
	ldr r3, [r2, r3]
	add r2, r0, #0
	sub r2, #0x20
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x40
	ldr r3, [r2, r3]
	add r2, r0, #0
	sub r2, #0x1c
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x48
	ldr r3, [r2, r3]
	add r2, r0, #0
	sub r2, #0x14
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x80
	ldr r3, [r2, r3]
	add r2, r0, #0
	sub r2, #8
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x50
	ldr r3, [r2, r3]
	add r2, r0, #4
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x54
	ldr r3, [r2, r3]
	add r2, r0, #0
	add r2, #0xc
	str r3, [r4, r2]
	add r2, r0, #0
	add r2, #0x54
	ldr r2, [r4, r2]
	mov r3, #2
	bic r2, r3
	ldr r3, [sp, #4]
	ldr r3, [r3, r5]
	add r5, r1, #0
	lsl r3, r3, #0x1f
	lsr r3, r3, #0x1e
	orr r3, r2
	add r2, r0, #0
	add r2, #0x54
	str r3, [r4, r2]
	add r2, r0, #0
	add r2, #0x54
	ldr r2, [r4, r2]
	mov r3, #8
	bic r2, r3
	ldr r3, [sp, #4]
	add r5, #0xbc
	ldr r3, [r3, r5]
	lsl r3, r3, #0x1f
	lsr r3, r3, #0x1c
	orr r3, r2
	add r2, r0, #0
	add r2, #0x54
	str r3, [r4, r2]
	add r3, r1, #0
	ldr r2, [sp, #4]
	add r3, #0x60
	ldr r2, [r2, r3]
	add r0, #8
	str r2, [r4, r0]
	ldr r0, [sp, #4]
	add r1, #0x30
	ldr r0, [r0, r1]
	mov r1, #0x87
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp, #4]
	sub r1, #0xd8
	ldr r0, [r0, r1]
	cmp r0, #0
	bne _02238C52
	bl GF_AssertFail
_02238C52:
	mov r1, #0x72
	ldr r0, [sp, #4]
	lsl r1, r1, #2
	ldr r1, [r0, r1]
	ldr r0, _02238D54 ; =0x00002488
	ldr r5, [sp, #4]
	str r1, [r4, r0]
	mov r0, #0
	str r0, [sp, #8]
	str r4, [sp, #0x34]
	add r6, r5, #0
	add r7, r4, #0
_02238C6A:
	ldr r0, [sp, #0x34]
	ldr r1, [r5, #0x18]
	add r0, #0xa0
	strh r1, [r0]
	add r3, r6, #0
	add r2, r7, #0
	mov r0, #6
	add r3, #0x28
	add r2, #0xac
	mov ip, r0
_02238C7E:
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r0, ip
	sub r0, r0, #1
	mov ip, r0
	bne _02238C7E
	ldr r0, [r3]
	add r5, r5, #4
	str r0, [r2]
	ldr r0, [sp, #0x34]
	add r6, #0x34
	add r0, r0, #2
	str r0, [sp, #0x34]
	ldr r0, [sp, #8]
	add r7, #0x34
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #4
	blt _02238C6A
	add r0, r4, #0
	bl BattleContext_New
	ldr r7, _02238D58 ; =0x0000248C
	str r0, [r4, #0x30]
	mov r5, #0
	add r6, r4, #0
_02238CB2:
	mov r0, #5
	bl SaveArray_Party_Alloc
	str r0, [r6, #0x68]
	ldr r0, [sp, #4]
	add r6, r6, #4
	add r1, r0, r5
	mov r0, #0x73
	lsl r0, r0, #2
	ldrb r1, [r1, r0]
	add r0, r4, r5
	add r5, r5, #1
	strb r1, [r0, r7]
	cmp r5, #4
	blt _02238CB2
	mov r0, #0
	ldr r6, [sp, #4]
	str r0, [sp, #0xc]
_02238CD6:
	ldr r0, [r6, #4]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _02238D08
_02238CE2:
	ldr r0, [r6, #4]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r7, r0, #0
	bl GetMonGender
	str r0, [sp, #0x44]
	add r0, r7, #0
	mov r1, #0x6f
	add r2, sp, #0x44
	bl SetMonData
	ldr r0, [r6, #4]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _02238CE2
_02238D08:
	ldr r0, [sp, #0xc]
	add r6, r6, #4
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #4
	blt _02238CD6
	ldr r0, [r4, #0x2c]
	mov r1, #4
	tst r1, r0
	bne _02238D1E
	b _022390CE
_02238D1E:
	add r0, r4, #0
	bl sub_02074E5C
	add r0, r4, #0
	bl ov12_0223BFC0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x38]
	ldr r1, [sp, #4]
	add r0, r4, #0
	bl ov12_0223A664
	ldr r1, [r4, #0x2c]
	mov r0, #0x80
	tst r0, r1
	beq _02238E22
	ldr r6, _02238D5C ; =ov12_0226C2DC
	b _02238D60
	.balign 4, 0
_02238D44: .word 0x00002446
_02238D48: .word 0x00002468
_02238D4C: .word 0x00002434
_02238D50: .word 0x00002424
_02238D54: .word 0x00002488
_02238D58: .word 0x0000248C
_02238D5C: .word ov12_0226C2DC
_02238D60:
	mov r5, #0
	add r7, r4, #0
_02238D64:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	str r0, [r7, #0x34]
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #4
	blt _02238D64
	str r5, [r4, #0x44]
	mov r6, #0
	add r5, r4, #0
_02238D86:
	ldr r1, [r5, #0x34]
	add r0, r4, #0
	bl ov12_02260EA4
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, #4
	add r5, r5, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _02238D86
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	ble _02238E18
	add r7, r4, #0
_02238DB2:
	ldr r0, [r7, #0x68]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _02238DFC
_02238DBE:
	ldr r0, [r7, #0x68]
	add r1, r5, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02238DF0
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238DF0
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238DFC
_02238DF0:
	ldr r0, [r7, #0x68]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _02238DBE
_02238DFC:
	str r5, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x10]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #0x10]
	ldr r1, [r4, #0x44]
	add r0, r0, #1
	add r7, r7, #4
	str r0, [sp, #0x10]
	cmp r0, r1
	blt _02238DB2
_02238E18:
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	b _022390C4
_02238E22:
	mov r0, #8
	tst r0, r1
	beq _02238F04
	mov r5, #0
	add r6, r4, #0
_02238E2C:
	add r0, sp, #0x40
	strb r5, [r0]
	ldr r1, [sp, #0x38]
	add r0, r4, #0
	bl ov12_0223BFCC
	lsl r1, r5, #0x10
	add r7, r0, #0
	add r0, r4, #0
	lsr r1, r1, #0x10
	bl ov12_0223BFCC
	ldr r1, _022390DC ; =ov12_0226C008
	lsl r2, r7, #2
	add r1, r1, r2
	ldrb r1, [r0, r1]
	add r0, sp, #0x40
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	str r0, [r6, #0x34]
	add r5, r5, #1
	add r6, r6, #4
	cmp r5, #4
	blt _02238E2C
	str r5, [r4, #0x44]
	mov r6, #0
	add r5, r4, #0
_02238E68:
	ldr r1, [r5, #0x34]
	add r0, r4, #0
	bl ov12_02260EA4
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, #4
	add r5, r5, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _02238E68
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	ble _02238EFA
	add r7, r4, #0
_02238E94:
	ldr r0, [r7, #0x68]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _02238EDE
_02238EA0:
	ldr r0, [r7, #0x68]
	add r1, r5, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02238ED2
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238ED2
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238EDE
_02238ED2:
	ldr r0, [r7, #0x68]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _02238EA0
_02238EDE:
	str r5, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x14]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #0x14]
	ldr r1, [r4, #0x44]
	add r0, r0, #1
	add r7, r7, #4
	str r0, [sp, #0x14]
	cmp r0, r1
	blt _02238E94
_02238EFA:
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	b _022390C4
_02238F04:
	mov r0, #2
	tst r0, r1
	bne _02238F0C
	b _02239018
_02238F0C:
	ldr r0, [sp, #0x38]
	ldr r1, _022390E0 ; =ov12_0226BFE0
	lsl r0, r0, #2
	mov r5, #0
	add r6, r1, r0
	add r7, r4, #0
_02238F18:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	add r1, r0, #0
	add r0, r4, #0
	str r1, [r7, #0x34]
	bl ov12_02260EA4
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #4
	blt _02238F18
	str r5, [r4, #0x44]
	mov r6, #0
	add r5, r4, #0
_02238F42:
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, #4
	add r5, r5, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _02238F42
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	ble _02239016
_02238F64:
	ldr r0, [sp, #0x18]
	mov r1, #1
	and r0, r1
	str r0, [sp, #0x30]
	lsl r0, r0, #2
	add r7, r4, r0
	ldr r0, [r7, #0x68]
	mov r6, #0
	bl Party_GetCount
	cmp r0, #0
	ble _02238FFC
_02238F7C:
	ldr r0, [r7, #0x68]
	add r1, r6, #0
	bl Party_GetMonByIndex
	ldr r1, [sp, #0x18]
	add r5, r0, #0
	cmp r1, #1
	ble _02238FC8
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x30]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022581D4
	cmp r6, r0
	beq _02238FF0
	add r0, r5, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _02238FF0
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238FF0
	add r0, r5, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238FFC
	b _02238FF0
_02238FC8:
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _02238FF0
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238FF0
	add r0, r5, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02238FFC
_02238FF0:
	ldr r0, [r7, #0x68]
	add r6, r6, #1
	bl Party_GetCount
	cmp r6, r0
	blt _02238F7C
_02238FFC:
	str r6, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x18]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #0x18]
	ldr r1, [r4, #0x44]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, r1
	blt _02238F64
_02239016:
	b _022390C4
_02239018:
	ldr r0, [sp, #0x38]
	ldr r1, _022390E4 ; =ov12_0226BFDC
	lsl r0, r0, #1
	mov r5, #0
	add r6, r1, r0
	add r7, r4, #0
_02239024:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	add r1, r0, #0
	add r0, r4, #0
	str r1, [r7, #0x34]
	bl ov12_02260EA4
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #2
	blt _02239024
	mov r0, #0
	str r5, [r4, #0x44]
	str r0, [sp, #0x1c]
	add r7, r4, #0
_02239050:
	ldr r0, [sp, #4]
	ldr r1, [r7, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [r7, #0x68]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _022390A4
_02239066:
	ldr r0, [r7, #0x68]
	add r1, r5, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02239098
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02239098
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022390A4
_02239098:
	ldr r0, [r7, #0x68]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _02239066
_022390A4:
	str r5, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x1c]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #4]
	add r7, r7, #4
	add r0, r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #4
	blt _02239050
_022390C4:
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	b _0223948A
_022390CE:
	mov r1, #0x10
	tst r1, r0
	bne _022390D6
	b _022391EA
_022390D6:
	ldr r6, _022390E8 ; =ov12_0226C2DC
	b _022390EC
	nop
_022390DC: .word ov12_0226C008
_022390E0: .word ov12_0226BFE0
_022390E4: .word ov12_0226BFDC
_022390E8: .word ov12_0226C2DC
_022390EC:
	mov r5, #0
	add r7, r4, #0
_022390F0:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	add r1, r0, #0
	add r0, r4, #0
	str r1, [r7, #0x34]
	bl ov12_02260EA4
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #4
	blt _022390F0
	str r5, [r4, #0x44]
	mov r6, #0
	add r5, r4, #0
_0223911A:
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, #4
	add r5, r5, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _0223911A
	ldr r0, [r4, #0x44]
	mov r7, #0
	cmp r0, #0
	ble _022391DA
_0223913A:
	add r0, r4, #0
	add r1, r7, #0
	mov r5, #0
	bl BattleSystem_GetPartySize
	cmp r0, #0
	ble _022391BE
_02239148:
	add r0, r4, #0
	add r1, r7, #0
	add r2, r5, #0
	bl BattleSystem_GetPartyMon
	add r6, r0, #0
	cmp r7, #2
	bne _02239188
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _022391B0
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022391B0
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _022391B0
	ldr r0, [sp, #0x3c]
	cmp r0, r5
	bne _022391BE
	b _022391B0
_02239188:
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _022391B0
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022391B0
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022391BE
_022391B0:
	add r0, r4, #0
	add r1, r7, #0
	add r5, r5, #1
	bl BattleSystem_GetPartySize
	cmp r5, r0
	blt _02239148
_022391BE:
	str r5, [sp]
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	mov r2, #2
	add r3, r7, #0
	bl ov12_022582B8
	cmp r7, #0
	bne _022391D2
	str r5, [sp, #0x3c]
_022391D2:
	ldr r0, [r4, #0x44]
	add r7, r7, #1
	cmp r7, r0
	blt _0223913A
_022391DA:
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	ldr r0, _022394D8 ; =0x000023FC
	mov r1, #1
	strb r1, [r4, r0]
	b _0223948A
_022391EA:
	mov r1, #8
	tst r1, r0
	beq _022392BA
	ldr r6, _022394DC ; =ov12_0226C2DC
	mov r5, #0
	add r7, r4, #0
_022391F6:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	add r1, r0, #0
	add r0, r4, #0
	str r1, [r7, #0x34]
	bl ov12_02260EA4
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #4
	blt _022391F6
	str r5, [r4, #0x44]
	mov r6, #0
	add r5, r4, #0
_02239220:
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, #4
	add r5, r5, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _02239220
	mov r0, #0
	str r0, [sp, #0x20]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	ble _022392AA
	add r7, r4, #0
_02239244:
	ldr r0, [r7, #0x68]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _0223928E
_02239250:
	ldr r0, [r7, #0x68]
	add r1, r5, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02239282
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02239282
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _0223928E
_02239282:
	ldr r0, [r7, #0x68]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _02239250
_0223928E:
	str r5, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x20]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #0x20]
	ldr r1, [r4, #0x44]
	add r0, r0, #1
	add r7, r7, #4
	str r0, [sp, #0x20]
	cmp r0, r1
	blt _02239244
_022392AA:
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	ldr r0, _022394D8 ; =0x000023FC
	mov r1, #1
	strb r1, [r4, r0]
	b _0223948A
_022392BA:
	mov r1, #2
	tst r0, r1
	bne _022392C2
	b _022393D6
_022392C2:
	ldr r6, _022394DC ; =ov12_0226C2DC
	mov r5, #0
	add r7, r4, #0
_022392C8:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	add r1, r0, #0
	add r0, r4, #0
	str r1, [r7, #0x34]
	bl ov12_02260EA4
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #4
	blt _022392C8
	str r5, [r4, #0x44]
	mov r6, #0
	add r5, r4, #0
_022392F2:
	ldr r0, [sp, #4]
	ldr r1, [r5, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [sp, #4]
	add r6, r6, #1
	add r0, r0, #4
	add r5, r5, #4
	str r0, [sp, #4]
	cmp r6, #4
	blt _022392F2
	mov r0, #0
	str r0, [sp, #0x24]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	ble _022393C6
_02239314:
	ldr r0, [sp, #0x24]
	mov r1, #1
	and r0, r1
	str r0, [sp, #0x2c]
	lsl r0, r0, #2
	add r7, r4, r0
	ldr r0, [r7, #0x68]
	mov r6, #0
	bl Party_GetCount
	cmp r0, #0
	ble _022393AC
_0223932C:
	ldr r0, [r7, #0x68]
	add r1, r6, #0
	bl Party_GetMonByIndex
	ldr r1, [sp, #0x24]
	add r5, r0, #0
	cmp r1, #1
	ble _02239378
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x2c]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022581D4
	cmp r6, r0
	beq _022393A0
	add r0, r5, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _022393A0
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022393A0
	add r0, r5, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022393AC
	b _022393A0
_02239378:
	mov r1, #5
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _022393A0
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022393A0
	add r0, r5, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _022393AC
_022393A0:
	ldr r0, [r7, #0x68]
	add r6, r6, #1
	bl Party_GetCount
	cmp r6, r0
	blt _0223932C
_022393AC:
	str r6, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x24]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #0x24]
	ldr r1, [r4, #0x44]
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, r1
	blt _02239314
_022393C6:
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	ldr r0, _022394D8 ; =0x000023FC
	mov r1, #1
	strb r1, [r4, r0]
	b _0223948A
_022393D6:
	ldr r6, _022394E0 ; =_0226BFD8
	mov r5, #0
	add r7, r4, #0
_022393DC:
	add r0, sp, #0x40
	strb r5, [r0]
	ldrb r1, [r6]
	strb r1, [r0, #1]
	add r0, r4, #0
	add r1, sp, #0x40
	bl ov12_02258D74
	add r1, r0, #0
	add r0, r4, #0
	str r1, [r7, #0x34]
	bl ov12_02260EA4
	add r5, r5, #1
	add r6, r6, #1
	add r7, r7, #4
	cmp r5, #2
	blt _022393DC
	mov r0, #0
	str r5, [r4, #0x44]
	str r0, [sp, #0x28]
	add r7, r4, #0
_02239408:
	ldr r0, [sp, #4]
	ldr r1, [r7, #0x68]
	ldr r0, [r0, #4]
	bl Party_Copy
	ldr r0, [r7, #0x68]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _0223945C
_0223941E:
	ldr r0, [r7, #0x68]
	add r1, r5, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _02239450
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _02239450
	add r0, r6, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _0223945C
_02239450:
	ldr r0, [r7, #0x68]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _0223941E
_0223945C:
	str r5, [sp]
	ldr r1, [r4, #0x30]
	ldr r3, [sp, #0x28]
	add r0, r4, #0
	mov r2, #2
	bl ov12_022582B8
	ldr r0, [sp, #4]
	add r7, r7, #4
	add r0, r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #4
	blt _02239408
	ldr r1, [r4, #0x30]
	add r0, r4, #0
	bl ov12_02256F28
	ldr r0, _022394D8 ; =0x000023FC
	mov r1, #1
	strb r1, [r4, r0]
_0223948A:
	mov r0, #2
	ldr r1, [r4, #0x2c]
	lsl r0, r0, #8
	tst r0, r1
	beq _022394A6
	ldr r0, [r4, #0x6c]
	mov r1, #0
	bl Party_GetMonByIndex
	add r2, r4, #0
	mov r1, #0x90
	add r2, #0xf4
	bl GetMonData
_022394A6:
	ldr r1, [r4, #0x2c]
	mov r0, #1
	tst r0, r1
	beq _0223954E
	add r0, r4, #0
	add r0, #0xe1
	ldrb r0, [r0]
	bl ov12_022395BC
	cmp r0, #1
	beq _022394C8
	ldr r0, _022394E4 ; =0x00000149
	ldrb r0, [r4, r0]
	bl ov12_022395BC
	cmp r0, #1
	bne _0223954E
_022394C8:
	ldr r0, [r4, #0x68]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _02239516
	ldr r7, _022394E8 ; =0x00002408
	b _022394EC
	.balign 4, 0
_022394D8: .word 0x000023FC
_022394DC: .word ov12_0226C2DC
_022394E0: .word _0226BFD8
_022394E4: .word 0x00000149
_022394E8: .word 0x00002408
_022394EC:
	ldr r0, [r4, #0x68]
	add r1, r5, #0
	bl Party_GetMonByIndex
	ldr r2, [r4, r7]
	add r6, r0, #0
	lsl r2, r2, #0x10
	mov r1, #3
	lsr r2, r2, #0x10
	bl MonApplyFriendshipMod
	add r0, r6, #0
	mov r1, #2
	bl ApplyMonMoodModifier
	ldr r0, [r4, #0x68]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _022394EC
_02239516:
	ldr r0, [r4, #0x70]
	mov r5, #0
	bl Party_GetCount
	cmp r0, #0
	ble _0223954E
	ldr r7, _022395B0 ; =0x00002408
_02239524:
	ldr r0, [r4, #0x70]
	add r1, r5, #0
	bl Party_GetMonByIndex
	ldr r2, [r4, r7]
	add r6, r0, #0
	lsl r2, r2, #0x10
	mov r1, #3
	lsr r2, r2, #0x10
	bl MonApplyFriendshipMod
	add r0, r6, #0
	mov r1, #2
	bl ApplyMonMoodModifier
	ldr r0, [r4, #0x70]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _02239524
_0223954E:
	ldr r0, _022395B4 ; =0x0000247C
	mov r7, #0
	sub r6, r0, #4
	str r7, [r4, r0]
	add r1, r6, #0
	ldr r2, [r4, r1]
	mov r1, #4
	bic r2, r1
	sub r0, r0, #4
	str r2, [r4, r0]
	ldr r0, [r4, #0x44]
	add r5, r7, #0
	cmp r0, #0
	ble _02239594
_0223956A:
	add r0, r4, #0
	add r1, r5, #0
	bl BattleSystem_GetPlayerProfile
	bl PlayerProfile_GetVersion
	cmp r0, #GAME_VERSION
	beq _0223957C
	mov r7, #1
_0223957C:
	cmp r0, #7
	beq _0223958C
	cmp r0, #8
	beq _0223958C
	ldr r1, [r4, r6]
	mov r0, #4
	orr r0, r1
	str r0, [r4, r6]
_0223958C:
	ldr r0, [r4, #0x44]
	add r5, r5, #1
	cmp r5, r0
	blt _0223956A
_02239594:
	ldr r0, _022395B8 ; =0x000023FC
	ldrb r1, [r4, r0]
	cmp r1, #0
	beq _022395A4
	add r0, #0x80
	add sp, #0x48
	str r7, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_022395A4:
	mov r1, #0
	add r0, #0x80
	str r1, [r4, r0]
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	nop
_022395B0: .word 0x00002408
_022395B4: .word 0x0000247C
_022395B8: .word 0x000023FC
	thumb_func_end ov12_02238A68
